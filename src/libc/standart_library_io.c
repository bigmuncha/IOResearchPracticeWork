#include "standart_library_io.h"
#include "../tools/tools.h"

void standart_library_io_getc_putc(char *path,char *path_to_new_file){
    FILE *file_from;
    FILE *file_to;
    int c;

    if((file_from = fopen(path, "r")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "w")) == NULL){
        perror("Error with open output file");
    }

    while((c = getc(file_from)) != EOF){
        putc(c, file_to);
    }
    fclose(file_from);
    fclose(file_to);
}


void standart_library_io_binary_getc_putc(char *path,char *path_to_new_file){
    FILE *file_from;
    FILE *file_to;
    int c;

    if((file_from = fopen(path, "rb")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "wb")) == NULL){
        perror("Error with open output file");
    }

    while((c = getc(file_from)) != EOF){
        putc(c, file_to);
    }
    fclose(file_from);
    fclose(file_to);
}


void standart_library_io_fgetc_fputc(char *path,char *path_to_new_file){
    FILE *file_from;
    FILE *file_to;
    int c;

    if((file_from = fopen(path, "r")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "w")) == NULL){
        perror("Error with open output file");
    }

    while((c = fgetc(file_from)) != EOF){
        fputc(c, file_to);
    }
    fclose(file_from);
    fclose(file_to);
}

void standart_library_io_binary_fgetc_fputc(char *path,char *path_to_new_file){
    FILE *file_from;
    FILE *file_to;
    int c;

    if((file_from = fopen(path, "rb")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "wb")) == NULL){
        perror("Error with open output file");
    }

    while((c = fgetc(file_from)) != EOF){
        fputc(c, file_to);
    }
    fclose(file_from);
    fclose(file_to);
}

/*cannot be bynary*/
void standart_library_io_fgets_fputs(char *path, char* path_to_new_file,
                                     size_t bufsize){
    FILE *file_from;
    FILE *file_to;
    char str[bufsize];

    if((file_from = fopen(path, "r")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "w")) == NULL){
        perror("Error with open output file");
    }

    while(fgets(str,bufsize,file_from) !=NULL){
        fputs(str, file_to);
    }

    fclose(file_from);
    fclose(file_to);
}


void standart_library_io_binary_fread_fwrite(char *path,
                                             char* path_to_new_file,
                                             size_t bufsize){
    FILE *file_from;
    FILE *file_to;
    int str[bufsize];
    int count;

    if((file_from = fopen(path, "rb")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "wb")) == NULL){
        perror("Error with open output file");
    }

    int sum =0;

    while((count = fread(str,1,bufsize,file_from)) > 0){
        printf("count ");
        sum++;
        fwrite(str, 1, count, file_to);
    }
    printf("%d",sum);
    fclose(file_from);
    fclose(file_to);
}


void standart_library_io_fscanf_fprintf(char *path, char *path_to_new_file){
    FILE *file_from;
    FILE *file_to;


    if((file_from = fopen(path, "r")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "w")) == NULL){
        perror("Error with open output file");
    }


    /*you can change this on char array, apply scanf for string and printing string in file*/
    char c;
    while(fscanf(file_from, "%c",&c) != EOF){
        fprintf(file_to, "%c",c);
    }

    fclose(file_from);
    fclose(file_to);
}


/*dont work*/
void standart_library_io_fscanf_fprintf_string(char *path,
                                               char *path_to_new_file){

    FILE *file_from;
    FILE *file_to;


    if((file_from = fopen(path, "r")) == NULL){
        perror("Error with open input file");
    }
    if((file_to = fopen(path_to_new_file, "w")) == NULL){
        perror("Error with open output file");
    }

    long size = get_file_size(path);

    char *buffer = malloc(size);
    while(fscanf(file_from, "%[^\n]",buffer) != EOF){
        fprintf(file_to, "%s\n",buffer);
    }

    fclose(file_from);
    fclose(file_to);
}
