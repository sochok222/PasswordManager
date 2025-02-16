#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include<QString>
#include<QDir>
#include<QMessageBox>
#include<QDebug>
#include<QSqlDatabase>
#include<qsqlquery>
#include"dbmanager.h"

class DirectoryManager
{
public:
    DirectoryManager();
    static void createDirIfNotExists(const QString& path);
    static void createFileIfNotExists(const QString& path);
    static void checkIfFileExists(const QString& path);
    ~DirectoryManager();
};

#endif // DIRECTORYMANAGER_H
