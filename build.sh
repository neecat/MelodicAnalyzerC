#!/bin/bash
echo Building Melodic Analyzer...
echo Target: Linux
gcc linux.c -o melodicanalyzer
echo Target: win32
i686-w64-mingw32-gcc win32.c -o melodic.exe
echo Target: win64
x86_64-w64-mingw32-gcc win32.c -o melodic64.exe
echo Done!

