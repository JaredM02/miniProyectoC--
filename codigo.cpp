/*
MiniProyecto en C++
Sistema de registro de notas
Autor: Martin Correa
Fecha: 21 de marzo del 2026
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

//Firmas de funciones a utiliar:
void mostrarMenu();
void registroDatos(string nombres[], double notas[], int &cantidad);

int main (){
    //Declaracion de variables necesarias para realizar los procesos - Arreglos para guardar la informacion 
    string nombres[50];
    double notas[50];
    // Esta variable lleva el conteo de registros reales y sirve como indice para el proximo espacio libre
    int cantidadActual = 0;
    //Variable que va a leer lo que el usuario elija del menu
    int opcion;
    do{
        mostrarMenu();
        cin >> opcion;
        if (opcion < 1 || opcion > 8 ){

            cout << "Opcion invalida. Ingrese nuevamente " << endl;
            
        } 

        switch (opcion){
        
        case 1:

            registroDatos(nombres, notas, cantidadActual);

            
        }











    }while (opcion != 8);


    return 0;

}
void mostrarMenu(){
    
    cout << "===== SISTEMA DE GESTION DE NOTAS PRO =====" << endl;
    cout << "1. INGRESE AL REGISTRO DE DATOS " << endl;
    cout << "2. VER LISTA DE ESTUDIANTES Y NOTAS " << endl;
    cout << "3. VER ESTADISTICAS Y CONTEO  " << endl;
    cout << "4. CUADRO DE HONOR " << endl;
    cout << "5. BUSCAR ALUMNO POR NOMBRE "<< endl;
    cout << "6. ELIMINAR ULTIMO REGISTRO " << endl;
    cout << "7. BORRAR TODOS LOS DATOS " << endl;
    cout << "8. Salir " << endl;
    cout << "Selecciones una opcion " << endl;

}

void registroDatos(string nombres[], double notas[], int &cantidad){

    //Validacion de la cantidad de estudiantes a registrar, mientras la cantidad seleccionada sea menor a 1 o mayor a 20
    do {
        cout << "Ingrese la cantidad de estudiantes a registrar (1-50): ";
        cin >> cantidad;
        if (cantidad < 0 || cantidad > 50 ){
            cout << "Rango no valido. Intente nuevamente. " << endl;
        }
    } while (cantidad < 1 || cantidad > 50); 

    //Bucle for para ingresar los nombres y guardarlas en el arreglo

 
}
