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
        // Escudo para que el menu no se rompa.
        // cin >> opcion devuelve "false" si el usuario mete una letra
        while (!(cin >> opcion)) {
            cout << "ERROR: Seleccione una opcion valida (1-8): ";
            // Limpia el estado de error 
            cin.clear(); 
            // Borra la letra que causo el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
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
    //Declaro vairable para operar
    int cantidadNueva;
    //Bucle para el ingreso de la cantidad de datos a querer ingresar.
    do {
        cout << "Ingrese la cantidad de estudiantes a registrar (Espacio disponible: " << 50 - cantidad << "): ";
        
        //Escudo para que cuando ingrese una letra en numero de estudiantes, el programa no se rompa.
        while (!(cin >> cantidadNueva)) {
            cout << "ERROR: Por favor ingrese un NUMERO entero: ";
            // Limpia el estado de error
            cin.clear(); 
            // Borra la letra que causo el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //Validacion de entrada
        if (cantidadNueva < 1 || (cantidad + cantidadNueva) > 50) {
            cout << "Error: No hay espacio suficiente o cantidad invalida." << endl;
        }
    } while (cantidadNueva < 1 || (cantidad + cantidadNueva) > 50);
    // cin.ignore() borra el "Enter" que dejo el ultimo cin >>
    cin.ignore();
    // Define el nuevo tope del arreglo sumando los que ya existían más los nuevos.
    int limite = cantidad + cantidadNueva;
    
    // El bucle inicia en 'cantidad' para no sobreescribir los alumnos previos
    // y avanza hasta el nuevo 'limite' calculado.
    for (int i = cantidad; i < limite; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        // getline lee toda la linea incluyendo espacios
        getline(cin, nombres[i]);

        //Bucle para ingresar notas con la validacion.
        do {
            cout << "Nota (0-10): ";
            
            //Escudo para la nota (EVITA LETRAS)
            while (!(cin >> notas[i])) {
                cout << "ERROR: Ingrese una calificacion numerica (0-10): ";
                // Limpia el estado de error
                cin.clear();
                // Borra la letra que causo el error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            //Validacion para las notas
            if (notas[i] < 0 || notas[i] > 10) {
                cout << "Nota invalida. Intente de nuevo." << endl;
            }
        } while (notas[i] < 0 || notas[i] > 10);
        
        // cin.ignore() borra el "Enter" que dejo el ultimo cin >>
        cin.ignore();
    }

    cantidad = cantidad + cantidadNueva;
    cout << "Registros agregados con exito." << endl;
}

void reporteGeneral(string nombres[], double notas[], int cantidad){

    //Nos aseguramos que existan estudiantes y no dejar espacios vacios
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl; 
        return;
    }
    cout << "--- Listado de Estudiantes ---" << endl;

    //Bucle necesario para mostrar los estudiantes y sus notas de manera ordenada, por lo tal , tambien ocupamos el i+1
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}

void estadisticasyConteo(double notas[], int cantidad){
    //Nos aseguramos que existan o no estudiantes.
    if (cantidad == 0){
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    //Declaramos vairables a utilizar para operar.
    int apr = 0, sup = 0, rep = 0;
    double suma = 0;
    //Bulce para contar la cantidad de estudiantes aprobados/reprobados/supletorios
    for (int i = 0; i < cantidad; i++) {
        suma = suma + notas[i];
        if (notas[i] >= 7) apr = apr + 1;
        else if (notas[i] >= 5) sup = sup + 1;
        else rep = rep + 1;
    }
    //Mensaje en pantalla
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
    //Mensaje en pantalla
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

    //Bucle para mostrar los estudiantes del cuadro de honor.
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
            //Declaro variable para saber si rep, apro, supl con su condicion especifica.
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
        //Se muestra en pantalla el error que pudo cometer el usuario.
        cout << "Error: El estudiante '" << buscado << "' no esta en la lista." << endl;
        cout << "Asegurese de usar mayusculas, minusculas y espacios correctamente." << endl;
    }
}

void eliminarEstudiante(string nombres[], double notas[], int &cantidad) {
    //Escudo de seguridad
    if (cantidad == 0) {
        //Se muestra en pantalla.
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

            //Se mostrara en pantalla el resultado.

            cout << "Estudiante eliminado exitosamente." << endl;
            // Salimos de la función
            return; 
        }
    }

    // Si terminó el for y no entró al if:
    cout << "No se encontro al estudiante." << endl;
}

void borrarDatos(int &cantidad) {
    //Nos aseguramos que existan estudiantes o no
   if (cantidad == 0) {
        //Se muestra en pantalla
        cout << "El sistema ya esta vacio." << endl;
        return;
    }
    //Declaro variable para confirmar una accion 
    char confirmar;
    cout << "ESTA ACCION NO SE PUEDE DESHACER. Borrar todo? (PRESIONE s para CONFIRMAR o n para ANULAR OPERACION): ";
    cin >> confirmar;

    //Condicion para detectar si el usuario realmente quiere borrar datos o no.

    if (confirmar == 's' || confirmar == 'S') {
        //Se resetean los datos a 0 para poder ingresar nueva informacion.
        cantidad = 0;
        //Se muestra en pantalla
        cout << "Sistema vacio. Registros invalidados." << endl;
    } else {
        //Se muestra en pantalla.
        cout << "Operacion cancelada." << endl;
    }
}