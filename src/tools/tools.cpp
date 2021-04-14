#include "tools.h"

//namespace tools{
    const duration elapsed_time(time_point finish, time_point start){
        return finish - start;
    }

    time_point get_current_time(){
        time_point start;
        start = std::chrono::steady_clock::now();
        return start;
    }

    long long  get_file_size(char *path){
        struct stat statbuf;
        long long result;
        if(stat(path, &statbuf) == -1){
            perror("Error in file size func");
        }
        return statbuf.st_size;
    }

/*
    template<typename Fn>
    void time_wraper(Fn foo,std::string path,
                     std::string path_to_new_file){

        long long f1 = get_file_size((char *)path.c_str());
        time_point start = get_current_time();

        foo();

        time_point finish = get_current_time();
        duration result = elapsed_time(finish, start);
        long long f2 = get_file_size((char *)path.c_str());

        std::cout << "Elapsed time " << result.count() << " sec" <<'\n'
                  <<"New file size status: ";

        if(f1 == f2){
            std::cout <<"NORMAL\n";
        }else if (f1 > f2){
            std::cout <<"OVERFLOW\n";
        }else{
            std::cout <<"NOT ENOUGH\n";
        }


    }
*/
//}
