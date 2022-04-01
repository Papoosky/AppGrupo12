#include "header.h"
#include "string.h"

void agregarLibro(Libro libros[]) {
    int nuevo_row = registryCount + 1;
    char titulos[255];
    char autors[255];
    char anios[255];
    char estante_n[255];
    char estante_s[255];
    char pizo[255];
    char edif[255];
    char sed[255];
    Libro *nuevos_libros;


    printf("\nPor favor, ingrese el nombre del libro que desea aniadir: \n");
    scanf("%s", titulos);
    strcpy(nuevos_libros[nuevo_row].titulo,titulos);


    printf("\nPor favor, ingrese el autor del libro que desea aniadir: \n");
    scanf("%s", autors);
    strcpy(nuevos_libros[nuevo_row].autor,autors);

    printf("\nPor favor, ingrese el anio de publicacion del libro que desea aniadir: \n");
    scanf("%s", anios);
    strcpy(nuevos_libros[nuevo_row].anio,anios);

    printf("\nPor favor, indique en que numero de estante guardarlo\n");
    scanf("%s",estante_n);
    strcpy(nuevos_libros[nuevo_row].estante_numero,estante_n);

    printf("\nPor favor, indique en que sección guardarlo\n");
    scanf("%s",estante_s);
    strcpy(nuevos_libros[nuevo_row].estante_seccion,estante_s);

    printf("\nPor favor, indique en que piso del edificio desea guardarlo: \n");
    scanf("%s", pizo);
    strcpy(nuevos_libros[nuevo_row].piso,pizo);

    printf("\nPor favor, indique en que edificio desea guardarlo: \n");
    scanf("%s", edif);
    strcpy(nuevos_libros[nuevo_row].edificio,edif);

    printf("\nPor favor, indique en que sede desea guardarlo: \n");
    scanf("%s", sed);
    strcpy(nuevos_libros[nuevo_row].sede,sed);




    for(int i = 0; i <= nuevo_row - 1; i++){
        nuevos_libros[i].titulo = libros[i].titulo;
        nuevos_libros[i].autor = libros[i].autor;
        nuevos_libros[i].anio = libros[i].anio;
        nuevos_libros[i].estante_seccion = libros[i].estante_seccion;
        nuevos_libros[i].estante_numero = libros[i].estante_numero;
        nuevos_libros[i].piso = libros[i].piso;
        nuevos_libros[i].edificio = libros[i].edificio;
    }

    printf("\n\n Libro guardaro exitosamente!\n\n");
}