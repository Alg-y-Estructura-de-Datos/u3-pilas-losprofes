/*
Control de Desplazamientos en un Edificio
Contexto: Un edificio cuenta con un sistema de control de accesos a través de
 tarjetas magnéticas. Cada vez que una persona entra o sale del edificio, su
 tarjeta se registra en el sistema. Queremos implementar un programa que,
 utilizando una pila, simule el movimiento de una persona dentro del edificio.

Enunciado:
Implementa un programa en C++ que utilice una pila para simular el movimiento de
 una persona en un edificio. Cada vez que la persona entra en un área del edificio
 (por ejemplo, "Recepción", "Sala de Reuniones", "Oficina"), se debe apilar el
 nombre del área. Cuando la persona sale del área, se debe desapilar el nombre.
 Al final del día, el programa debe mostrar el recorrido de la persona en orden
 inverso al que lo hizo (último lugar visitado al primero).

Entrada:

Serie de operaciones de entrada ("in") o salida ("out") de áreas específicas del
 edificio.

Salida:

El recorrido completo de la persona en orden inverso, mostrando los lugares
 que visitó.

Ejemplo: Si la persona visitó las áreas en el siguiente orden:

Entra a "Recepción"
Entra a "Oficina"
Entra a "Sala de Reuniones"
Sale de "Sala de Reuniones"
Entra a "GYM"

El programa debería mostrar:

"GYM"
"Oficina"
"Recepción"

 */
#include <iostream>
#include "Pila/Pila.h"
#include <string>
using namespace std;

void registrarDesplazamiento(Pila<std::string>& pilaMovimientos, const std::string& movimiento, const std::string& area) {
    if (movimiento == "in") {
        pilaMovimientos.push(area);
    } else if (movimiento == "out" && !pilaMovimientos.esVacia()) {
        pilaMovimientos.pop();
    }else{
        cout << "error" << endl;
    }
}

void mostrarRecorridoInverso(Pila<std::string>& pilaMovimientos) {
    std::cout << "Recorrido inverso del dia: " << std::endl;
    while (!pilaMovimientos.esVacia()) {
        std::cout << pilaMovimientos.pop() << std::endl;
    }
}

int main() {
    Pila<std::string> pilaMovimientos;

    registrarDesplazamiento(pilaMovimientos, "in", "Recepcion");
    registrarDesplazamiento(pilaMovimientos, "in", "Oficina");
    registrarDesplazamiento(pilaMovimientos, "in", "Sala de Reuniones");
    registrarDesplazamiento(pilaMovimientos, "out", "Sala de Reuniones");
    registrarDesplazamiento(pilaMovimientos, "in", "GYM");

    mostrarRecorridoInverso(pilaMovimientos);

    return 0;
}
