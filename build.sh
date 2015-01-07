#!/bin/bash

cd cuteSniffer
qmake-qt5
make
mv cuteSniffer usr/bin/
cd ..
sudo dpkg-deb --build cuteSniffer
