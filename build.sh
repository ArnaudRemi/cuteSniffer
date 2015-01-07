#!/bin/bash

cd cuteSniffer
qmake-qt5
make
mv cuteSniffer usr/bin/
cd ..
dpkg-deb --build cuteSniffer
