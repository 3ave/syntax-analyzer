#!/bin/bash

if [ -d "build/release" ]; then
  rm -rf "build/release"
fi

mkdir -p build/release
make release
cp ./syntax_analyzer ./build/tmp
make clean
mv ./build/tmp ./build/release/syntax_analyzer