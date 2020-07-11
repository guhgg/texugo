#!/bin/bash

# Installing Nlohmann Json lib
git clone https://github.com/nlohmann/json.git
mkdir json/build && cd json/build
cmake ..
make -j2
sudo make install
cd ../..

# Installing Spdlog lib
git clone https://github.com/gabime/spdlog.git
mkdir spdlog/build && cd spdlog/build
cmake ..
make -j2
sudo make install
cd ../..

# Installing Prometheus lib
git clone https://github.com/jupp0r/prometheus-cpp.git
mkdir prometheus-cpp/build && cd prometheus-cpp
git submodule init
git submodule update
cd build
cmake .. -DBUILD_SHARED_LIBS=OFF
make -j2
sudo make install
cd ../..