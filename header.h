#include <stdio.h>
struct Libros{
    char *titulo;
    char *autor;
    char *anio;
    char *estante_numero;
    char *estante_seccion;
    char *piso;
    char *edificio;
    char *sede;


};
typedef struct Libros Libro;
extern int registryCount;

Libro * getLibros(FILE *fp);
void menu(Libro libros[], int registryCount, char *archivo_csv);
void agregarLibro(char *archivo_csv);
void opciones(int *cerrar, int *salir);