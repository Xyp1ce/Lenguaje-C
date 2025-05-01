/*
    Ramon Manriquez Guerrero
    2210376
    Estructuras para la generacion de un ticket de compra
*/

#include <stdio.h>
#include <stdlib.h>

// Constantes

#define MAX 10

// Estructuras

typedef struct {
        long long codigo;
        char nombre[MAX];
        float precio;
} Producto;

typedef struct {
    Producto *ref;
    int cantidad;
} Ticket;

// Prototipos

void StartProducts(Producto*, int);
void StartTicket(Ticket*, int);
void ShowProducts(Producto*, int);
void ShowTicket(Ticket*, int);

int main(void){
    Producto inventario[MAX];
    Ticket registro[MAX];

    StartProducts(&inventario[0], MAX);
    StartTicket(&registro[0], MAX);
    printf("\nProductos\n\n");
    ShowProducts(&inventario[0], MAX);
    printf("\nTicket\n\n");
    ShowTicket(&registro[0], MAX);
    return 0;
}

// Procedimientos
void StartProducts(Producto *producto, int size){
    for(int i = 0; i < size; i++){
        producto[i].codigo = -1;
        // Tendre que quitar esto, solamente es para ver si funciona bien
        for(int j = 0; j < size - 1; j++){
            producto[i].nombre[j] = '-';
        }
        producto[i].nombre[size-1] = '\0';
        // Hasta aqui
        producto[i].precio = 0.0;
    }
}
void StartTicket(Ticket *registro, int size){
    for(int i = 0; i < size; i++){
        registro[i].ref = NULL;
        registro[i].cantidad = 0;
    }
}
void ShowProducts(Producto *producto, int size){
    printf("%-10s %-10s %-10s %10s\n", "#", "Codigo", "Nombre", "Precio");
    for(int i = 0; i < size; i++){
        printf("%-12d %-7lld %-16s %-10.2f\n", i+1, producto[i].codigo, producto[i].nombre, producto[i].precio);
    }
}
void ShowTicket(Ticket *registro, int size){
    printf("%-5s %-10s %s\n", "#", "Referencia", "Cantidad");
    for(int i = 0; i < size; i++){
        if(registro->ref == NULL)
            printf("%-8d %-11s %-10d\n", i+1, "NULL", registro[i].cantidad);
    }
}