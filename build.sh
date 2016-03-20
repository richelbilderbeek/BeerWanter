#!/bin/bash
qmake BeerWanterConsole.pro
make
qmake BeerWanterDesktop.pro
make
qmake BeerWanterConsoleTest.pro
make
./BeerWanterConsoleTest
