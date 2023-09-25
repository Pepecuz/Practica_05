// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 18/09/2023
// Fecha modificación: 19/09/2023
// Número de ejericio: 3
// Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del
//Multicine.
//Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de
//autos
//Piso 1 – 50 autos
//Piso 2 – 40 autos
//Piso 3 – 30 autos
//Piso 4 – 45 autos
//El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas,
//automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del
//auto.
//Escribir un programa en C++ utilizando funciones y estructuras para:
//• Simular la entrada de vehículos, el programa debe pedir la cantidad de
//vehículos ingresados y el programa debe simular los tipos de vehículo, la
//marca, el modelo, el color y en que piso se han estacionado.
//• La simulación puede repetirse varias veces hasta que el usuario ingrese el valor
//de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se
//incremental.
//• Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en
//cada piso.
//• Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
//• Hacer un reporte por colores de autos, modelo y marca.
//• La simulación debe determinar cuando el parqueo se ha llenado.
//• La simulación debe determinar cuántos espacios libres queda

#include <iostream>
#include <string>
using namespace std;


struct Vehiculo {
    string tipo;
    string marca;
    string modelo;
    string color;
};

struct Piso {
    int capacidad;
    int ocupados;
};


void ingresarVehiculo(Piso pisos[], Vehiculo vehiculo) {
    int pisoSeleccionado = -1;

    for (int i = 0; i < 4; i++) {
        if (pisos[i].ocupados < pisos[i].capacidad) {
            pisoSeleccionado = i;
            break;
        }
    }

    if (pisoSeleccionado != -1) {
        pisos[pisoSeleccionado].ocupados++;
        cout << "Vehículo estacionado en el piso " << pisoSeleccionado + 1 << endl;
        cout << "Tipo: " << vehiculo.tipo << ", Marca: " << vehiculo.marca << ", Modelo: " << vehiculo.modelo << ", Color: " << vehiculo.color << endl;
    } else {
        cout << "El estacionamiento está lleno. No se puede estacionar más vehículos." << endl;
    }
}

int main() {
  
    Piso pisos[4] = {{50, 0}, {40, 0}, {30, 0}, {45, 0}};

    int cantidadVehiculos = 0;
    while (true) {
        cout << "Ingrese la cantidad de vehículos a estacionar (0 para salir): ";
        cin >> cantidadVehiculos;

        if (cantidadVehiculos == 0) {
            break;
        }

        for (int i = 0; i < cantidadVehiculos; i++) {
            Vehiculo vehiculo;
            cout << "Ingrese el tipo de vehículo (vagoneta, camioneta, automóvil, minivan, motocicleta): ";
            cin >> vehiculo.tipo;
            cout << "Ingrese la marca del vehículo: ";
            cin >> vehiculo.marca;
            cout << "Ingrese el modelo del vehículo: ";
            cin >> vehiculo.modelo;
            cout << "Ingrese el color del vehículo: ";
            cin >> vehiculo.color;

            ingresarVehiculo(pisos, vehiculo);
        }

        cout << "Ocupación por piso:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Piso " << i + 1 << ": " << pisos[i].ocupados << " vehículos" << endl;
        }
    }

    // Reporte de ocupación total
    int totalOcupados = 0;
    for (int i = 0; i < 4; i++) {
        totalOcupados += pisos[i].ocupados;
    }

    int espaciosLibres = 4 * (50 + 40 + 30 + 45) - totalOcupados;
    cout << "Total de vehículos estacionados: " << totalOcupados << endl;
    cout << "Espacios libres: " << espaciosLibres << endl;

    return 0;
}
