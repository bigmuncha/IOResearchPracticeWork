#include "universal_unix_io.h"

void universal_unix_io(char *path,char *path_to_new_file, size_t bufsize){
    int fd1;
    int fd2;
    size_t count;
    char buffer[bufsize];

    fd1 = open(path,O_RDONLY,
               S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
               S_IROTH | S_IWOTH);
    if(fd1 == -1){
        perror("Error with open input file");
    }

    fd2 = open(path_to_new_file,O_WRONLY | O_CREAT,
               S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
               S_IROTH | S_IWOTH);
    if(fd2 == -1){
        perror("Error with open output file");
    }

    while((count = read(fd1,buffer,bufsize)) > 0){
        write(fd2, buffer, count);
    }


    close(fd1);
    close(fd2);

}
