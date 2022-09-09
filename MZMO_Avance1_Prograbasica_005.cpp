// MZMO_Av1_Prograbasica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h> //para cambiar el color de la pantalla

using namespace std;
int main()
{
    int numarticulo, anodelanzamiento, opcion;
    float precio_unitario, impuesto, total;
    string nombrejuego, caracteristicas, clasificacion, descripcion, genero;

    system("color 4f");
    cout << "\t ***GAMESTORE EL SOMBRERO NEGRO*** \n";
    cout << "\n";
    cout << " 1.-Agregar Articulo \n";
    cout << " 2.-Modificar Articulo\n";
    cout << " 3.-Eliminar Articulo\n";
    cout << " 4.-Articulos vigentes\n";
    cout << " 5.-Limpiar Pantalla\n";
    cout << " 6.-Salir\n";
    cout << "\n";
    cin >> opcion;

    switch (opcion)
    {
    case 1: //Agregar Articulo
        cout << "\t ***Agregar articulo*** \n";
        cout << "\n";
        cout << "Ingrese el numero de articulo \n";
        cin >> numarticulo;
        cout << "ingrese el nombre del articulo\n";
        cin.ignore();//ignora el primer espacio 
        getline(cin, nombrejuego); //permite ejecutar los espacios en la variable
        cout << "ingrese el año de lanzamiento del articulo\n";
        cin.ignore();
        getline(cin, anodelanzamiento);
        cout << "ingrese la clasificacion del articulo\n";
        cin.ignore();
        getline(cin, clasificacion);
        cout << "ingrese la descripcion del articulo\n";
        cin.ignore();
        getline(cin, descripcion);
        cout << "ingrese el genero del articulo\n";
        cin.ignore();
        getline(cin, genero);
        cin.ignore();
        cout << "ingrese el precio unitario del articulo\n";
        getline(cin, precio_unitario);
        total = precio_unitario + (precio_unitario * 0.16);
        cout << "El total es: " << total;
        return main();
        break;

    case 2: //Modificar Articulo
        break;

    case 3://Eliminar Articulo
        break;

    case 4: //Articulos vigentes
        break;

    case 5: //Limpiar Pantalla
        system("cls"); //clean  se utiliza en web 
        return main();
        break;

    case 6: //salir
        cout << "Gracias por utilizar el programa \n";
        break;

    default:
        cout << "ingrese una opcion correcta \n";
        return main();

    }

}



