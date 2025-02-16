cmake_minimum_required(VERSION 3.16)

project(PasswordManager VERSION 0.1 LANGUAGES CXX)

# Знайти Qt (підтримка Qt6 і Qt5)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql UiTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql UiTools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основні файли проекту
set(PROJECT_SOURCES
    main.cpp
    dbmanager.cpp dbmanager.h
    windows.cpp windows.h
    homescreen.cpp homescreen.h homescreen.ui
    welcomewindow.cpp welcomewindow.h welcomewindow.ui
    addpassworddialog.cpp addpassworddialog.h addpassworddialog.ui

    register.ui register.h register.cpp
    login.ui login.h login.cpp
    mainwindow.ui mainwindow.h mainwindow.cpp
)


# Додаємо виконуваний файл
if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_executable(PasswordManager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(PasswordManager ${PROJECT_SOURCES} ${PasswordManager_resources})
endif()

# Визначаємо ідентифікатор для macOS
if(QT_VERSION_MAJOR LESS 6)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PasswordManager)
endif()

# Підключаємо бібліотеки Qt
target_link_libraries(PasswordManager PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::UiTools
)

# Додаємо підтримку MOC, UIC, RCC
set_target_properties(PasswordManager PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

# Вкажи Qt-шну версію OpenSSL
set(OPENSSL_ROOT_DIR "C:/Qt/Tools/OpenSSLv3/Win_x64")
set(OPENSSL_LIBRARIES "${OPENSSL_ROOT_DIR}/lib")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")

# Якщо використовується OpenSSL, знайдемо та підключимо
find_package(OpenSSL)
if(OPENSSL_FOUND)
    target_link_libraries(PasswordManager PRIVATE OpenSSL::SSL OpenSSL::Crypto)
    message(STATUS "found openssl: ${OPENSSL_VERSION}")
else()
    message(WARNING "Openssl is not found!")
endif()

# Встановлення для Windows
if(WIN32)
    set_target_properties(PasswordManager PROPERTIES WIN32_EXECUTABLE ON)
endif()

# Додаємо встановлення
install(TARGETS PasswordManager
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
