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
void reporteGeneral(string nombres[], double notas[], int cantidad);
void estadisticasyConteo(double notas[], int cantidad);
void cuadroHonor(string nombres[], double notas[], int cantidad);
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

            break;

        case 2:

            reporteGeneral(nombres, notas, cantidadActual);

            break;

        case 3:

            estadisticasyConteo(notas, cantidadActual);

            break;

        case 4:

            cuadroHonor(nombres, notas, cantidadActual);

            break;
        }











    }while (opcion != 8);


    return 0;

}
void mostrarMenu(){
    
    cout << "===== SISTEMA DE GESTION DE NOTAS PRO =====" << endl;
    cout << "1. INGRESE AL REGISTRO DE DATOS " << endl;
    cout << "2. VER LISTA DE ESTUDIANTES Y NOTAS " << endl;
    cout << "3. VER ESTADISTICAS Y CONTEO DE APROBADOS/REPROBADOS/SUPLETORIOS " << endl;
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
        if (cantidad < 1 || cantidad > 50 ){
            cout << "Rango no valido. Intente nuevamente. " << endl;
        }
    } while (cantidad < 1 || cantidad > 50); 
    //Se limpia el enter que se da 
    cin.ignore();
        //Bucle for para ingresar los nombres y guardarlas en el arreglo
    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
       //getline se usa para leer la linea completa.
        getline (cin, nombres[i]);
         
        //Bucle do-while para validar asegurando que estemos dentro del rango y un if para mostrar un error de nota fuera de rango y 
        //permita al usuario volver a ingresar la nota.
        do {
            cout << "Nota (0-10): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 10) { 
                cout << "Nota invalida. La calificacion debe estar entre 0 y 10." << endl;
            }
        } while (notas[i] < 0 || notas[i] > 10);
        cin.ignore();
    }

}

void reporteGeneral(string nombres[], double notas[], int cantidad){

    //Nos aseguramos que existan estudiantes y no dejar espacios vacios
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl; 
        return;
    }
    cout << "---Listado de Estudiantes ---" << endl;

    //Bucle necesario para mostrar los estudiantes y sus notas de manera ordenada, por lo tal , tambien ocupamos el i+1
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}

void estadisticasyConteo(double notas[], int cantidad){
    if (cantidad == 0) return;
    int apr = 0, sup = 0, rep = 0;
    double suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma = suma + notas[i];
        if (notas[i] >= 7) apr = apr + 1;
        else if (notas[i] >= 5) sup = sup + 1;
        else rep = rep + 1;
    }
    cout << "--- RESUMEN ---" << endl;
    cout << "Promedio Grupal: " << suma / cantidad << endl;
    cout << "Aprobados: " << apr << " | Supletorios: " << sup << " | Reprobados: " << rep << endl;
}
    
void cuadroHonor(string nombres[], double notas[], int cantidad){

   if (cantidad == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    cout << "=======================================" << endl;
    cout << "      CUADRO DE HONOR: TOP 3           " << endl;
    cout << "=======================================" << endl;

    // Todos empiezan en "falso" para no repetir al mismo alumno y "tacha" cuando el programa ya lo lea.
    bool yaMostrado[50] = {false}; 

    // Declaracion de la variable puestosAMostrar y una condicion para el TOP3
    int puestosAMostrar;

    if (cantidad < 3) {
        puestosAMostrar = cantidad; // Si hay 1 o 2, mostramos 1 o 2
    } else {
        puestosAMostrar = 3; // Si hay 3 o más, mostramos el top 3
    }

    for (int puesto = 1; puesto <= puestosAMostrar; puesto++) {
        //Declaracion de variables inicializandolos en nota imposible 
        double notaMasAlta = -1;
        int indiceMejor = -1;

        // Buscamos en todo el arreglo quién tiene la nota más alta 
        // y que NO haya sido mostrado todavía
        for (int i = 0; i < cantidad; i++) {
            if (notas[i] > notaMasAlta && yaMostrado[i] == false) {
                notaMasAlta = notas[i];
                indiceMejor = i;
            }
        }

        // Si encontramos a alguien, lo mostramos y lo "marcamos"
        if (indiceMejor != -1) {
            cout << "PUESTO " << puesto << ": " << nombres[indiceMejor] 
                 << " | Nota: " << notas[indiceMejor] << endl;
            yaMostrado[indiceMejor] = true; // Marcamos para que no vuelva a salir
        }
    }
    cout << "=======================================" << endl;
    
}



