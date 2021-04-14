#include "libcpp/stl_io.h"

#include "tools/tools.h"
extern "C"{

#include "libc/universal_unix_io.h"
#include "libc/standart_library_io.h"
}

#include <functional>
#include <map>
#include <vector>
#include <iomanip>

template<typename Fn>
void time_wraper(Fn foo,std::string path,
                 std::string path_to_new_file){

    long long f1 = get_file_size((char *)path.c_str());
    time_point start = get_current_time();

    foo();

    time_point finish = get_current_time();
    duration result = elapsed_time(finish, start);
    long long f2 = get_file_size((char *)path.c_str());
    string whitespace = "           ";
    std::cout <<whitespace << "Elapsed time " << result.count() << " sec" <<'\n'
              <<whitespace<<"New file size status: ";

    if(f1 == f2){
        std::cout <<"NORMAL\n"
                  << whitespace<<"Read/Write average speed: " << f1 /result.count() << '\n';

    }else if (f1 > f2){
        std::cout <<" >>>>> >>>>> OVERFLOW <<<<< <<<<<\n";
    }else{
        std::cout <<" >>>>> >>>>> NOT ENOUGH <<<<< <<<<<\n";
    }


}


int main(int argc, char **argv){

    std::vector<int> vec_bufsize = {64, 128, 256 , 512, 1024, 4096, 8192,16384, 32768,65536};
    std::vector<std::string> vec_filename = {"CMakeCache.txt", "video_50mb.mp4"};
    std::vector<std::string> vec_new_filename = {"new.txt", "new_video.mp4"};
    //printf("%ld\n",get_file_size((char *)"CMakeCache.txt"));
    std::map<std::string, long long> file_map;
    for(auto i : vec_filename){
        file_map[i] = get_file_size((char *) i.c_str());
    }

    for(auto i: vec_bufsize){
        std::cout << "Universal unix io for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb txt. Bufsize = " << i<<'\n';
        std::string file_from = vec_filename[0];
        std::string file_to =std::to_string(i) +  vec_new_filename[0];
        auto omar = bind(universal_unix_io,(char *) file_from.c_str(), (char *)file_to.c_str(), i);
        time_wraper(omar, file_from, file_to);
    }
    std::cout <<endl <<endl;

    for(auto i: vec_bufsize){
        std::cout << "Universal unix io for " <<
            file_map[vec_filename[1]]/(1024 * 1024.0) <<
            "mb bin. Bufsize = " << i<<'\n';
        std::string file_from = vec_filename[1];
        std::string file_to =std::to_string(i) +  vec_new_filename[1];
        auto omar = bind(universal_unix_io,(char *) file_from.c_str(), (char *)file_to.c_str(), i);
        time_wraper(omar, file_from, file_to);
    }
    std::cout <<endl <<endl;

    {
        std::cout << "C lang standart library io getc putc for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb txt.\n";
        std::string file_from = vec_filename[0];
        std::string file_to =std::to_string(1) +  vec_new_filename[0];
        auto omar = bind(standart_library_io_binary_getc_putc,(char *) file_from.c_str(), (char *)file_to.c_str());
        time_wraper(omar, file_from, file_to);

    }
    std::cout <<endl;

    {
        std::cout << "C lang standart library io getc putc for "<<
            file_map[vec_filename[1]]/(1024 * 1024.0) <<
            "mb bin.\n";
        std::string file_from = vec_filename[1];
        std::string file_to =std::to_string(1) +  vec_new_filename[1];
        auto omar = bind(standart_library_io_binary_getc_putc,(char *) file_from.c_str(), (char *)file_to.c_str());
        time_wraper(omar, file_from, file_to);
    }

    std::cout <<endl <<endl;

    for(auto i: vec_bufsize){
        std::cout << "C lang standart library io fread fwrite for " <<
            file_map[vec_filename[1]]/(1024 * 1024.0) <<
            "mb bin. Bufsize = " << i<<'\n';
        std::string file_from = vec_filename[1];
        std::string file_to =std::to_string(i) +  vec_new_filename[1];
        auto omar = bind(standart_library_io_binary_fread_fwrite,(char *) file_from.c_str(), (char *)file_to.c_str(), i);
        time_wraper(omar, file_from, file_to);
    }
    std::cout <<endl <<endl;

    for(auto i: vec_bufsize){
        std::cout << "C lang standart library fgets fputs io for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb txt. Bufsize = " << i<<'\n';
        std::string file_from = vec_filename[0];
        std::string file_to =std::to_string(i) +  vec_new_filename[0];
        auto omar = bind(standart_library_io_fgets_fputs,(char *) file_from.c_str(), (char *)file_to.c_str(), i);
        time_wraper(omar, file_from, file_to);
    }

    std::cout <<endl <<endl;

    {
        std::cout << "C lang standart library fscanf fprintf io for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb txt\n";
        std::string file_from = vec_filename[0];
        std::string file_to =std::to_string(1) +  vec_new_filename[0];
        auto omar = bind(standart_library_io_fscanf_fprintf,(char *) file_from.c_str(), (char *)file_to.c_str());
        time_wraper(omar, file_from, file_to);
    }

    std::cout <<endl <<endl;

    {
        std::cout << "CPP stl io by rdbuf for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb txt\n";
        std::string file_from = vec_filename[0];
        std::string file_to =std::to_string(1) +  vec_new_filename[0];
        auto omar = bind(CppFileIO::io_by_rdbuf,(char *) file_from.c_str(), (char *)file_to.c_str());
        time_wraper(omar, file_from, file_to);
    }

        std::cout <<endl <<endl;

    {
        std::cout << "CPP stl io by rdbuf for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb bin\n";
        std::string file_from = vec_filename[1];
        std::string file_to =std::to_string(1) +  vec_new_filename[1];
        auto omar = bind(CppFileIO::io_binary_by_rdbuf,(char *) file_from.c_str(), (char *)file_to.c_str());
        time_wraper(omar, file_from, file_to);
    }

        std::cout <<endl <<endl;

    {
        std::cout << "CPP stl io by std getline for "<<
            file_map[vec_filename[0]]/(1024 * 1024.0) <<
            "mb txt\n";
        std::string file_from = vec_filename[0];
        std::string file_to =std::to_string(1) +  vec_new_filename[0];
        auto omar = bind(CppFileIO::io_by_std_getline,(char *) file_from.c_str(), (char *)file_to.c_str());
        time_wraper(omar, file_from, file_to);
    }




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
