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
void buscarEstudianteDetalle(string nombres[], double notas[], int cantidad);
void eliminarEstudiante(string nombres[], double notas[], int &cantidad);
void borrarDatos(int &cantidad);
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

        case 5:

            buscarEstudianteDetalle(nombres, notas, cantidadActual);

            break;

        case 6:

            eliminarEstudiante(nombres, notas, cantidadActual);

            break;

        case 7:

            borrarDatos(cantidadActual);

            break;

        case 8:

            cout << "Saliendo del programa..." << endl;

            break;
        }

    }while (opcion != 8);

    return 0;
}
void mostrarMenu(){
    
    cout << "===== SISTEMA DE GESTION DE NOTAS PRO =====" << endl;
    cout << "1. INGRESE AL REGISTRO DE DATOS " << endl;
    cout << "2. VER LISTA DE ESTUDIANTES Y NOTAS " << endl;
    cout << "3. VER PROMEDIO GENERAL Y CONTEO DE APROBADOS/REPROBADOS/SUPLETORIOS " << endl;
    cout << "4. CUADRO DE HONOR " << endl;
    cout << "5. BUSCAR ALUMNO POR NOMBRE "<< endl;
    cout << "6. ELIMINAR ESTUDIANTE" << endl;
    cout << "7. BORRAR TODOS LOS DATOS " << endl;
    cout << "8. Salir " << endl;
    cout << "Selecciones una opcion " << endl;
}

void registroDatos(string nombres[], double notas[], int &cantidad) {
    int cantidadNueva;

    //Validacion de la cantidad de estudiantes a registrar, mientras la cantidad seleccionada sea menor a 1 o mayor a 50
    do {
        cout << "Ingrese la cantidad de estudiantes a registrar. (Espacio disponible: " << 50 - cantidad << "): ";
        cin >> cantidadNueva;

        if (cantidadNueva < 1 || (cantidad + cantidadNueva) > 50) {
            cout << "Error: No hay espacio suficiente o cantidad invalida." << endl;
        }
    } while (cantidadNueva < 1 || (cantidad + cantidadNueva) > 50);

        //Se limpia el enter que se da
    cin.ignore();

    // El bucle empieza desde donde se quedó la cantidad anterior
    // El límite es la suma de lo que había + lo nuevo
    int limite = cantidad + cantidadNueva;
    
    //Bucle for para ingresar los nombres/ notas con su validacion correspondiente y guardarlas en el arreglo
    for (int i = cantidad; i < limite; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        getline(cin, nombres[i]);

        do {
            cout << "Nota (0-10): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 10) {
                cout << "Nota invalida." << endl;
            }
        } while (notas[i] < 0 || notas[i] > 10);
        
        cin.ignore();
    }

    // ACTUALIZAMOS la cantidad real que vive en el main
    cantidad = cantidad + cantidadNueva;
    cout << "Registros agregados con exito." << endl;
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
    //Si aun no se registran estudiantes
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

void buscarEstudianteDetalle(string nombres[], double notas[], int cantidad) {
    //Si aun no se registran estudiantes
   if (cantidad == 0){
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    //Declaracion de variable para la nueva funcion Y pedir en pantalla
    string buscado;
    cout << "Nombre a buscar (escriba el nombre exacto): "; 
    cin.ignore(); 
    getline(cin, buscado);

    //Declaracion de Booleano necesario para que el programa encuentre el estudiante.
    bool encontrado = false; // Variable para saber si lo hallamos

    //Bucle para realizar los calculos y mostrar en pantalla los resultados de las condiciones.
    for (int i = 0; i < cantidad; i++) {
        //Condiciones para saber el estado de los estudiantes y encontrarlos.
        if (nombres[i] == buscado) {
            //Declaro variable para saber si rep, apro, supl.
            string estado;

            if (notas[i] >= 7) {
                estado = "APROBADO";
            } else if (notas[i] >= 5) {
                estado = "SUPLETORIO";
            } else {
                estado = "REPROBADO";
            }

            // Se mostrara en pantalla el resultado
            cout << "--- RESULTADO DE BUSQUEDA ---" << endl;
            cout << "Estudiante : " << nombres[i] << endl;
            cout << "Nota       : " << notas[i] << endl;
            cout << "Estado     : " << estado << endl;
            cout << "-----------------------------" << endl;
            
            encontrado = true;
            return; // Salimos de la función porque ya lo encontramos
        }
    }

    // SI EL BUCLE TERMINA Y NO ENCONTRAMOS NADA:
    if (encontrado == false) {
        cout << "Error: El estudiante '" << buscado << "' no esta en la lista." << endl;
        cout << "Asegurese de usar mayusculas, minusculas y espacios correctamente." << endl;
    }
}

void eliminarEstudiante(string nombres[], double notas[], int &cantidad) {
    //Escudo de seguridad
    if (cantidad == 0) {
        cout << "No hay estudiantes para eliminar." << endl;
        return;
    }
    //Declaracion de variable e ingreso de cout para pedir en pantalla el estudiante que el usuario desea eliminar.
    string buscado;
    cout << "Ingrese el nombre exacto a eliminar: ";
    cin.ignore();
    getline(cin, buscado);

    // Buscamos al estudiante con un for simple 
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == buscado) {
            
            // Reemplazamos al que queremos borrar con los datos del ULTIMO de la lista
            nombres[i] = nombres[cantidad - 1];
            notas[i] = notas[cantidad - 1];

            // Restamos 1 a la cantidad total
            cantidad = cantidad - 1;

            cout << "Estudiante eliminado exitosamente." << endl;
            return; // Salimos de la función
        }
    }

    // Si terminó el for y no entró al if:
    cout << "No se encontro al estudiante." << endl;
}

void borrarDatos(int &cantidad) {
    //Nos aseguramos que existan estudiantes o no
   if (cantidad == 0) {
        cout << "El sistema ya esta vacio." << endl;
        return;
    }
    //Declaro variable para confirmar una accion 
    char confirmar;
    cout << "ESTA ACCION NO SE PUEDE DESHACER. ¿Borrar todo? (PRESIONE s para CONFIRMAR o n para ANULAR OPERACION): ";
    cin >> confirmar;

    //Condicion para detectar si el usuario realmente quiere borrar datos o no.

    if (confirmar == 's' || confirmar == 'S') {
        cantidad = 0;
        cout << "Sistema vacio. Registros invalidados." << endl;
    } else {
        cout << "Operacion cancelada." << endl;
    }
}