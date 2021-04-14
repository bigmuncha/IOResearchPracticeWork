#ifndef __TOOLS_H_
#define __TOOLS_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <chrono>
#include <thread>
#include <string>
#include <iostream>

//namespace tools{
using namespace std;
    typedef std::chrono::steady_clock::time_point time_point;
    typedef std::chrono::duration<double> duration;

    time_point get_current_time();
    const duration elapsed_time(time_point,time_point);
    long long get_file_size(char *);

    template<typename Fn>
    void time_wraper(Fn foo,std::string path,
                     std::string path_to_new_file);
//}
#endif // __TOOLS_H_
