#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
Desarrollar un programa en C++ para la resolución del siguiente problema.
Otro equipo de desarrollo trabajo en la función
Factura obtenerSiguienteFactura();
Esta función devuelve un registro de tipo Factura. :

Se deben procesar las facturas hasta que no haya más facturas pendientes.

Aclaración: Se hace una factura por cada producto. Los datos NO deben ser validados, ya que la función los devuelve validados.

Luego de procesarlas, se pide mostrar:
Por cada venta: Descripción del producto, precio e importe final de la venta.
Sobre el total de datos ingresados:
Cantidad total de facturas por cada Rubro.
Importe promedio por factura de Alcoholes.
Descripción del producto que corresponde a la factura de mayor importe del Rubro Lavandinas.
*/
struct Factura
{
    string descripcion; // si no hay más facturas, la descripción es “fin”
    char rubro;         // (‘D’ Desinfectantes, ‘A’ Alcoholes, ‘L’ Lavandinas)
    float precio;       // siempre mayor a cero
    int cantidad;       // siempre mayor a cero
};

int indice = 0;

Factura vecFactu[10] = {
    {"Prod_1", 'D', 11.1, 1},
    {"Prod_2", 'D', 21.2, 1},
    {"Prod_3", 'D', 31.3, 1},
    {"Prod_4", 'A', 12.1, 2},
    {"Prod_5", 'A', 22.2, 2},
    {"Prod_6", 'A', 32.3, 2},
    {"Prod_7", 'L', 13.1, 3},
    {"Prod_8", 'L', 23.1, 3},
    {"Prod_9", 'L', 33.3, 3},
    {"fin", ' ', 0.0, 0},
};

Factura obtenerSiguienteFactura()
{
    return vecFactu[indice++];
}

/***************** HASTA ACÁ LO QUE VENÍA DADO POR LA CONSIGNA, QUE NO DEBÍAN PROGRAMAR USTEDES *****************/

void imprimirFactura(Factura f)
{
    cout << "Descripcion: " << f.descripcion << " Precio: " << f.precio << " Importe final: " << f.cantidad * f.precio << "\n";
}

void procesarFactura(Factura f, int &cantD, int &cantA, int &cantL,
                     float &importeAcumAlc, string &descMayorPrecioLava, float &mayorPrecioLava)
{
    switch (f.rubro)
    {
    case 'D':
        cantD++;
        break;
    case 'A':
        cantA++;
        importeAcumAlc += f.cantidad * f.precio;
        break;
    case 'L':
        cantL++;
        if (f.cantidad * f.precio > mayorPrecioLava)
        {
            mayorPrecioLava = f.cantidad * f.precio;
            descMayorPrecioLava = f.descripcion;
        }
        break;
    }
}

int main()
{
    Factura facActual = obtenerSiguienteFactura();
    int cantD = 0;
    int cantA = 0;
    int cantL = 0;
    float importeAcumAlc, mayorPrecioLava = 0;
    string descMayorPrecioLava = " ";

    while (facActual.descripcion != "fin")
    {
        imprimirFactura(facActual);

        procesarFactura(facActual, cantD, cantA, cantL, importeAcumAlc, descMayorPrecioLava, mayorPrecioLava);

        facActual = obtenerSiguienteFactura();
    }

    cout << "\n\n*****  TOTALES POR RUBRO *****\n\n";
    cout << "Desinfectantes: " << cantD << " Alcoholes: " << cantA << " Lavandinas: " << cantL;
    cout << "\n\n***********\n\nImporte promedio por factura de Alcoholes: " << importeAcumAlc / cantA;
    cout << "\n\n***********\n\nDescripción del producto de la factura de mayor importe del Rubro Lavandinas: "
         << descMayorPrecioLava;

    return EXIT_SUCCESS;
}