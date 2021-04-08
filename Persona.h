#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona
{
private:
    string nombre;
    string dni;

public:
    Persona();
    Persona(string, string);
    void Leer();
    void Mostrar();
};

Persona::Persona()
{
    nombre = "no definido";
    dni = "no definido";
}

Persona::Persona(string _nombre, string _dni)
{
    nombre = _nombre;
    dni = _dni;
}

void Persona::Leer()
{
    cout << "========================================" << endl;
    cout << "======---LEER INFORM DE PERSONA---======" << endl;
    cout << "========================================" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "DNI: ";
    cin >> dni;
}

void Persona::Mostrar()
{
    cout << "----INFORMACION DE PERONSA----" << endl;
    cout << "============------============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "DNI: " << dni << endl;
}
