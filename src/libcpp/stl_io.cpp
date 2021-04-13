#include "stl_io.h"

void FileIO::foo(){
    std::cout << "omar";
}

void FileIO::io_by_rdbuf(string path, string path_to_new_file){

    ifstream file_from;
    ofstream file_to;
    file_from.open(path);
    file_to.open(path_to_new_file);

    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }
    cout <<"here\n";

    file_to << file_from.rdbuf();

    file_from.close();
    file_to.close();
}

void FileIO::io_by_std_getline(string path, string path_to_new_file){

    ifstream file_from;
    ofstream file_to;
    file_from.open(path);
    file_to.open(path_to_new_file);

    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }
    cout <<"here\n";
    string line;
    while(getline(file_from,line)){
        file_to << line;
        file_to << '\n';
    }

    file_from.close();
    file_to.close();
}

void FileIO::io_by_ifstream_readsome(string path, string path_to_new_file,
                                    size_t bufsize){

    ifstream file_from;
    ofstream file_to;
    file_from.open(path);
    file_to.open(path_to_new_file);

    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }
    cout <<"here\n";

    char buffer[bufsize];
    int count;
    while((count = file_from.readsome(buffer, bufsize))){
        file_to.write(buffer,count);
    }

    file_from.close();
    file_to.close();
}
