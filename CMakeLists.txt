cmake_minimum_required(VERSION 3.5)

project(Homework2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    executable/main.cpp
    executable/mainwindow.cpp
    executable/profileaccount.cpp
    executable/registartionform.cpp
    executable/mainwindow.ui
    executable/profileaccount.ui
    executable/registartionform.ui
    headers/profileaccount.h
    headers/registartionform.h
    headers/mainwindow.h
    executable/database.txt
    AccessParametres/User.h
    AccessParametres/User.cpp
    AccessParametres/Room.h
    AccessParametres/Room.cpp
    AccessParametres/AccessType.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Homework2
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Homework2 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Homework2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Homework2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
