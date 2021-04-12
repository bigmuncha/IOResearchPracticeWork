#include <iostream>
#include <random>
#include <fstream>
#include <stdio.h>

enum {file_size = 512 * 1024 * 1024};

int main(int args,char **argv){

    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());

    std::uniform_int_distribution<> dist(65,90);


    FILE * file_512mb = fopen("./file_512mb.txt", "w");
    FILE * file_1gb = fopen("./file_1gb.txt", "w");
    for(int i =0; i < file_size; i++){
        char sym = (char) dist(mt);
        fputc(sym,file_512mb);
        fputc(sym,file_1gb);
        fputc(sym, file_1gb);
    }
    std::cout << "Compelte";


    return 0;
}
