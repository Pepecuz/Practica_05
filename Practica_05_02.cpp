// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 18/09/2023
// Fecha modificación: 19/09/2023
// Número de ejericio: 2
// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y
//nos devuelva el país que mayor número de medallas ha ganado.
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Atleta {
    string nombre;
    string pais;
    int medallas;
};

int main() {
    int N;
    cout << "Ingrese el número de atletas: ";
    cin >> N;

    map<string, int> medallasPorPais;

    for (int i = 0; i < N; i++) {
        Atleta atleta;
        cout << "Nombre del atleta " << i + 1 << ": ";
        cin >> atleta.nombre;
        cout << "País del atleta " << i + 1 << ": ";
        cin >> atleta.pais;
        cout << "Número de medallas del atleta " << i + 1 << ": ";
        cin >> atleta.medallas;

        medallasPorPais[atleta.pais] += atleta.medallas;
    }

    
    string paisMayorMedallas;
    int mayorMedallas = 0;

    for (const auto& entry : medallasPorPais) {
        if (entry.second > mayorMedallas) {
            mayorMedallas = entry.second;
            paisMayorMedallas = entry.first;
        }
    }

 
    cout << "El país con el mayor número de medallas es: " << paisMayorMedallas << " con " << mayorMedallas << " medallas." << endl;

    return 0;
}
