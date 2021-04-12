#include "libc/universal_unix_io.h"
#include "libc/standart_library_io.h"

int main(int argc, char **argv){
    universal_unix_io("CMakeCache.txt", "./new.c", 8192);
    standart_library_io_getc_putc("CMakeCache.txt", "./new1.c");
    standart_library_io_fgetc_fputc("CMakeCache.txt", "./new2.c");
    standart_library_io_fgets_fputs("CMakeCache.txt", "./new3.c", 8192);
    standart_library_io_fscanf_fprintf("CMakeCache.txt", "./new4.c");
    standart_library_io_fscanf_fprintf_string("CMakeCache.txt", "./new5.c",8192);
    return 0;
}
