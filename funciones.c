#include <stdio.h>
#include <string.h>
#include "funciones.h"

void imprimirListaProductos() {
    FILE *archivo = fopen("archivo1.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    char producto[25];
    int cant;

    printf("Lista de productos:\n");

    while (fscanf(archivo, "Nombre producto: %s\nCantidad: %d\n", producto, &cant) == 2) {
        printf("%s - Cantidad: %d", producto, cant);
    }

    fclose(archivo);
}

int buscarProducto(char *productoBuscar) {
    FILE *archivo = fopen("archivo1.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return -1; 
    }

    int cant;
    char producto[25];
    int encontrado = 0;

    while (fscanf(archivo, "Nombre producto: %s\nCantidad: %d\n", producto, &cant) == 2) {
        if (strcmp(producto, productoBuscar) == 0) {
            printf("La cantidad de %s es: %d\n", productoBuscar, cant);
            encontrado = 1;
            break;
        }
    }

    fclose(archivo);

    if (!encontrado) {
        printf("Producto no encontrado.\n");
        return 0; 
    }

    return 1; 
}

int agregarProducto(char *nuevoProducto) {
    FILE *archivo = fopen("archivo1.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return 0; 
    }

    int nuevaCantidad;
    printf("Ingrese la cantidad del nuevo producto: ");
    scanf("%d", &nuevaCantidad);

    fprintf(archivo, "Nombre producto: %s Cantidad: %d\n", nuevoProducto, nuevaCantidad);

    fclose(archivo);
    return 1; 
}

int borrarProducto(char *productoBorrar) {
    FILE *tempArchivo = fopen("temp.txt", "w");
    if (tempArchivo == NULL) {
        printf("Error al abrir el archivo temporal");
        return 0;
    }

    FILE *archivo = fopen("archivo1.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        fclose(tempArchivo);
        return 0; 
    }

    int cant;
    char producto[25];
    int encontrado = 0;

    while (fscanf(archivo, "Nombre producto: %s\nCantidad: %d\n", producto, &cant) == 2) {
        if (strcmp(producto, productoBorrar) != 0) {
            fprintf(tempArchivo, "Nombre producto: %s\nCantidad: %d\n", producto, cant);
        } else {
            encontrado = 1;
        }
    }

    fclose(archivo);
    fclose(tempArchivo);

    remove("archivo1.txt");
    rename("temp.txt", "archivo1.txt");

    if (!encontrado) {
        printf("Producto no encontrado.\n");
        return 0; 
    }

    printf("Registro eliminado correctamente.\n");
    return 1; 
}
