#include "header.h"
void agregarLibro( char *archivo_csv) {
    char info_libro[1024];


    printf("Ingresa la información del libro a agregar:\n");
    printf("El formato admitido es: "
      "\"titulo\",\"autor\",anio,estante_numero,\"estante_seccion\",piso,"
      "\"edificio\",\"sede\"\n");
    fflush(stdout);
    scanf(" %[^\n]", info_libro);

    FILE *fputs;
    fputs = fopen( archivo_csv, "a");
    fprintf(fputs, "\n%s", info_libro);
    fclose(fputs);


    printf("\n Libro guardado exitosamente!\n\n");
}