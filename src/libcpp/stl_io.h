#ifndef __STL_IO_H_
#define __STL_IO_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileIO{
    public:
        static void foo();
        static void io_by_rdbuf(string,string);
        static void io_by_std_getline(string, string);
        static void io_by_ifstream_readsome(string, string,size_t);
};


#endif // __STL_IO_H_
