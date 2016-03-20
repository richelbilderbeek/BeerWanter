include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralConsoleTest.pri)

include(../BeerWanter/BeerWanterConsole.pri)
include(../BeerWanter/BeerWanterConsoleTest.pri)

SOURCES += main_test.cpp

LIBS += -lboost_unit_test_framework

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable