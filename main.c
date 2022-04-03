#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "header.h"
#define MAXCHAR 1000



FILE * openingFile(char *filename){
    FILE *fp;
    FILE *fp1;
    fp = fopen(filename,"r");
    fp1 = fopen(filename,"r");

    return fp;
}

int main(int argc, char *argv[] ){
    char* archivo_csv;
    archivo_csv = argv[1];
    FILE *fp = openingFile(argv[1]);

    Libro *libros;
    libros = getLibros(fp);
    menu(libros, registryCount, archivo_csv);

    return 0;
}


