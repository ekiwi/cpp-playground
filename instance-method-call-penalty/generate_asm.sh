#!/usr/bin/env bash

FLAGS="-S -std=c++11 -O0"

arm-none-eabi-g++ $FLAGS -DSTATIC main.cpp
mv main.s static.s

arm-none-eabi-g++ $FLAGS -DINSTANCE main.cpp
mv main.s instance.s

arm-none-eabi-g++ $FLAGS -DINSTANCE_PTR main.cpp
mv main.s instance_ptr.s

arm-none-eabi-g++ $FLAGS -DINSTANCE_REF main.cpp
mv main.s instance_ref.s
