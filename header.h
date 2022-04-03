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
void EditarLibro(Libro *libros, int registryCount);
void EditarSeccion(Libro *libros, int registryCount);
void EditarSede(Libro *libros, int registryCount);
void EditarPiso(Libro *libros, int registryCount);
void Guardar(Libro Datos[], int j, char *archivo_csv);
void QuitarLibro(Libro Datos[], int j);