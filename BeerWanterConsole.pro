include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

include(../BeerWanter/BeerWanterConsole.pri)

SOURCES += main.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable