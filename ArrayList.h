#pragma once
#include "Alumno.h"
#include "Persona.h"
#include "Docente.h"
#include <iostream>
using namespace std ;

class ArrayList
{
private:
    /* data */
    Persona **aregloPersonas;
    int nroPersonas;

public:
    ArrayList(/* args */);
    void Ejecutar();
    void Menu();
    void MenuPersonas();
    int Ubicar(string);
    void Listar(int);   
    
};

ArrayList::ArrayList()
{
    aregloPersonas = new Persona *[100];
    nroPersonas = 0;
}

void ArrayList::MenuPersonas(){
    cout << "++++++++++++++++ TIPO DE PERSONA ++++++++++++++++++++" << endl;
    cout << "1) Persona" << endl;
    cout << "2) Alumno" << endl;
    cout << "3) Docente" << endl;
}

void ArrayList::Menu(){
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++++++++++++++++MENU DE PROGRAMA++++++++++++++++++++" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "1-> Agregar" << endl;
    cout << "2-> Ubicar" << endl;
    cout << "3-> Listar" << endl;
    cout << "4-> Eliminar" << endl;
    cout << "5-> SALIR--------------" << endl;
}

int ArrayList::Ubicar(string ubicarDNI){
    Persona *aux;
    int posicion = -1;
    int recorrido = 0;
    while (recorrido < nroPersonas)
    {
        aux = aregloPersonas[recorrido];
        if (aux->GetDni() == ubicarDNI)
        {
            posicion = recorrido;
            break;
        }
        recorrido++;
    }
    return posicion;
}

void ArrayList::Listar(int opcion)
{
    if (opcion == 1)
    { //buscar personas
        for (int i = 0; i < nroPersonas; i++)
        {
            //si logra mutar a persona ////////// tal vez seria si no es ningun derivado
            if (dynamic_cast<Persona *>(aregloPersonas[i]))
            {
                Persona *aux = dynamic_cast<Persona *>(aregloPersonas[i]);
                aux->Mostrar(); //----------------LISTA A TODOS CSMRE------------------------
            }
        }
    }
    else if (opcion == 2)
    { //buscar alumnos
        for (int i = 0; i < nroPersonas; i++)
        {   //si logra mutar a alumno
            if (dynamic_cast<Alumno *>(aregloPersonas[i]))
            {
                Alumno *aux = dynamic_cast<Alumno *>(aregloPersonas[i]);
                aux->Mostrar();
            }
        }
    }
    else if (opcion == 3)
    { //buscar docentes
        for (int i = 0; i < nroPersonas; i++)
        {   //si logra mutar a alumno
            if (dynamic_cast<Docente *>(aregloPersonas[i]))
            {
                Docente *aux = dynamic_cast<Docente *>(aregloPersonas[i]);
                aux->Mostrar();
            }
        }
    }
    else
        cout << "Opcion no identificada" << endl;
}

void ArrayList::Ejecutar(){
    int opcion;
    string ubicarDni;
    do
    {
        Menu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            MenuPersonas();
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            cin.ignore();

            if (opcion == 1)
            { //Agrega persona
                Persona *aux = new Persona();
                aux->Leer();
                aregloPersonas[nroPersonas] = aux;
                nroPersonas++;
            }
            else if (opcion == 2)
            { //Agregar alumno
                Alumno *aux1 = new Alumno();
                aux1->Leer();
                aregloPersonas[nroPersonas] = aux1;
                nroPersonas++;
            }
            else if (opcion == 3)
            { //Agrega Docente
                Docente *aux2 = new Docente();
                aux2->Leer();
                aregloPersonas[nroPersonas] = aux2;
                nroPersonas++;
            }
            else
                cout << "Opcion no identificada" << endl;
            opcion = 0;
            cout << "REGISTRO EXITOSO." << endl;
            break;

        case 2:
            int posicionArray;
            //Buscar en el ArrayList
            cout << "Ingrese el dni: ";
            cin >> ubicarDni;
            //Ubicar personas
            posicionArray = Ubicar(ubicarDni);
            if (posicionArray == -1)
                cout << "Persona no ubicada" << endl;
            else
            {
                cout << "Persona ubicada" << endl;
                aregloPersonas[posicionArray]->Mostrar(); //MUTAR AL TIPO DE DATO QUE SE AGREGO //
            }
            break;

        case 3:
            //Listar por tipo
            MenuPersonas();
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            cin.ignore();
            Listar(opcion);
            break;

        case 4:
            //Eliminar personas
            break;

        default:
            break;
        }

    } while (opcion < 5);
}