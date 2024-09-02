/*
Deshacer Operaciones en un Editor de Texto

        Contexto: Imagina que estás utilizando un editor de texto que tiene una función de
        "deshacer" para revertir los cambios recientes. Cada vez que realizas un cambio en
        el documento, el editor lo guarda para que puedas deshacerlo si es necesario.
        Implementa esta funcionalidad usando una pila.

Enunciado:

Escribe un programa en C++ que simule la funcionalidad de "deshacer" de un editor de texto
 utilizando una pila. Cada vez que el usuario realiza una acción (por ejemplo, escribir una
 palabra, borrar una palabra), se debe apilar esta acción. Cuando el usuario decide "deshacer"
 una acción, se debe desapilar y mostrar cuál fue la última acción realizada.

Entrada:

Serie de acciones como "escribir" o "borrar" seguidas de la palabra correspondiente.
Comando "deshacer" para revertir la última acción.

Salida:

Estado actual del texto después de cada operación.
Acción revertida en cada comando de "deshacer".

Ejemplo: Si el usuario realiza las siguientes acciones:

 Escribir "Hola"
Escribir "Mundo"
Borrar "Mundo"
Deshacer
Deshacer

El programa debería mostrar:

Texto actual: "Hola"

*/

#include <iostream>
#include "Pila/Pila.h"
#include <string>

using namespace std;

void realizarAccion(Pila<std::string>& pilaAcciones, Pila<std::string>& pilaTexto,const std::string& accion, const std::string& palabra) {
    std::string accionCompleta = accion + " " + palabra;
    pilaAcciones.push(accionCompleta);
    pilaTexto.push(palabra);
}

void deshacerAccion(Pila<std::string>& pilaAcciones, Pila<std::string>& pilaTexto) {
    if (!pilaAcciones.esVacia()) {
        std::string ultimaAccion = pilaAcciones.pop();
        pilaTexto.pop();
        std::cout << "Deshaciendo accion: " << ultimaAccion << std::endl;
    } else {
        std::cout << "No hay acciones para deshacer." << std::endl;
    }
}

int main() {
    Pila<std::string> pilaAcciones;
    Pila<std::string> pilaTexto;

    realizarAccion(pilaAcciones, pilaTexto, "Escribir", "Hola");
    realizarAccion(pilaAcciones,pilaTexto,  "Escribir", "Mundo");
    realizarAccion(pilaAcciones,pilaTexto, "Borrar", "Mundo");
    deshacerAccion(pilaAcciones,pilaTexto);  // Deshacerá "Borrar Mundo"
    deshacerAccion(pilaAcciones,pilaTexto);  // Deshacerá "Escribir Mundo"

    cout << "Texto actual:" << endl;

    while(pilaTexto.esVacia()==0){
       cout << pilaTexto.pop() << endl;
   }
    return 0;
}
