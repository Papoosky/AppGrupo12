#include "header.h"
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
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
void EditarSeccion(Libro *libros, int j) {
    char name[50];
    printf("Ingrese el nombre de la secci贸n que desea editar \n");
    scanf("%s", &name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerCase(libros[i].estante_seccion);
        char *nameToLook = toLowerCase(name);
        char *ret = strstr(nameConverted, nameToLook);
        if(ret){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1) {
        printf("\nSecci贸n actual: %s\n", libros[i].estante_seccion);
        printf("Ingrese el piso:\n");
        fflush(stdout);
        scanf(" %[^\n]", name);
        strcpy(libros[i].estante_seccion, name);
        printf("Nueva secci贸n: %s\n", libros[i].estante_seccion);
    }
    else {
        printf("La secci贸n no existe!");
    }

}

void EditarSede(Libro *libros, int j) {
    char name[50];
    printf("Ingrese el nombre de la sede que desea editar \n");
    scanf("%s", &name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerCase(libros[i].sede);
        char *nameToLook = toLowerCase(name);
        char *ret = strstr(nameConverted, nameToLook);
        if(ret){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1) {
        printf("\nPiso actual: %s\n", libros[i].sede);
        printf("Ingrese el sede:\n");
        fflush(stdout);
        scanf(" %[^\n]", name);
        strcpy(libros[i].sede, name);
        printf("Nuevo sede: %s\n", libros[i].sede);
    }
    else {
        printf("La sede no existe!");
    }

}


void EditarPiso(Libro *libros, int j) {
    char name[50];
    printf("Ingrese el nombre del piso que desea editar \n");
    scanf("%s", &name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerCase(libros[i].piso);
        char *nameToLook = toLowerCase(name);
        char *ret = strstr(nameConverted, nameToLook);
        if(ret){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1) {
        printf("\nPiso actual: %s\n", libros[i].piso);
        printf("Ingrese el piso:\n");
        fflush(stdout);
        scanf(" %[^\n]", name);
        strcpy(libros[i].piso, name);
        printf("Nuevo piso: %s\n", libros[i].piso);
    }
    else {
        printf("El piso no existe!");
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

void QuitarLibro(Libro Datos[], int j, char *archivo_csv) {
    char tituloAQuitar[200];
    int x;

    printf("Ingresa el nombre del libro a eliminar:\n");
    fflush(stdout);
    scanf(" %[^\n]", tituloAQuitar);

    for (int x = 0; x < j; ++x) {
        if (strcmp(tituloAQuitar,Datos[x].titulo) == 0) {
            Datos[x].to_delete = +1;
        }
    }

    FILE *fp;
    fp= fopen(archivo_csv, "w+");

    fprintf(fp,
            "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
    for (int x = 0; x < j; ++x) {
        if (Datos[x].to_delete != 1) {
            fprintf(fp, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                    Datos[x].titulo, ",", Datos[x].autor, ",",
                    Datos[x].anio, ",", Datos[x].estante_numero, ",",
                    Datos[x].estante_seccion, ",", Datos[x].piso, ",",
                    Datos[x].edificio, ",", Datos[x].sede);
        }

    }
    fclose(fp);

}

void buscarLibro(Libro *libros) {
    char name[50];
    printf("Ingrese el nombre del libro que desea buscar \n");
    scanf("%s", &name);
    //Hago una busqueda linea
    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *nameConverted = toLowerCase(libros[i].titulo);
        char *nameToLook = toLowerCase(name);
        char *ret = strstr(nameConverted, nameToLook);
        if(ret){
            encontre = 1;
        } else {
            i++;
        }
    }
    //verifico que sali por que encontre
    if (encontre == 1){
        printf("La persona Existe, estos son los datos \n");
        printf("%s,%s,%s,%s,%s,%s,%s,%s. \n", libros[i].titulo,
               libros[i].autor, libros[i].anio,libros[i].estante_numero,libros[i].estante_seccion,libros[i].piso,
               libros[i].edificio,libros[i].sede);
    } else {
        printf("La persona no existe!");
    }

}
char *toLowerCase(char *name) {
    char *converted =  (char*)malloc( strlen(name) * sizeof(char));
    strcpy(converted,name);
    for(int i = 0; converted[i]; i++){
        converted[i] = tolower(converted[i]);
    }
    return converted;
}