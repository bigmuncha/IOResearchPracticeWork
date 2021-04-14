#ifndef __STANDART_LIBRARY_IO_H_
#define __STANDART_LIBRARY_IO_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
/*read write only one char*/
void standart_library_io_getc_putc(char *,char *);
/*same, but for binary*/
void standart_library_io_binary_getc_putc(char *,char *);

/*same as getc_putc, but this is always be a functions(getc_putc can be macros)*/
void standart_library_io_fgetc_fputc(char *, char *);
/*same, but for binary files*/
void standart_library_io_binary_fgetc_fputc(char *, char *);

/*work only with txt files*/
void standart_library_io_fgets_fputs(char *, char *,size_t);

/*binary io, cannot apply to txt files*/
void standart_library_io_binary_fread_fwrite(char *,char *,size_t);

/*formating io read each char and write its*/
void standart_library_io_fscanf_fprintf(char *, char*);

/*same, but read string
 *dont work */

//void standart_library_io_fscanf_fprintf_string(char *, char*);


#endif // __STANDART_LIBRARY_IO_H_
