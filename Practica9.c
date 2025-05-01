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

void Menu(Producto*, Ticket*, int, float *);
void ClearBuffer();
void StartProducts(Producto*, int);
void StartTicket(Ticket*, int);
void ShowProducts(Producto*, int);
void ShowTicket(Ticket*, int, float *);
void AddProduct(Producto*, int);
void ScanProduct(Ticket*, Producto*, int, float *);

int main(void){
    // Declaracion e Inicializacion de variables
    Producto inventario[MAX];
    Ticket registro[MAX];
    float total = 0;
    // Inicializacion de arreglos
    StartProducts(&inventario[0], MAX);
    StartTicket(&registro[0], MAX);
    // Llamada a menu
    Menu(&inventario[0], &registro[0], MAX, &total);
    return 0;
}

// Procedimientos
void Menu(Producto *inventario, Ticket *registro, int size, float *total){
    int opc = 0;
    do{
        printf("\n---------------------------Calimax---------------------------\n");
        printf("[1] Agregar/Editar Productos  [4] Mostrar Ticket de Compra\n");
        printf("[2] Escanear Codigo           [5] Borrar Ticket de compra\n");
        printf("[3] Mostra Lista de Productos [0] Terminar Programa\n");
        printf("Seleccione una opcion\n>> ");
        scanf("%d", &opc);
        switch(opc){
            case 1: // Agregar/Editar Productos'
                AddProduct(&inventario[0], size);
                break;
            case 2: // Escarear Codigo
                ScanProduct(&registro[0], &inventario[0], size, total);
                break;
            case 3: // Mostrar Lista de Productos
                printf("\nProductos\n\n");
                ShowProducts(&inventario[0], size);
                break;
            case 4: // Mostrar Ticket de Compra
                printf("\nTicket\n\n");
                ShowTicket(&registro[0], size, total);
                break;  
            case 5: // Borrar Ticket de Compra
                StartTicket(&registro[0], size);
                break;
            case 0:
                printf("Terminando programa...\n");
                break;
            default:
                printf("Opcion invalida...\n");
                break;
        }
    }while(opc != 0);
}
void ClearBuffer(){
    char c;
	while((c = getchar() ) != '\n' && c != EOF);
}
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
        if(producto[i].codigo != -1){
            printf("%-12d %-7lld %-15s %-.2f\n", i+1, producto[i].codigo, producto[i].nombre, producto[i].precio);
        }
    }
}
void ShowTicket(Ticket *registro, int size, float *total){
    printf("%-5s %-10s %s\n", "#", "Referencia", "Cantidad");
    for(int i = 0; i < size; i++){
        if(registro[i].ref != NULL)
            printf("%-8d %-11lld %-10d\n", i+1, registro[i].ref->codigo, registro[i].cantidad);
    }
    printf("%-10s %.2f\n", "Total", *total);
}
void AddProduct(Producto *producto, int size){
    long long code = 0;
    int newPrice = 0;
    int indx = 0;
    printf("Ingresa el codigo del producto: ");
    scanf("%lld", &code);
    ClearBuffer();
    // Se busca el codigo ingresado
    for(int i = 0; i < size; i++){
        if(producto[i].codigo == code){
            // Se modifica el precio del codigo encontrado
            printf("Actualiza el precio del producto [%s]\n>> ", producto[i].nombre);
            scanf("%d", &newPrice);
            ClearBuffer();
            producto[i].precio = newPrice;
            return;
        }
    }
    // No se encontro un codigo igual
    // Se genera un nuevo producto
    for(int i = 0; i < size; i++){
        if(producto[i].codigo == -1){
            // Creamos nuevo producto
            producto[i].codigo = code;
            printf("Ingresa el nombre del nuevo producto\n>> ");
            fgets(producto[i].nombre, MAX, stdin);
            // Removemos el salto de linea ingresado por el fgets
            for (int j = 0; producto[i].nombre[j] != '\0'; j++) {
                if (producto[i].nombre[j] == '\n') {
                    producto[i].nombre[j] = '\0'; 
                    break;
                }
            }
            printf("Ingresa el precio del nuevo producto\n>> ");
            scanf("%d", &newPrice);
            ClearBuffer();
            producto[i].precio = newPrice;
            return;
        }
    }
}
void ScanProduct(Ticket *registro, Producto *inventario, int size, float *total){
    long long code = 0;
    printf("Escanea el codigo del producto: ");
    scanf("%lld", &code);
    ClearBuffer();
    // Buscar el prodcuto en el inventario
    Producto *foundProduct = NULL;
    for(int i = 0; i < size; i++){
        if(inventario[i].codigo == code){
            foundProduct = &inventario[i];
        }
    }
    if(foundProduct == NULL){
        printf("Codigo no registrado\nPor favor registra el codigo en la lista de productos o asegurate de ingresar bien el codigo\n");
        return;
    }
    // Buscar la direccion en el ticket
    for(int i = 0; i < size; i++){
        if(registro[i].ref == foundProduct){
            // El producto ya se encuentra, incrementamos cantidad
            registro[i].cantidad++;
            *total += registro[i].ref->precio;
            return;
        }
    }
    // Si no esta en el ticket, asignamos una posicion
    for(int i = 0; i < size; i++){
        if(registro[i].ref == NULL){
            registro[i].ref = foundProduct;
            registro[i].cantidad = 1;
            *total += registro[i].ref->precio;
            return;
        }
    }
    printf("No hay espacio en el ticket para agregar más productos.\n");
}