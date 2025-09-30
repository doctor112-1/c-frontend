#!/bin/bash

./preprocess.sh
emcc main.c -o page.js -sDEFAULT_LIBRARY_FUNCS_TO_INCLUDE='$UTF8ToString' -sEXPORTED_RUNTIME_METHODS=ccall,cwrap -O3
rm site/vars.h
mv site/vars.h.bak site/vars.h
