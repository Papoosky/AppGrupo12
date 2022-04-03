#include "header.h"
#include<string.h>
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
void EditarLibro(Libro *libros, int registryCount) {
    char book[200];
    char edit[200];
    int opcion3, found = 0, b = 1, a;

    printf("Ingresa el nombre del libro que deseas editar: \n");
    fflush(stdout);
    scanf(" %[^\n]", book);

    for (int i = 0; i <= registryCount; i++) {
        if (strcmp(book, libros[i].titulo) == 0) {
            a = i;
            found = 1;
        }
    }

    if (found == 1) {
        printf("Que informacion desea editar. \n");
        printf("1.     Autor. \n");
        printf("2.     Titulo. \n");
        printf("3.     Anio. \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion3);

        switch (opcion3) {
            case 1: {
                printf("Ingrese el autor:\n");
                fflush(stdout);
                scanf(" %[^\n]", edit);

                printf("\nAutor Antiguo: %s\n", libros[a].autor);
                strcpy(libros[a].autor, edit);
                printf("Autor Nuevo: %s\n\n", libros[a].autor);
            } break;
            case 2: {
                printf("Ingrese titulo.\n");
                fflush(stdout);
                scanf(" %[^\n]", edit);
                printf("Old: %s\n", libros[a].titulo);
                strcpy(libros[a].titulo, edit);
                printf("New: %s\n", libros[a].titulo);
            } break;
            case 3: {
                printf("Ingrese anio.\n");
                fflush(stdout);
                scanf(" %[^\n]", edit);
                printf("Old: %s\n", libros[a].anio);
                strcpy(libros[a].anio, edit);
                printf("New: %s\n", libros[a].anio);
            } break;
            default: {
                printf("Opcion invalida.\n");
            } break;
        }
    } else {
        printf("No se encuentra el libro.\n");
    }
}
void EditarSeccion(Libro *libros, int registryCount) {
    char edit[200];
    char book[200];
    int found = 0, a;

    printf("Ingresa el nombre del libro que deseas editar: \n");
    fflush(stdout);
    scanf(" %[^\n]", book);
    for (int i = 0; i <= registryCount; i++) {
        if (strcmp(book, libros[i].titulo) == 0) {
            a = i;
            found = 1;
        }
    }
    if (found == 1) {
        printf("\nSeccion actual: %s\n", libros[a].estante_seccion);
        printf("\nIngrese nueva seccion:\n");
        fflush(stdout);
        scanf(" %[^\n]", edit);
        strcpy(libros[a].estante_seccion, edit);
        printf("Nueva seccion: %s\n", libros[a].estante_seccion);
    }
}
void EditarSede(Libro *libros, int registryCount) {
    char edit[200];
    char book[200];
    int found = 0, a, i;

    printf("Ingresa el nombre del libro que deseas editar: \n");
    fflush(stdout);
    scanf(" %[^\n]", book);
    for (i = 0; i <= registryCount; i++) {
        if (strcmp(book, libros[i].titulo) == 0) {
            a = i;
            found = 1;
        }
    }
    if (found == 1) {
        printf("\nSede actual: %s\n", libros[a].sede);
        printf("Ingrese nueva sede:\n");
        fflush(stdout);
        scanf(" %[^\n]", edit);
        strcpy(libros[a].sede, edit);
        printf("Nueva sede: %s\n", libros[a].sede);
    }
}
void EditarPiso(Libro *libros, int registryCount) {
    char edit[200];
    char book[200];
    int found = 0, a, i;

    printf("Ingresa el nombre del libro que deseas editar: \n");
    fflush(stdout);
    scanf(" %[^\n]", book);
    for (i = 0; i <= registryCount; i++) {
        if (strcmp(book, libros[i].titulo) == 0) {
            a = i;
            found = 1;
        }
    }
    if (found == 1) {
        printf("\nPiso actual: %s\n", libros[a].piso);
        printf("Ingrese el piso:\n");
        fflush(stdout);
        scanf(" %[^\n]", edit);
        strcpy(libros[a].piso, edit);
        printf("Nuevo piso: %s\n", libros[a].piso);
    }
}
void Guardar(Libro Datos[], int j, char *archivo_csv) {
    int x;
    FILE *fp2 = fopen(archivo_csv, "w+");

    fprintf(fp2,
            "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,"
            "sede\n");

    for (x = 0; x < j; ++x) {
        if (strcmp(Datos[x].titulo, "del") == 0) {
            continue;
        }
        if (x < j - 1) {
            fprintf(fp2, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                    Datos[x].titulo, ",", Datos[x].autor, ",",Datos[x].anio, ",", Datos[x].estante_numero, ",",Datos[x].estante_seccion ,",",Datos[x].piso, ",",Datos[x].edificio,",", Datos[x].sede);
        }
        else {
            fprintf(fp2, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                    Datos[x].titulo, ",", Datos[x].autor, ",",
                    Datos[x].anio, ",", Datos[x].estante_numero, ",",
                    Datos[x].estante_seccion, ",",Datos[x].piso, ",",
                    Datos[x].edificio,",", Datos[x].sede);
        }
    }
    fclose(fp2);
}
void QuitarLibro(Libro Datos[], int j) {
    char tituloAQuitar[200];
    int found = 0;
    int ind;
    int y;


    printf("Ingresa el nombre del libro a eliminar:\n");
    fflush(stdout);
    scanf(" %[^\n]", tituloAQuitar);

    for (y = 0; y < j; ++y) {
        if (strcmp(tituloAQuitar, Datos[y].titulo) == 0) {
            found = 1;
            ind = y;
        }
    }

    if (found == 1) {
        printf("Libro encontrado.\n");
        strcpy(Datos[ind].titulo, "del");
        strcpy(Datos[ind].autor, " ");
        strcpy(Datos[ind].anio, " ");
        strcpy(Datos[ind].estante_numero, " ");
        strcpy(Datos[ind].estante_seccion, " ");
        strcpy(Datos[ind].piso, " ");
        strcpy(Datos[ind].edificio, " ");
        strcpy(Datos[ind].sede, " ");
        printf("...\n");
        printf("Libro eliminado.\n");
    } else {
        printf("No se encuentra el libro.\n");
    }
}
