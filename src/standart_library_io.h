#ifndef __STANDART_LIBRARY_IO_H_
#define __STANDART_LIBRARY_IO_H_
#include <stdio.h>
#include <stdarg.h>

void standart_library_io_getc_putc(char *,char *);
void standart_library_io_binary_getc_putc(char *,char *);
void standart_library_io_binary_fgetc_fputc(char *, char *);
void standart_library_io_fgets_fputs(char *, char *,size_t);
void standart_library_io_binary_fread_fwrite(char *,char *,int);


#endif // __STANDART_LIBRARY_IO_H_
