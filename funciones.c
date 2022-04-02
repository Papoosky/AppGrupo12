#include "header.h"
void opciones(int *cerrar, int *salir) {
    int subopcion;
    printf("\n[1]   Volver al menu principal.\n");
    printf("[2]   Salir del sistema.\n");
    printf("Opcion: ");
    scanf("%d", &subopcion);
    printf("\n");
    if (subopcion == 1) {

        printf("Volviendo al menu principal...\n");
        *salir = 1;
    }
    if (subopcion == 2) {

        printf("Saliendo del sistema...\n");
        *salir = 1;
        *cerrar = 1;
    }
}


void agregarLibro( char *archivo_csv) {
    char info_libro[1024];


    printf("Ingresa la informacion del libro a agregar:\n");
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