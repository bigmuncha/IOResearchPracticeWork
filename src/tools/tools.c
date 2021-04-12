#include "tools.h"

long get_file_size(char *path){
    struct stat statbuf;
    long result;
    if(stat(path, &statbuf) == -1){
        perror("Error in file size func");
    }
    return statbuf.st_size;
}
