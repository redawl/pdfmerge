#!/bin/bash

set -e
# install podofo dependencies
sudo apt-get install -y libfontconfig1-dev libfreetype-dev libxml2-dev libssl-dev libjpeg-dev libpng-dev libtiff-dev libidn11-dev

## Download podofo
#wget "https://github.com/podofo/podofo/archive/refs/tags/0.10.4.zip" --output-document /tmp/podofo.zip && unzip /tmp/podofo.zip -d /tmp/podofo

## Install podofo
#pushd "/tmp/podofo/podofo-0.10.4"
#mkdir build && cd build
## cmake -DPODOFO_BUILD_STATIC=TRUE ..
#cmake ..
#make
#sudo make install
