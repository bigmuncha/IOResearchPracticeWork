#include <iostream>
#include <random>
#include <fstream>
#include <stdio.h>

enum {file_size = 512 * 1024 * 1024};

int main(int args,char **argv){

    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());

    std::uniform_int_distribution<> dist(65,90);
    std::uniform_int_distribution<> dist1(-128,127);


    FILE * file_512mb = fopen("./file_512mb.txt", "w");
    FILE * file_1gb = fopen("./file_1gb.txt", "w");


    FILE * file_bin_512mb = fopen("./file_bin_512mb", "wb");
    FILE * file_bin_1gb = fopen("./file_bin_1gb", "wb");

    for(int i =0; i < file_size; i++){
        char sym = (char) dist(mt);
	int ii = dist1(mt);
        fputc(sym,file_512mb);
        fputc(sym,file_1gb);
        fputc(sym, file_1gb);
	
        fputc(ii,file_bin_512mb);
        fputc(ii,file_bin_1gb);
        fputc(ii, file_bin_1gb);
    }
    std::cout << "Compelte";


    return 0;
}
