#!/bin/bash

emcc main.c -o page.js -sDEFAULT_LIBRARY_FUNCS_TO_INCLUDE='$UTF8ToString'
