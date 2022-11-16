// MZMO_PIA_Prograbasica_Pfinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <locale.h> // consola para poner en español
#include <windows.h> // consola para poner en español
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h> 
#include <fstream>
#include <stdlib.h>

using namespace std;

//voids 
void alta();
void eliminar();
void lista();
void modificar();
void archivo();

//variables
int* numarticulo, * item, * anodelanzamiento, desicion, n = 1, registros;
float* precio_unitario, * total, * iva;
string* nombrejuego, * caracteristicas, * clasificacion, * descripcion, * genero;


int main()
{
    setlocale(LC_ALL, "Spanish"); //para poner en español 1
    SetConsoleCP(1252); //para poner en español 2
    SetConsoleOutputCP(1252); //para poner en español 3
    int opcion;
    string clasificacion2, genero2, buscar, buscar2;

    system("color 5f"); //Para cambiar color de pantalla.
    printf("\t *GAMESTORE EL SOMBRERO NEGRO* \n");
    printf("\n");
    printf(" 1.-Agregar Articulo \n");
    printf(" 2.-Lista de Articulos\n");
    printf(" 3.-Modificar Articulo\n");
    printf(" 4.-Eliminar Articulo\n");
    printf(" 5.-Limpiar Pantalla\n");
    printf(" 6.-Salir\n");
    printf("\n");
    scanf_s("%d", &opcion);

    switch (opcion) {

    case 1: //Agregar articulo
        alta(); //void para agregar articulos.
        system("pause");
        return main();
        break;

    case 2: //Lista aticulos
        lista(); //void para mostrar listas
        system("pause");
        return main();
        break;

    case 3: //Modificar
        modificar(); //void para modificar
        system("pause");
        return main();
        break;

    case 4: //Eliminar
        eliminar();
        system("pause");
        return main();
        break;

    case 5: //Limpiar pantalla
        system("cls"); //clean  se utiliza en web 
        return main();
        break;


    case 6: //Salir
        archivo();
        exit(1);
        system("pause");
        break;



    default:
        cout << "ingrese una opcion correcta \n";
        archivo();
        return main();

    }
}

void alta() {
    printf("Ingrese la cantidad de registros que desea dar de alta: \n");
    scanf_s("%d", &registros);
    if (registros > 0) {
        item = new int[registros];
        anodelanzamiento = new int[registros];
        nombrejuego = new string[registros];
        clasificacion = new string[registros];
        caracteristicas = new string[registros];
        genero = new string[registros];
        descripcion = new string[registros];
        precio_unitario = new float[registros];
        iva = new float[registros];
        total = new float[registros];


        for (int i = 0; i < registros; i++) {
            printf("Ingrese el articulo: \n");
            scanf_s("%d", &item[i]);
            do {
                if (item[i] != item[i - n]) {
                    n = n + 1;
                }
                else {
                    printf("El articulo ya existe \n");
                    printf("Ingrese el articulo: \n");
                    scanf_s("&d", &item[i]);
                }
            } while (n < registros);
            printf(" Ingrese el nombre del articulo:\n");
            cin.ignore();//ignora el primer espacio 
            getline(cin, nombrejuego[i]); //permite ejecutar los espacios en la variable
            printf(" Ingrese el año de lanzamiento del articulo: \n");
            scanf_s("%d", &anodelanzamiento[i]);
            printf(" Ingrese la clasificacion del articulo:\n");
            cin.ignore();
            getline(cin, clasificacion[i]);
            printf(" Ingrese la descripcion del articulo:\n");
            getline(cin, descripcion[i]);
            printf(" Ingrese el genero del articulo:\n");
            getline(cin, genero[i]);
            printf(" Ingrese el precio unitario del articulo:\n");
            scanf_s("%f", &precio_unitario[i]);
            iva[i] = precio_unitario[i] * 0.16;
            total[i] = precio_unitario[i] + iva[i];
            printf(" El total (IVA incluido) es: %f \n", total[i]);
            printf(" El IVA es: %f \n", iva[i]);
            printf("************************\n");
            printf("\n");
            if (i == (registros - 1)) {
                int opp;
                printf("Desea agregar otro registro? \n");
                printf(" 1. Si\n");
                printf(" 2. No\n");
                scanf_s("%d", &opp);
                if (opp == 1) {
                    registros = registros + 1;
                }

            }
        }
    }
    else {
        printf("Se eligio una opcion incorrecta \n");
    }
}

