# Sistema de Gestión de Notas PRO (C++)

**Autor:** Martin Correa  
**Fecha:** 21 de marzo de 2026

## Descripción

Este proyecto es una aplicación de consola desarrollada en **C++ estructurado** diseñada para la gestión académica de estudiantes. El sistema permite el registro dinámico de alumnos, el control de sus calificaciones y la generación de reportes estadísticos automáticos.

El enfoque del código se centra en la **robustez y la validación**, implementando técnicas avanzadas de manejo para evitar errores de entrada (letras en campos numéricos) y asegurar la integridad de la información mediante arreglos.

## Objetivo

El objetivo de este proyecto es resolver la necesidad de un control automatizado de notas en entornos educativos, buscando:
* Optimizar el registro de datos sin sobreescribir información previa.
* Automatizar el cálculo de promedios y estados académicos (Aprobado/Reprobado).
* Garantizar una experiencia de usuario fluida mediante validaciones de entrada de datos.

## Contenido / Funcionalidades

El sistema cuenta con las siguientes funciones principales:

1.  **Registro y Adición Dinámica:** Permite ingresar nuevos alumnos sumándolos a los ya existentes hasta un límite de 50 registros.
2.  **Reporte General:** Muestra la lista completa de estudiantes ingresados por el usuario.
3.  **Análisis Estadístico:** Calcula el promedio grupal y realiza un conteo automático de alumnos Aprobados, en Supletorio y Reprobados.
4.  **Cuadro de Honor (TOP 3):** Algoritmo de búsqueda que extrae los tres mejores promedios del curso.
5.  **Búsqueda Detallada:** Localiza un estudiante por su nombre exacto y muestra su estado académico.
6.  **Eliminación Segura:** Permite remover registros individuales desplazando los datos de forma eficiente.
7.  **Borrado Total con Confirmación:** Función de seguridad para reiniciar el sistema tras una validación del usuario.
8.  **Opcion de salida:** Permite al usuario salir del menu cuando este lo requiera.

## Estructura

El proyecto está organizado de la siguiente manera:
* **Librerias:** Uso de las librerias necesarias para una ejecucion correcta del codigo.
* **Prototipos/Firmas:** Declaración inicial de funciones para modularización.
* **Función Principal (main):** Control del flujo mediante un menú interactivo y estructura `do-while` / `switch`.
* **Módulos de Función:** Implementación independiente de cada funcionalidad (Lógica de negocio).
* **Validaciones:** Bloques de código dedicados a la limpieza del búfer (`cin.clear` y `cin.ignore`).

## Herramientas utilizadas

* **Lenguaje:** C++ (Estándar ISO).
* **IDE:** Visual Studio Code / Dev-C++.
* **Compilador:** GCC/G++.
* **Librerías:** `<iostream>`, `<string>`, `<limits>`.
* **Control de Versiones:** Git & GitHub.

## Autor

Proyecto desarrollado por **Martin Correa** como parte del proceso de aprendizaje en lógica de programación y C++ estructurado.

## Instrucciones de Compilación y Ejecución

Para ejecutar este proyecto en su ordenador, siga estos pasos:

1. **Requisitos Previos:** Asegúrese de tener instalado un compilador de C++ (como GCC/MinGW) o un IDE (como VS Code, Dev-C++ o Code::Blocks).
2. **Compilación:** * Si utiliza la terminal, ejecute el comando: 
     `g++ codigo.cpp -o codigo`
3. **Ejecución:**
   * En Windows: `./codigo`
4. **Uso:** Siga las instrucciones del menú interactivo en la consola para navegar por las 8 opciones del sistema.

## Observaciones

* **Resiliencia:** El programa utiliza `numeric_limits` para prevenir bucles infinitos ante ingresos de datos no numéricos en el menú y las notas.
* **Memoria:** Se utilizan arreglos paralelos (`nombres[]` y `notas[]`) vinculados mediante un índice común, garantizando que la relación Estudiante-Calificación sea siempre correcta.
* **Escalabilidad:** El código está estructurado de forma modular, lo que facilita la adición de futuras funcionalidades.

El proyecto fue realizado de manera secuencial y ordenada, compilando, ejecutando el codigo y corrigiendo errores. Todo ello, con el objetivo de desarrollar una mejor lógica al desarrollar codigo en el lenguaje de C++.
