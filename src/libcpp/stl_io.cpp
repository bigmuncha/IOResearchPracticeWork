#include "stl_io.h"



void CppFileIO::io_by_rdbuf(string path, string path_to_new_file){

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


    file_to << file_from.rdbuf();

    file_from.close();
    file_to.close();
}

void CppFileIO::io_binary_by_rdbuf(string path,
                                string path_to_new_file){

    ifstream file_from;
    ofstream file_to;
    file_from.open(path, ios::binary);
    file_to.open(path_to_new_file, ios::binary);



    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }


    file_to << file_from.rdbuf();

    file_from.close();
    file_to.close();
}


void CppFileIO::io_by_std_getline(string path,
                               string path_to_new_file){

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

    string line;
    while(getline(file_from,line)){
        file_to << line;
        file_to << '\n';
    }

    file_from.close();
    file_to.close();
}

void CppFileIO::io_by_ifstream_read(string path,
                               string path_to_new_file){

    ifstream file_from;
    ofstream file_to;
    file_from.open(path, ios::binary);
    file_to.open(path_to_new_file, ios::binary);

    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }

    file_from.seekg(0,file_from.end);
    long long len = file_from.tellg();
    file_from.seekg(0,file_from.beg);

    char * buffer = new char[len];

    file_from.read(buffer, len);
    file_to.write(buffer, len);

    file_from.close();
    file_to.close();
    delete [] buffer;
}


void CppFileIO::io_by_ifstream_readsome(string path,
                                     string path_to_new_file,
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


    char buffer[bufsize];
    int count;
    while((count = file_from.readsome(buffer, bufsize))){
        file_to.write(buffer,count);
    }

    file_from.close();
    file_to.close();
}

void CppFileIO::io_binary_by_ifstream_readsome(string path,
                                            string path_to_new_file,
                                            size_t bufsize){

    ifstream file_from;
    ofstream file_to;
    file_from.open(path, ios::binary);
    file_to.open(path_to_new_file, ios::binary);

    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }


    char buffer[bufsize];
    int count;
    while((count = file_from.readsome(buffer, bufsize))){
        file_to.write(buffer,count);
    }

    file_from.close();
    file_to.close();
}


void CppFileIO::io_by_copy_buf_iterator(string path,
                                     string path_to_new_file){
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


    copy(istreambuf_iterator<char>(file_from),
         istreambuf_iterator<char>(),
         ostreambuf_iterator<char>(file_to));

    file_from.close();
    file_to.close();
}

void CppFileIO::io_binary_by_copy_streambuf_iterator(string path,
                                            string path_to_new_file){
    ifstream file_from;
    ofstream file_to;
    file_from.open(path, ios::binary);
    file_to.open(path_to_new_file, ios::binary);

    if(!file_from.is_open()){
       cerr << "Error in open input file";
       //return;
    }
    if(!file_to.is_open()){
       cerr << "Error in open output file";
       //return;
    }


    copy(istreambuf_iterator<char>(file_from),
         istreambuf_iterator<char>(),
         ostreambuf_iterator<char>(file_to));

    file_from.close();
    file_to.close();
}