void eliminar() {
    int Eliminar;
    printf("Ingrese el articulo a eliminar \n");
    scanf_s("%d", &Eliminar);

    for (int i = 0; i < registros; i++) {
        if (Eliminar == item[i])
        {
            item[i] = 0;
        }
    }
}

void modificar() {
    //utilizar switch
    int Modificar;
    do {
        printf("Ingrese el num de articulo a modificar: ");
        scanf_s("%d", &Modificar);
    } while (Modificar > 0);
    scanf_s("%d", &Modificar);
    for (int i = 0; i < registros; i++) {
        if (Modificar == item[i]) {
            printf(" Ingrese el nombre del articulo:\n");
            cin.ignore();//ignora el primer espacio 
            getline(cin, nombrejuego[i]); //permite ejecutar los espacios en la variable
            printf(" Ingrese el año de lanzamiento del articulo: \n");
            scanf_s("%d", &anodelanzamiento[i]);
            printf(" Ingrese la clasificacion del articulo:\n");
            cin.ignore();
            getline(cin, clasificacion[i]);
            printf(" Ingrese la descripcion del articulo:\n");
            getline(cin, descripcion[i]);
            printf(" Ingrese el genero del articulo:\n");
            getline(cin, genero[i]);
            printf(" Ingrese el precio unitario del articulo:\n");
            scanf_s("%f", &precio_unitario[i]);
            iva[i] = precio_unitario[i] * 0.16;
            total[i] = precio_unitario[i] + iva[i];
            printf(" El total (IVA incluido) es: %f \n", total[i]);
        }
    }
}

void lista() {
    int opc2;
    string busca;
    printf("\t *** Listas *** \n");
    printf("\n");
    printf(" 1.-Buscar por clasificacion \n");
    printf(" 2.-Buscar por genero \n");
    printf("\n");
    scanf_s("%d", &opc2);

    switch (opc2) {

    case 1:
        printf("Ingrese la clasificacion a buscar \n");
        cin.ignore();
        getline(cin, busca);
        for (int i = 0; i < registros; i++) {
            if (clasificacion[i] == busca) {
                    printf(" Numero del articulo: %d \n", item[i]);
                    printf(" Nombre del articulo: %s \n", nombrejuego[i].c_str());
                    printf(" Ano de lanzamiento: %d \n", anodelanzamiento[i]);
                    printf(" Clasificacion del articulo: %s \n", clasificacion[i].c_str());
                    printf(" Descripcion del articulo: %s \n", descripcion[i].c_str());
                    printf(" Genero del articulo: %s \n", genero[i].c_str());
                    printf(" Precio unitario del articulo: %f \n", precio_unitario[i]);
                    printf(" Total: %f \n", total[i]);
                }
        }
        break;

    case 2:
        printf("Ingrese el genero a buscar \n");
        cin.ignore();
        getline(cin, busca);
        for (int i = 0; i < registros; i++) {
            if (genero[i] == busca) {
                if (item[i] != 0) {
                    printf(" Numero del articulo: %d \n", numarticulo[i]);
                    printf(" Nombre del articulo: %s \n", nombrejuego[i].c_str());
                    printf(" Ano de lanzamiento: %d \n", anodelanzamiento[i]);
                    printf(" Clasificacion del articulo: %s \n", clasificacion[i].c_str());
                    printf(" Descripcion del articulo: %s \n", descripcion[i].c_str());
                    printf(" Genero del articulo: %s \n", genero[i].c_str());
                    printf(" Precio unitario del articulo: %f \n", precio_unitario[i]);
                    printf(" Total: %f \n", total[i]);

                }
            }
        }
        break;

    default:
        printf("Ingrese una opcion correcta");
        return lista();
        break;
    }
}

void archivo() {
    ofstream Archivo;
    string nombre;

    nombre = "Articulos";
    //archivos
    Archivo.open(nombre.c_str(), ios::out);
    //archivos
    if (Archivo.fail()) {
        printf("NO SE GENERO EL ARCHIVO");
        system("pause");
        exit(1);
    }
    //archivos
    Archivo << "\t *** Informacion *** \n";
    for (int i = 0; i < registros; i++) {
        if (item[i] != 0) {
            Archivo << "Articulo: " << item[i] << endl;
            Archivo << "Anio: " << anodelanzamiento[i] << endl;
            Archivo << "Videojuego: " << nombrejuego[i] << endl;
            Archivo << "Clasificacion: " << clasificacion[i] << endl;
        }
    }
    Archivo.close();
}
