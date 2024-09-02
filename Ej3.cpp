/*
Crear una función que reciba una pila por referencia y un número. La función
 debe sacar la primera ocurrencia de dicho valor de la pila sino se repite el
 valor en la pila, de lo contrario debe eliminar todos los valores repetidos
 a excepción de la primera ocurrencia. Si el valor no se encuentra en la pila
 muestra un mensaje indicando que no pertenece a la pila. Imprimir la pila al
 final para verificar si hubo o no modificaciones.


 */
#include <iostream>
#include "Pila/Pila.h"  // Incluye la biblioteca de la pila

using namespace std;

void eliminarOcurrencias(Pila<int>& pila, int valor) {
    Pila<int> pilaAux;
    bool encontrado = false;
    int contador = 0;

    // Desapila los elementos y cuenta las ocurrencias del valor
    while (!pila.esVacia()) {
        int dato = pila.pop();
        if (dato == valor) {
            if (!encontrado) {
                encontrado = true;  // Marca que la primera ocurrencia fue encontrada
                pilaAux.push(dato);  // Mantiene la primera ocurrencia
            }
            contador++;  // Cuenta las ocurrencias del valor
        } else {
            pilaAux.push(dato);
        }
    }

    // Restaurar la pila original, omitiendo las ocurrencias adicionales si se encontró más de una
    while (!pilaAux.esVacia()) {
        int aux;
        aux = pilaAux.pop();
        if(encontrado && contador ==1 && aux == valor ){

        }else{
            pila.push(aux);
        }
    }

    // Verifica si el valor fue encontrado y actúa en consecuencia
//    if (contador == 0) {
//        cout << "El valor " << valor << " no pertenece a la pila." << endl;
//    } else if (contador > 1) {
//        cout << "Eliminadas " << contador - 1 << " ocurrencias adicionales del valor " << valor << "." << endl;
//    } else {
//        cout << "Se mantuvo la única ocurrencia del valor " << valor << " en la pila." << endl;
//    }
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main() {

    cout << "Ejercicio 03/03" << endl;

    Pila<int> pila;

    // Ejemplo: apilar algunos valores
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);

    // Mostrar la pila antes de la modificación
    cout << "Pila antes de la modificacion: ";
    mostrarPila(pila);

    // Eliminar ocurrencias del valor 2
    eliminarOcurrencias(pila, 5);

    // Mostrar la pila después de la modificación
    cout << "Pila despues de la modificacion: ";
    mostrarPila(pila);

    return 0;
}
