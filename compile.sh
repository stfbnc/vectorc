#!/bin/bash

# $1 - C program
# $2 - library path
# $3 - executable name

gcc "$1" -L"$2" -lvectorc -o "$3"
