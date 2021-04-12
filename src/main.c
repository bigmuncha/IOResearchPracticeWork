#include "universal_unix_io.h"


int main(int argc, char **argv){
    universal_unix_io("../universal_unix_io.c", "./new.c", 8192);
    return 0;
}
