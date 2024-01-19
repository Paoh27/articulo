#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    char productoBuscar[25];
    char nuevoProducto[25];
    int nuevaCantidad;
    char productoBorrar[25];

    do {
        printf("\n1. Imprimir lista de productos\n");
        printf("2. Buscar producto\n");
        printf("3. Agregar producto\n");
        printf("4. Borrar registro\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirListaProductos();
                break;
            case 2:
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", productoBuscar);
                buscarProducto(productoBuscar);
                break;
            case 3:
                printf("Ingrese el nombre del nuevo producto: ");
                while (getchar() != '\n');
                fgets(nuevoProducto, 25, stdin);
                agregarProducto(nuevoProducto);
                break;
            case 4:
                printf("Ingrese el nombre del producto a borrar: ");
                scanf("%s", productoBorrar);
                borrarProducto(productoBorrar);
                break;
            case 0:
                printf("Saliendo del programa. \n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}
