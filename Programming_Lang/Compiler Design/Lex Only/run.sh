#!/bin/bash
read -p "FileName: " file
flex $file
gcc lex.yy.c
./a.out
