#ifndef __STL_IO_H_
#define __STL_IO_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class CppFileIO{
    public:

        static long get_size_file(ifstream);

        static void io_by_rdbuf(string,string);
        static void io_binary_by_rdbuf(string,string);

        static void io_by_std_getline(string, string);

        static void io_by_ifstream_read(string, string);

        static void io_by_ifstream_readsome(string, string,size_t);
        static void io_binary_by_ifstream_readsome(string, string,size_t);

        static void io_by_copy_buf_iterator(string, string);
        static void io_binary_by_copy_streambuf_iterator(string, string);
};


#endif // __STL_IO_H_
