#include "libcpp/stl_io.h"

extern "C"{

#include "tools/tools.h"
#include "libc/universal_unix_io.h"
#include "libc/standart_library_io.h"

}

int main(int argc, char **argv){
    

    printf("%ld\n", get_file_size((char *)"CMakeCache.txt"));
/*
    universal_unix_io("CMakeCache.txt", "./new.c", 8192);
    universal_unix_io("video_50mb.mp4", "new_video.mp4", 8192);

    standart_library_io_getc_putc("CMakeCache.txt", "./new1.c");
    standart_library_io_binary_getc_putc("video_50mb.mp4", "new_video1.mp4");

    standart_library_io_fgetc_fputc("CMakeCache.txt", "./new2.c");
    standart_library_io_binary_fgetc_fputc("video_50mb.mp4", "new_video2.mp4");

    standart_library_io_binary_fread_fwrite("video_50mb.mp4", "new_video3.mp4", 8192);

    standart_library_io_fgets_fputs("CMakeCache.txt", "./new3.c", 8192);

    standart_library_io_fscanf_fprintf("CMakeCache.txt", "./new4.c");

    //standart_library_io_fscanf_fprintf_string("CMakeCache.txt", "./new5.c");
*/

    FileIO::foo();
    FileIO::io_by_rdbuf("CMakeCache.txt", "./new5.c");
    FileIO::io_by_std_getline("CMakeCache.txt", "./new6.c");
    FileIO::io_by_ifstream_readsome("CMakeCache.txt", "./new7.c",256);
    cout <<"omer";
    return 0;
}
