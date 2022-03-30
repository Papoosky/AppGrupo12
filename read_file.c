#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "header.h"

#define MAXCHAR 10000

int registryCount = 0;

Libro* getLibros(FILE *fp) {
    //genero un array dinamico de personas
    Libro *libros = (Libro*) malloc(5000*sizeof(Libro));;

    char row[MAXCHAR];
    char *token;
    int cont = 0;
    //saco la primer linea
    fgets(row, MAXCHAR, fp);
    while (!feof(fp)){
        //obtiene la linea siguiente
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        //print id first
        Libro *libro = (Libro *) malloc(sizeof(Libro));;
    
  /*      int id = atoi(token);

        persona->id = id;
*/
        //obtengo el siguiente campo
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->titulo = (char*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        strcpy(libro->titulo, token);

        //obtengo el siguiente campo
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->autor = (char*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        strcpy(libro->autor, token);

        //obtengo el siguiente campo
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->anio = (int*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        int anio = atoi(token);
        libro->anio = &anio;
        //strcpy(libro->anio, token);

        //obtengo el siguiente campo
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->estante_numero = (char*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        strcpy(libro->estante_numero, token);
        
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->estante_seccion = (char*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        strcpy(libro->estante_seccion, token);
        
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->piso = (int*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        int piso = atoi(token);
        libro->piso = &piso;
        
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->edificio = (char*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        strcpy(libro->edificio, token);
        
        token = strtok(NULL, ",");
        //inicializo el string en la estructura acorde al tamaño que venga del archivo
        libro->sede = (char*)malloc( strlen(token) * sizeof(char));
        //finalmente lo copio en el campo de persona
        strcpy(libro->sede, token);
        
        libros[cont] = *libro;
        cont++;
    }
    //guardo la cantidad de registros que lei
    registryCount = cont;
    return libros;
}
