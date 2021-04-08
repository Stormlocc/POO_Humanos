#include <iostream>
#include "Persona.h"
#include "Alumno.h"
#include "Docente.h"
#include <string>
using namespace std;

static int Ubicar(Persona **array, string _dni, int index){
    //
    //
    //Persona *aux = new Persona();
    Persona *aux ;

    int posicion = -1;
    int recorrido = 0;
    while ( recorrido <index ){
        aux= array[recorrido];//Mutacion de array a objeto
        //cout<<"La persona que esat comparando el dni es "<<aux->GetNombre()<<endl;

        if(aux->GetDni() == _dni){
            posicion = recorrido;
        }
        recorrido++;
    }
    return posicion;
}
/*
        public static int BusquedaLineal(int[] array, int n, int objetivo)
        {
            int posicion = -1;
            int i = 0;
            while(i< array.Length)
            {
                if (array[i] == objetivo)
                {
                    posicion = i;
                    break;
                }
                i++;
            }
            return posicion;
        }
*/


static void MenuPersonas(){
    cout<<"1) Agregar Persona"<<endl;
    cout<<"2) Agregar Alumno"<<endl;
    cout<<"3) Agregar Docente"<<endl;
}

static void Menu(){
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout << "++++++++++++++++MENU DE PROGRAMA++++++++++++++++++++"<<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout << "1-> Agregar"<<endl;
    cout << "2-> Ubicar"<<endl;
    cout << "3-> Eliminar"<<endl;
    cout << "4-> SALIR--------------"<<endl;
}

int main(){
    cout<<"=================+++++++++++++++++++++++++++++++++++==============="<<endl;
    cout<<"=================PROGRAMA DE HERENCIA Y POLIMORFISMO==============="<<endl;
    cout<<"=================+++++++++++++++++++++++++++++++++++==============="<<endl;

    //Intanciamos arreglo de objectos
    Persona **aregloPersonas = new Persona *[100];
    int nroPeronas = 0; 
    int opcion;
    do
    {
        /* code */
        Menu();
        cout<<"Ingrese su opcion: ";
        cin>>opcion;
        cin.ignore();
        string dariela;
        int anthony;

        switch(opcion)
        {
        case 1:
            MenuPersonas();
            cout<<"Ingrese su opcion: ";
            cin>>opcion;   
            cin.ignore();

            if(opcion ==1){//Agrega pernsa
                Persona *aux = new Persona();
                aux->Leer();
                aregloPersonas[nroPeronas] = aux;
                nroPeronas++;
            }  
            else if(opcion ==2){//Agregar alumno
            //DUNAMIC CAST
                Alumno *aux1 = new Alumno();
                aux1->Leer();
                aregloPersonas[nroPeronas] = aux1;
                nroPeronas++;
            }  
            else if(opcion ==3){//Agrega Docente
            //DUNAMIC CAST
                Docente *aux2 = new Docente();
                aux2->Leer();
                aregloPersonas[nroPeronas] = aux2;
                nroPeronas++;
            }  
            else
                cout<<"Opcion no identificada"<<endl;
                opcion =0;
            cout<<"Ya estas agregado manite"<<endl;
            
            break;
        
        case 2:
            //BUSCAR EM EL array list
            cout<<"Ingrese el dni: ";
            cin>>dariela;   
            //Ubicar personas
            anthony = Ubicar(aregloPersonas,dariela,nroPeronas);
            if(anthony==-1)
            {
                cout<<"Persona no ubicada"<<endl;
            }
            else{
                cout<<"Persona ubicada"<<endl;
                aregloPersonas[anthony]->Mostrar();
            }
                



            break;
        
        case 3:
            //Eliminar personas


        default:
            break;
        }


        
    } while (opcion<4);

            //@@@@@@@@@@@@@@@@ GIt HUB @@@@@@@@@@@@@@@

    //VERSION 1
    //ejecutar opciones aqui dentro

    //VERSION 2
    // CREAR una clase de donde se pueda ejecutar funciones


    //Estas deben tener el dynamic cast osea mutacion
}