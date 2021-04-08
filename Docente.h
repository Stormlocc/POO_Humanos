#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;

class Docente : public Persona
{
private:
    string asignatura;

public:
    Docente();
    Docente(string, string, string);
    void Leer();
    void Mostrar();
    ~Docente();
};

Docente::Docente()
    : Persona()
{
    asignatura = " no defindiop";
}

Docente::Docente(string _nombre, string _dni, string _asignatura)
    : Persona(_nombre, _dni)
{
    asignatura = _asignatura;
}

void Docente::Leer()
{
    Persona::Leer();
    cout << "Asignatura: ";
    cin >> asignatura;
}

void Docente::Mostrar()
{
    Persona::Mostrar();
    cout << "Asignatura: " << asignatura << endl;
}

Docente::~Docente()
{
}
