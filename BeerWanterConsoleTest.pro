include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)

include(../BeerWanter/BeerWanterConsole.pri)
include(../BeerWanter/BeerWanterConsoleTest.pri)

SOURCES += main_test.cpp

# C++17
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

# High warning levels
QMAKE_CXXFLAGS += -Wall -Wextra -Werror

# Debug and release mode
CONFIG += debug_and_release
CONFIG(release, debug|release) {

  DEFINES += NDEBUG

}

CONFIG(debug, debug|release) {
  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov
}

# Boost.Test
LIBS += -lboost_unit_test_framework


# Qt
# Go ahead and use Qt.Core: it is about as platform-independent as
# the STL and Boost
QT += core
# Go ahead and use Qt.Gui: it is about as platform-independent as
# the STL and Boost. It is needed for QImage
QT += gui
# Don't define widgets: it would defy the purpose of this console
# application to work non-GUI
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable



