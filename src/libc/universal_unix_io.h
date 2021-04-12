#ifndef __UNIVERSAL_UNIX_IO_H_
#define __UNIVERSAL_UNIX_IO_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void universal_unix_io(char *,char *,size_t);


#endif // __UNIVERSAL_UNIX_IO_H_
