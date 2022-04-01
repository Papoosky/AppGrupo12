#include <string.h>
#include "header.h"

void agregarLibro(Libro *libros) {
    int nuevo_row = registryCount + 1;
    char titulos[255];
    char autores[255];
    char anios[255];
    char sed[255];
    char edif[255];
    char p[55];
    char estante_s[255];
    char estante_n[255];


    printf("\nPor favor, ingrese el nombre del libro que desea aniadir: \n");
    scanf("%[^\n]s", &titulos);
    strcpy(libros[nuevo_row].titulo,titulos);

    printf("\nPor favor, ingrese el autor del libro que desea aniadir: \n");
    scanf("%[^\n]s", &autores);
    strcpy(libros[nuevo_row].autor,autores);

    printf("\nPor favor, ingrese el anio de publicacion del libro que desea aniadir: \n");
    scanf("%s", &anios);
    strcpy(libros[nuevo_row].anio,anios);

    printf("\nPor favor, indique en que sede desea guardarlo: \n");
    scanf("%s", &sed);
    strcpy(libros[nuevo_row].sede,sed);

    printf("\nPor favor, indique en que edificio desea guardarlo: \n");
    scanf("%s", &edif);
    strcpy(libros[nuevo_row].edificio,edif);

    printf("\nPor favor, indique en que piso desea guardarlo: \n");
    scanf("%s", &p);
    strcpy(libros[nuevo_row].piso,p);

    printf("\nPor favor, indique en quÃ© seccion guardarlo\n");
    scanf("%s",&estante_s);
    strcpy(libros[nuevo_row].estante_seccion,estante_s);

    printf("\nPor favor, indique en que numero de estante guardarlo\n");
    scanf("%s",&estante_n);
    strcpy(libros[nuevo_row].estante_numero,estante_n);

    printf("\n\n Libro guardaro exitosamente!\n\n");
}