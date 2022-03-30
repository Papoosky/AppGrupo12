#include <stdio.h>
struct Libros{
	char *titulo;
	char *autor;
	int *anio;
	char *estante_numero;
   	char *estante_seccion;
    int *piso;
    char *edificio;
    char *sede;
    
    
};
typedef struct Libros Libro;
extern int registryCount;

Libro * getLibros(FILE *fp);