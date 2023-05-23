#!/bin/bash

if [ -d "build/debug" ]; then
  rm -rf "build/debug"
fi

mkdir -p build/debug
make debug
cp ./syntax_analyzer ./build/tmp
make clean
mv ./build/tmp ./build/debug/syntax_analyzer