// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 18/09/2023
// Fecha modificación: 19/09/2023
// Número de ejericio: 1
// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo
//struct llamada “empleado”.
//La información con que se cuenta es: nombre, ci, departamento y salario.
//Realizar un programa en C++ que lea un array de estructura de los datos de N
//empleados e imprima los siguiente:
//• Empleado con mayor salario
//• Empleado con menor salario
//• Promedio salarial
//• Promedio por departamento
//• Departamento con mayor salario en promedio
//• Departamento con menor salario en promedio
#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    string nombre;
    int ci;
    string departamento;
    double salario;
};

int main() {
    int N;
    cout << "Ingrese el número de empleados: ";
    cin >> N;

    Empleado empleados[N];

    for (int i = 0; i < N; i++) {
        cout << "Ingrese el nombre del empleado " << i + 1 << ": ";
        cin >> empleados[i].nombre;
        cout << "Ingrese la CI del empleado " << i + 1 << ": ";
        cin >> empleados[i].ci;
        cout << "Ingrese el departamento del empleado " << i + 1 << ": ";
        cin >> empleados[i].departamento;
        cout << "Ingrese el salario del empleado " << i + 1 << ": ";
        cin >> empleados[i].salario;
    }

    Empleado empleadoMayorSalario = empleados[0];
    Empleado empleadoMenorSalario = empleados[0];
    double sumaSalarios = 0;
    int contadorPorDepartamento[N] = {0};
    double sumaSalariosPorDepartamento[N] = {0};

    for (int i = 0; i < N; i++) {
        // Empleado con mayor salario
        if (empleados[i].salario > empleadoMayorSalario.salario) {
            empleadoMayorSalario = empleados[i];
        }

        // Empleado con menor salario
        if (empleados[i].salario < empleadoMenorSalario.salario) {
            empleadoMenorSalario = empleados[i];
        }

        // Promedio salarial
        sumaSalarios += empleados[i].salario;

        // Promedio por departamento
        for (int j = 0; j < N; j++) {
            if (empleados[i].departamento == empleados[j].departamento) {
                contadorPorDepartamento[i]++;
                sumaSalariosPorDepartamento[i] += empleados[j].salario;
            }
        }
    }

    double promedioSalarial = sumaSalarios / N;
    string departamentoMayorSalario;
    string departamentoMenorSalario;
    double mayorPromedioSalario = 0;
    double menorPromedioSalario = sumaSalariosPorDepartamento[0] / contadorPorDepartamento[0];

    for (int i = 0; i < N; i++) {
        double promedio = sumaSalariosPorDepartamento[i] / contadorPorDepartamento[i];
        if (promedio > mayorPromedioSalario) {
            mayorPromedioSalario = promedio;
            departamentoMayorSalario = empleados[i].departamento;
        }
        if (promedio < menorPromedioSalario) {
            menorPromedioSalario = promedio;
            departamentoMenorSalario = empleados[i].departamento;
        }
    }

    // Resultados
    cout << "Empleado con mayor salario: " << empleadoMayorSalario.nombre << " (CI: " << empleadoMayorSalario.ci << ")" << endl;
    cout << "Empleado con menor salario: " << empleadoMenorSalario.nombre << " (CI: " << empleadoMenorSalario.ci << ")" << endl;
    cout << "Promedio salarial: " << promedioSalarial << endl;
    cout << "Departamento con mayor salario promedio: " << departamentoMayorSalario << endl;
    cout << "Departamento con menor salario promedio: " << departamentoMenorSalario << endl;

    return 0;
}

