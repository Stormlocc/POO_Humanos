#include <iostream>
#include "Persona.h"
#include "Alumno.h"
#include "Docente.h"
#include <string>
using namespace std;

static void Listar(Persona **aregloPersonas, int nroPersonas, int opcion)
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
        {
            //si logra mutar a alumno
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
        {
            //si logra mutar a alumno
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

static int Ubicar(Persona **array, string _dni, int index)
{
    Persona *aux;
    int posicion = -1;
    int recorrido = 0;
    while (recorrido < index)
    {
        aux = array[recorrido]; //Mutacion de array a objeto
        if (aux->GetDni() == _dni)
        {
            posicion = recorrido;
        }
        recorrido++;
    }
    return posicion;
}

static void MenuPersonas()
{
    cout << "++++++++++++++++ TIPO DE PERSONA ++++++++++++++++++++" << endl;
    cout << "1) Persona" << endl;
    cout << "2) Alumno" << endl;
    cout << "3) Docente" << endl;
}

static void Menu()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++++++++++++++++MENU DE PROGRAMA++++++++++++++++++++" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "1-> Agregar" << endl;
    cout << "2-> Ubicar" << endl;
    cout << "3-> Listar" << endl;
    cout << "4-> Eliminar" << endl;
    cout << "5-> SALIR--------------" << endl;
}

int main()
{
    cout << "=================+++++++++++++++++++++++++++++++++++===============" << endl;
    cout << "=================PROGRAMA DE HERENCIA Y POLIMORFISMO===============" << endl;
    cout << "=================+++++++++++++++++++++++++++++++++++===============" << endl;

    //Intanciamos arreglo de objectos
    Persona **aregloPersonas = new Persona *[100];
    int nroPeronas = 0;
    int opcion;
    do
    {
        /* code */
        Menu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore();
        string ubicarDni;
        int posicionArray;

        switch (opcion)
        {
        case 1:
            MenuPersonas();
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            cin.ignore();

            if (opcion == 1)
            { //Agrega pernsa
                Persona *aux = new Persona();
                aux->Leer();
                aregloPersonas[nroPeronas] = aux;
                nroPeronas++;
            }
            else if (opcion == 2)
            { //Agregar alumno
                //DUNAMIC CAST
                Alumno *aux1 = new Alumno();
                aux1->Leer();
                aregloPersonas[nroPeronas] = aux1;
                nroPeronas++;
            }
            else if (opcion == 3)
            { //Agrega Docente
                //DUNAMIC CAST
                Docente *aux2 = new Docente();
                aux2->Leer();
                aregloPersonas[nroPeronas] = aux2;
                nroPeronas++;
            }
            else
                cout << "Opcion no identificada" << endl;
            opcion = 0;
            cout << "REGISTRO EXITOSO." << endl;
            break;

        case 2:
            //Buscar en el ArrayList
            cout << "Ingrese el dni: ";
            cin >> ubicarDni;
            //Ubicar personas
            posicionArray = Ubicar(aregloPersonas, ubicarDni, nroPeronas);
            if (posicionArray == -1)
            {
                cout << "Persona no ubicada" << endl;
            }
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
            Listar(aregloPersonas, nroPeronas, opcion);
            break;

        case 4:
            //Eliminar personas
            break;

        default:
            break;
        }

    } while (opcion < 5);

    //@@@@@@@@@@@@@@@@ GIt HUB @@@@@@@@@@@@@@@

    //VERSION 1
    //ejecutar opciones aqui dentro

    //VERSION 2
    // CREAR una clase de donde se pueda ejecutar funciones

    //Estas deben tener el dynamic cast osea mutacion
}