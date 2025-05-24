#include <iostream>

/**
 * Ingresar un texto en un arreglo de caracteres definido de TOPE elementos, solicitarle al usuario que
 * ingrese 2 caracteres y desarrollar una función que reciba el arreglo, el TOPE, los 2 caracteres ingresados
 * y devuelva la posición donde encuentre al primero de alguno de esos 2 caracteres.
 *
 * Si no encontrase ninguno de ambos caracteres debe devolver -1.
 *
 * De acuerdo al resultado de la función el programa principal deberá indicar
 * “AL MENOS UNO” o “NO ESTÁN”
 */

using namespace std;

const int TOPE = 50;

int buscarCaracteres(char texto[], char caracter1, char caracter2, int tope)
{
    int idx = 0;
    bool caracterEncontrado = false;

    while (texto[idx] != '\0' && idx < tope && caracterEncontrado == false)
    {

        if (texto[idx] == caracter1 || texto[idx] == caracter2)
        {
            caracterEncontrado = true;
        }
        else
        {
            idx++;
        }
    }

    int valorRetorno = -1;

    if (caracterEncontrado)
    {
        valorRetorno = idx;
    }

    return valorRetorno;
}

int main()
{

    char texto[TOPE] = "";
    char car1, car2;

    cout << "ingrese texto: " << endl;
    cin.getline(texto, TOPE);

    cout << "ingrese caracter 1 " << endl;
    cin >> car1;
    cout << "ingrese caracter 2 " << endl;
    cin >> car2;

    int resultadoBusqueda = buscarCaracteres(texto, car1, car2, TOPE);

    if (resultadoBusqueda == -1)
    {
        cout << "NO ESTÆ";
    }
    else
    {
        cout << "AL MENOS UNO";
    }

    return EXIT_SUCCESS;
}