#!/bin/bash

if [ "$1" == "-h" ]; then
  echo "Ce script compile le code source"
  exit 2
fi

cd build
make
