#!/usr/bin/env bash
mkdir temp
c++  -o creator file_creator/create_two_files.cpp
echo "Подождите пока создаются (может занять пару минут)"
./creator
mv file_512mb.txt temp/
mv file_1gb.txt temp/
mv file_bin_512mb temp/
mv file_bin_1gb temp/
cd temp
cmake ../src/
make
./main file_512mb.txt file_bin_512mb
./main file_1gb.txt file_bin_1gb
