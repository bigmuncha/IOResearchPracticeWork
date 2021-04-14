#include "libcpp/stl_io.h"

#include "tools/tools.h"
extern "C"{

#include "libc/universal_unix_io.h"
#include "libc/standart_library_io.h"
}

#include <functional>

#include <vector>


template<typename Fn>
void time_wraper(Fn foo,std::string path,
                 std::string path_to_new_file){

    long f1 = get_file_size((char *)path.c_str());
    time_point start = get_current_time();

    foo();

    time_point finish = get_current_time();
    duration result = elapsed_time(finish, start);
    long f2 = get_file_size((char *)path.c_str());

    std::cout << "Elapsed time " << result.count() << " sec" <<'\n'
              <<"New file size status: ";

    if(f1 == f2){
        std::cout <<"NORMAL\n"
                  <<"Read/Write speed: " << f1 /result.count() << '\n';

    }else if (f1 > f2){
        std::cout <<"OVERFLOW\n";
    }else{
        std::cout <<"NOT ENOUGH\n";
    }


}


int main(int argc, char **argv){

    std::vector<int> vec_bufsize = {64, 128, 256 , 512, 1024, 4096, 8192,16384, 32768,65536};
    printf("%ld\n",get_file_size((char *)"CMakeCache.txt"));
    auto omar =
        bind(universal_unix_io,
             (char *)"CMakeCache.txt",(char *) "./new.c",
             256);

    time_wraper(omar, "CMakeCache.txt", "make");

    /*
    universal_unix_io((char *)"video_50mb.mp4",(char *) "new_video.mp4", 256);
    cout << "complete\n";
    standart_library_io_getc_putc((char *)"CMakeCache.txt",(char *) "./new1.c");
    standart_library_io_binary_getc_putc((char *)"video_50mb.mp4",(char *) "new_video1.mp4");
    cout << "complete\n";
    standart_library_io_fgetc_fputc((char *)"CMakeCache.txt",(char *) "./new2.c");
    standart_library_io_binary_fgetc_fputc((char *)"video_50mb.mp4", (char *)"new_video2.mp4");
    cout << "complete\n";
    standart_library_io_binary_fread_fwrite((char *)"video_50mb.mp4", (char *)"new_video3.mp4", 256);
    cout << "complete\n";
    standart_library_io_fgets_fputs((char *)"CMakeCache.txt", (char *)"./new3.c", 256);

//    standart_library_io_binary_fgets_fputs((char *)"video_50mb.mp4", (char *)"new_video4.mp4", 256);

    cout << "complete\n";
    standart_library_io_fscanf_fprintf((char *)"CMakeCache.txt",(char *) "./new4.c");
    cout << "complete\n";
*/
/*
    CppFileIO::io_by_rdbuf("CMakeCache.txt", "./new5.c");
    CppFileIO::io_by_std_getline("CMakeCache.txt", "./new6.c");
    CppFileIO::io_by_ifstream_readsome("CMakeCache.txt", "./new7.c",256);
    CppFileIO::io_binary_by_copy_streambuf_iterator("CMakeCache.txt",
                                                 "./new8.c");
    CppFileIO::io_by_ifstream_read("CMakeCache.txt", "./new9.c");
    cout <<"omer";
    */
    return 0;
}
