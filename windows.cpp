#include "windows.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <QIODevice>
#include <QFile>
#include<QBuffer>
#include <qsqlquery.h>


Windows::Windows(MainWindow *mw)
    : mw(mw) {}

bool Windows::createEncryptedDatabase(const QString &dbPath, const QString &key)
{
    qDebug() << Q_FUNC_INFO;
    QFile file(dbPath);

    if (!file.open(QIODevice::ReadWrite)) {
        qWarning() << "Не вдалося відкрити БД для шифрування!";
        return false;
    }

    QByteArray keyBytes = key.toUtf8().left(32).rightJustified(32, 0);
    QByteArray iv(16, 0);
    RAND_bytes(reinterpret_cast<unsigned char*>(iv.data()), iv.size());

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        qWarning() << "Помилка ініціалізації OpenSSL!";
        return false;
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                           reinterpret_cast<const unsigned char*>(keyBytes.data()),
                           reinterpret_cast<const unsigned char*>(iv.data())) != 1) {
        qWarning() << "Помилка ініціалізації AES!";
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    QByteArray buffer = file.readAll();
    file.close();

    QByteArray encrypted;
    encrypted.resize(buffer.size() + EVP_MAX_BLOCK_LENGTH);
    int len;

    if (EVP_EncryptUpdate(ctx,
                          reinterpret_cast<unsigned char*>(encrypted.data()),
                          &len,
                          reinterpret_cast<const unsigned char*>(buffer.data()),
                          buffer.size()) != 1) {
        qWarning() << "Помилка шифрування!";
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    int finalLen;
    if (EVP_EncryptFinal_ex(ctx,
                            reinterpret_cast<unsigned char*>(encrypted.data() + len),
                            &finalLen) != 1) {
        qWarning() << "Помилка завершального шифрування!";
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    encrypted.resize(len + finalLen);
    EVP_CIPHER_CTX_free(ctx);

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Не вдалося відкрити БД для запису!";
        return false;
    }

    file.write(iv);       // Записуємо IV
    file.write(encrypted);
    file.close();
    qDebug() << "File encryption executed";
    return true;
}

QByteArray Windows::encryptDatabase(const QString &filePath, const QByteArray &data, const QString &key)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "Encryption file path: " << filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        windows->handleError("Can't open database for encryption", 1);
    }

    QByteArray keyBytes = key.toUtf8().left(32).leftJustified(32, 0);
    QByteArray iv(16, 0);
    RAND_bytes(reinterpret_cast<unsigned char*>(iv.data()), iv.size());

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        windows->handleError("OpenSSL initialization error",1);
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                           reinterpret_cast<const unsigned char*>(keyBytes.data()),
                           reinterpret_cast<const unsigned char*>(iv.data())) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        windows->handleError("AES initialization error", 1);
    }

    QByteArray buffer = file.readAll();
    file.close();

    QByteArray encrypted;
    encrypted.resize(buffer.size() + EVP_MAX_BLOCK_LENGTH);
    int len;

    if (EVP_EncryptUpdate(ctx,
                          reinterpret_cast<unsigned char*>(encrypted.data()),
                          &len,
                          reinterpret_cast<const unsigned char*>(buffer.data()),
                          buffer.size()) != 1) {
        qWarning() << "Encryption error";
        EVP_CIPHER_CTX_free(ctx);
        windows->handleError("Encryption error", 1);
    }

    int finalLen;
    if (EVP_EncryptFinal_ex(ctx,
                            reinterpret_cast<unsigned char*>(encrypted.data() + len),
                            &finalLen) != 1) {
        qWarning() << "Error in final encryption";
        EVP_CIPHER_CTX_free(ctx);
        windows->handleError("Error in final encryption", 1);
    }

    encrypted.resize(len + finalLen);
    EVP_CIPHER_CTX_free(ctx);

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Can't open database for writing";
        windows->handleError("Cand't open database for writing",0);
    }

    file.write(iv);       // Записуємо IV
    file.write(encrypted);
    file.close();
    exit(EXIT_FAILURE);
}

bool Windows::decryptDatabase(const QString &key, QSqlDatabase &db) {
    qDebug() << Q_FUNC_INFO;
    QString filePath = windows->databasePath;
    qDebug() << "Decryption file path: " << filePath;
    // Відкриваємо файл бази
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        windows->handleError("Can't open database for reading", 1);
        return false;
    }

    QByteArray encryptedData = file.readAll();
    file.close();

    if (encryptedData.size() < 16) {
        windows->handleError("File is too small or damaged", 1);
        return false;
    }

    QByteArray keyBytes = key.toUtf8().left(32).leftJustified(32, 0);
    QByteArray iv = encryptedData.left(16);  // Перші 16 байт - це IV
    QByteArray cipherText = encryptedData.mid(16);

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        windows->handleError("OpenSSL initialization error", 1);
        return false;
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                           reinterpret_cast<const unsigned char*>(keyBytes.data()),
                           reinterpret_cast<const unsigned char*>(iv.data())) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        windows->handleError("AES initialization error", 1);
        return false;
    }

    std::vector<char> decryptedData(cipherText.size() + EVP_MAX_BLOCK_LENGTH);
    int len;

    if (EVP_DecryptUpdate(ctx,
                          reinterpret_cast<unsigned char*>(decryptedData.data()),
                          &len,
                          reinterpret_cast<const unsigned char*>(cipherText.data()),
                          cipherText.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        windows->handleError("Decryption error", 1);
        return false;
    }

    int finalLen;
    if (EVP_DecryptFinal_ex(ctx,
                            reinterpret_cast<unsigned char*>(decryptedData.data() + len),
                            &finalLen) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        windows->handleError("Final decryption error", 1);
        return false;
    }

    decryptedData.resize(len + finalLen);
    EVP_CIPHER_CTX_free(ctx);

    // Зберігаємо розшифровані дані у пам’ять (QBuffer)
    QBuffer *buffer = new QBuffer;
    buffer->setData(QByteArray::fromRawData(decryptedData.data(), decryptedData.size()));
    buffer->open(QIODevice::ReadOnly);

    // Підключаємо SQLite до пам'яті
    db = QSqlDatabase::addDatabase("QSQLITE", "memory_db");
    db.setDatabaseName(":memory:");

    if (!db.open()) {
        windows->handleError("Can't open SQLite in memory", 1);
        return false;
    }

    // Завантажуємо базу в пам’ять
    QSqlQuery query(db);
    query.exec("ATTACH DATABASE ':memory:' AS temp_db;");
    query.exec("CREATE TABLE IF NOT EXISTS temp_db.my_table AS SELECT * FROM main.my_table;");

    qDebug() << "Database decrypted and loaded into memory.";
    return true;
}
