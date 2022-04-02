#include "header.h"
void menu(Libro libros[], int registryCount, char *archivo_csv) {
    int cerrar = 0, trig = 0;
    while (cerrar == 0) {
        int opcion, subopcion, salir = 0;
        if (trig == 1) {
            registryCount = 0;
            FILE *notas = fopen(archivo_csv, "r");
        }





            printf("\nBienvenido a la biblioteca\n");
        printf("Selecciona una opcion: \n");
        printf("1. Aniadir/Quitar un libro.\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        do {
            switch (opcion) {
                case 1: {
                    printf("[Aniadir o quitar un libro]\n");
                    printf("Selecciona una opcion:\n");
                    printf("1. Aniadir un libro.\n");
                    printf("3. Atras.\n");
                    scanf("%d", &subopcion);
                    printf("\n");
                    switch (subopcion) {
                        case 1: {
                            agregarLibro(archivo_csv);
                            opciones(&cerrar, &salir);
                        }break;
                        case 3: {
                            salir = 1;
                            cerrar = 1;
                        }break;
                    }
                }break;
            }
        }while (salir == 0);
    }
}