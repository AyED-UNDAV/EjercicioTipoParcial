#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

/*
Necesitamos un programa que procese la información de ventas de nuestro nuevo almacén de vinos.
Para eso nos dieron una función que tiene la siguiente definición:

void obtenerInformacionAProcesar(tyInfo &infoVenta)

donde se le pasan los parámetros que serán modificados en la función y tendrán la información cargada.
Dicha información tiene el siguiente formato:

Tipo de vino (B para blanco, T para tinto, R para rosado): char
Descripción del producto: char[]
Precio: float
Cantidad: int

De no tener más información, la descripción viene cargada con la palabra "fin".
Se pide:
a) Mostrar en pantalla en el caso que el tipo de vino sea otro que los mencionados.
En ese caso no se debe procesar la venta para los totales.

El resto de los datos ingresados los asumimos correctos.

b) Sobre el total de datos ingresados válidos:
Cantidad total de vinos vendidos por cada tipo.
Categoría y cantidad del vino más vendido.
*/

struct tyInfo
{
    char tipoVino; //(B para blanco, T para tinto, R para rosado):
    char descripcion[50];
    float precio;
    int cantidad;
};
int indice = 0;
tyInfo vinosVendidos[12] = {
    {'B', "Vino Blanca", 11.1, 1},
    {'B', "Vino Blanca", 12.2, 1},
    {'B', "Vino Blanca", 13.3, 1},
    {'T', "Vino Tinto", 21.1, 2},
    {'T', "Vino Tinto", 22.2, 2},
    {'T', "Vino Tinto", 23.3, 2},
    {'R', "Vino Rosado", 31.1, 3},
    {'R', "Vino Rosado", 32.2, 3},
    {'R', "Vino Rosado", 33.2, 3},
    {'M', "Vino Malvec", 55.1, 8},
    {'C', "Vino Cavernet", 66.6, 8},
    {'x', "fin", 88.8, 0},
};

void procesarVenta(tyInfo infoVenta, int cantTipoBino[], int &maxCantVino, char &maxTipoVino)
{
    switch (infoVenta.tipoVino)
    {
    case 'B':
        cantTipoBino[0] += infoVenta.cantidad;
        break;

    case 'T':
        cantTipoBino[1] += infoVenta.cantidad;
        break;

    case 'R':
        cantTipoBino[2] += infoVenta.cantidad;
        break;

    default:
        cout << "Categoria no registrada. Descripcion: " << infoVenta.descripcion << "\n";
        break;
    }

    if ((infoVenta.tipoVino == 'B' || infoVenta.tipoVino == 'T' || infoVenta.tipoVino == 'R') && infoVenta.cantidad > maxCantVino)
    {
        maxCantVino = infoVenta.cantidad;
        maxTipoVino = infoVenta.tipoVino;
    }
}

void obtenerInformacionAProcesar(tyInfo &infoVenta)
{
    infoVenta = vinosVendidos[indice++];
}

/*************************************** HASTA ACÁ LO QUE VENÍA DADO *****************************/

void imprimirResultados(int cantTipoBino[], int maxCantVino, char maxTipoVino)
{
    cout << "\n******* RESULTADOS PROCESADOS **************\n";
    cout << "Cantidad de vinos blanco: " << cantTipoBino[0] << "\n";
    cout << "Cantidad de vinos tinto: " << cantTipoBino[1] << "\n";
    cout << "Cantidad de vinos rosado: " << cantTipoBino[2] << "\n";
    cout << "Categoria del vino mas vendido: " << maxTipoVino << "\nCantidad del vino mas vendido: " << maxCantVino;
}

int main()
{
    tyInfo ventaActual;
    int cantTipoBino[3] = {0, 0, 0};
    int maxCantVino = 0;
    char maxTipoVino = ' ';

    obtenerInformacionAProcesar(ventaActual);

    while (strcmp("fin", ventaActual.descripcion) != 0)
    {
        procesarVenta(ventaActual, cantTipoBino, maxCantVino, maxTipoVino);
        obtenerInformacionAProcesar(ventaActual);
    }

    imprimirResultados(cantTipoBino, maxCantVino, maxTipoVino);

    return EXIT_SUCCESS;
}