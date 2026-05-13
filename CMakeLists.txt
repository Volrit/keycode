cmake_minimum_required(VERSION 3.16)

project(keycode VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC_SEARCH_PATHS ui/)

set(PROJECT_SOURCES
    src/main.cpp
    src/ui/mainwindow.cpp
    src/ui/mainwindow.h
    src/ui/mainwindow.ui
    src/runner/coderunner.cpp
    src/runner/coderunner.h
    src/highlighting/cpphighlighter.cpp
    src/highlighting/cpphighlighter.h
)

qt_add_executable(keycode
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_include_directories(keycode PRIVATE src/ui/ src/runner/ src/highlighting/)

target_link_libraries(keycode PRIVATE Qt6::Widgets)

set_target_properties(keycode PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS keycode
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(keycode)