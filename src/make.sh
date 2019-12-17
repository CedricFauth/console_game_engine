#!/bin/bash
rm main;
gcc -std=c11 -D_XOPEN_SOURCE=700 -Wall -Werror main.c engine.c input.c view.c -o main;
./main;
exit;