cmake_minimum_required(VERSION 3.16)

    project(PasswordManager VERSION 0.1 LANGUAGES CXX)

# Знайти Qt (підтримка як Qt6, так і Qt5)
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql UiTools)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql UiTools)

    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Додаємо основні файли проекту
    set(PROJECT_SOURCES
            main.cpp
                dbmanager.cpp
                    dbmanager.h
                        windows.h windows.cpp
                            homescreen.h homescreen.cpp homescreen.ui
                                welcomewindow.h welcomewindow.cpp welcomewindow.ui
                                    addpassworddialog.h addpassworddialog.cpp addpassworddialog.ui
                                        simplecrypt.h simplecrypt.cpp
                                            resources.qrc
        )

# Визначаємо, як збирати проект
    if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_executable(PasswordManager
                          MANUAL_FINALIZATION
                              ${PROJECT_SOURCES}
                      )
    else()
    add_executable(PasswordManager ${PROJECT_SOURCES})
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

# Якщо використовується OpenSSL, знайдемо та підключимо
    find_package(OpenSSL)
    if(OPENSSL_FOUND)
    target_link_libraries(PasswordManager PRIVATE OpenSSL::SSL OpenSSL::Crypto)
    message(STATUS "OpenSSL знайдено: ${OPENSSL_VERSION}")
    else()
    message(WARNING "OpenSSL не знайдено, можливі проблеми зі шифруванням!")
    endif()

# Додаємо підтримку MOC, UIC, RCC
set_target_properties(PasswordManager PROPERTIES
                          AUTOMOC ON
                              AUTOUIC ON
                                  AUTORCC ON
                      )

# Встановлення для Windows
    if(WIN32)
    set_target_properties(PasswordManager PROPERTIES WIN32_EXECUTABLE ON)
    endif()

# Додаємо встановлення (опціонально)
install(TARGETS PasswordManager
            BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
