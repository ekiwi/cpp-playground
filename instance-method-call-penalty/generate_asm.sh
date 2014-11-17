#!/usr/bin/env bash

arm-none-eabi-g++ -S -std=c++11 -DSTATIC main.cpp
mv main.s static.s

arm-none-eabi-g++ -S -std=c++11 -DINSTANCE main.cpp
mv main.s instance.s

arm-none-eabi-g++ -S -std=c++11 -DINSTANCE_PTR main.cpp
mv main.s instance_ptr.s
