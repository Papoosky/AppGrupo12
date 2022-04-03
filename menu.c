#include "header.h"
void menu(Libro libros[], int j, char *archivo_csv) {
    int cerrar = 0, trig = 0;
    while (cerrar == 0) {
        int opcion, subopcion, salir = 0;
        if (trig == 1) {

            FILE *notas = fopen(archivo_csv, "r");
            libros = getLibros(notas);

            fclose(notas);
            trig = 0;
        }


        printf("\nBienvenido a la biblioteca\n");
        printf("Selecciona una opcion: \n");
        printf("1. Aniadir/Quitar un libro.\n");
        printf("5. Editar libro.\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        do {
            switch (opcion) {
                case 1: {
                    printf("[Aniadir o quitar un libro]\n");
                    printf("Selecciona una opcion:\n");
                    printf("1. Aniadir un libro.\n");
                    printf("2. Quitar un libro.\n");
                    printf("3. Atras.\n");
                    scanf("%d", &subopcion);
                    printf("\n");
                    switch (subopcion) {
                        case 1: {
                            Guardar(libros, registryCount, archivo_csv);
                            agregarLibro(archivo_csv);
                            trig = 1;
                            opciones(&cerrar, &salir);
                        }break;
                        case 2: {
                            QuitarLibro(libros, j);
                            j--;
                            Guardar(libros, registryCount, archivo_csv);
                            opciones(&cerrar, &salir);
                        } break;
                        case 3: {
                            salir = 1;
                            cerrar = 1;
                        }break;
                    }
                }break;
                case 5:{

                    printf("[Editar un libro]\n");
                    printf("Selecciona una opcion:\n");
                    printf("1.   Editar informacion del libro.\n");
                    printf("2.   Editar sede del libro.\n");
                    printf("3.   Editar piso del libro.\n");
                    printf("4.   Editar seccion del libro.\n");
                    printf("5.   Atras.\n");
                    printf("Opcion: ");
                    scanf("%d", &subopcion);
                    printf("\n");
                    switch (subopcion) {
                        case 1: {

                            EditarLibro(libros, registryCount);
                            Guardar(libros, registryCount, archivo_csv);
                            opciones(&cerrar, &salir);
                        } break;

                        case 2: {

                            EditarSede(libros, registryCount);
                            opciones(&cerrar, &salir);
                        } break;

                        case 3: {

                            EditarPiso(libros, registryCount);
                            opciones(&cerrar, &salir);
                        } break;

                        case 4: {

                            EditarSeccion(libros, registryCount);
                            opciones(&cerrar, &salir);
                        } break;

                        case 5: {

                            printf("Volviendo al menú principal...\n");
                            salir = 1;
                        } break;
                    }
                }break;
            }
        }while (salir == 0);
    }
}