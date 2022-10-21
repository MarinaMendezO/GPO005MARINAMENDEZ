// MZMO_Avance 2_Prograbasica_005.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h> //para cambiar el color de la pantalla

using namespace std;

struct juegos {
    int numarticulo, anodelanzamiento;
    float precio_unitario, total, iva;
    string nombrejuego, caracteristicas, clasificacion, descripcion, genero;
}compras[3];

int main() 
{
    int opcion,opc2;
    string clasificacion2, genero2, buscar, buscar2;

    system("color 5f");
    printf("\t *GAMESTORE EL SOMBRERO NEGRO* \n");
    printf("\n");
    printf(" 1.-Agregar Articulo \n");
    printf(" 2.-Lista de Articulos\n");
    printf(" 3.-Modificar Articulo\n");
    printf(" 4.-Eliminar Articulo\n");
    printf(" 5.-Articulos vigentes\n");
    printf(" 6.-Limpiar Pantalla\n");
    printf(" 7.-Salir\n");
    printf("\n");
    cin >> opcion;

    switch (opcion)
    {
    case 1: //Agregar Articulo
        printf("\t ***Agregar articulo*** \n"); 
        printf("\n");
        for (int i = 0; i < 3; i++) { //Captura y guarda por posicion.
            printf(" Ingrese el numero de articulo \n");
            scanf_s("%d", &compras[i].numarticulo);
            printf(" Ingrese el nombre del articulo\n");
            cin.ignore();//ignora el primer espacio 
            getline(cin, compras[i].nombrejuego); //permite ejecutar los espacios en la variable
            printf(" Ingrese el ano de lanzamiento del articulo \n");
            scanf_s("%d", &compras[i].anodelanzamiento);
            printf(" Ingrese la clasificacion del articulo\n");
            cin.ignore();
            getline(cin, compras[i].clasificacion);
            printf(" Ingrese la descripcion del articulo\n");
            getline(cin, compras[i].descripcion);
            printf(" Ingrese el genero del articulo\n");
            getline(cin, compras[i].genero);
            printf(" Ingrese el precio unitario del articulo\n");
            scanf_s("%f", &compras[i].precio_unitario);
            compras[i].iva = compras[i].precio_unitario * 0.16;
            compras[i].total = compras[i].precio_unitario + compras[i].iva;
            printf(" El total (IVA incluido) es: %f \n", compras[i].total);
            printf(" El IVA es: %f \n", compras[i].iva);
            printf("************************\n");
            printf("\n");

        }
        return main();
        break;

    case 2: //Lista de Articulos
        printf("\t *** Lista de Articulos *** \n");
        printf("\n");
        printf(" 1.-Ver todos los articulos \n");
        printf(" 2.-Buscar articulos por clasificacion\n");
        printf(" 3.-Buscar articulos por genero\n");
        printf("\n");
        scanf_s("%d", &opc2);

        switch (opc2)
        {
        case 1:
            printf("\t *** Lista de Articulos*** \n");
            printf("\n");
            for (int i = 0; i < 3; i++) {
                printf(" Numero del articulo: %d \n", compras[i].numarticulo);
                printf(" Nombre del articulo: %s \n", compras[i].nombrejuego.c_str());
                printf(" Ano de lanzamiento: %d \n", compras[i].anodelanzamiento);
                printf(" Clasificacion del articulo: %s \n", compras[i].clasificacion.c_str());
                printf(" Descripcion del articulo: %s \n", compras[i].descripcion.c_str());
                printf(" Genero del articulo: %s \n", compras[i].genero.c_str());
                printf(" Precio unitario del articulo: %f \n", compras[i].precio_unitario);
                printf(" Total: %f \n", compras[i].total);
                printf("************************\n");
                printf("\n");
            }
            return main();
            break;

        case 2:

            printf("\t ***Articulos por clasificacion*** \n");
            printf("\n");
            printf("Ingrese la clasificacion: \n");
            cin.ignore();
            getline(cin, buscar);
                printf("Ingrese la clasificacion: \n");
                cin.ignore();
                getline(cin, buscar);
                for (int i = 0; i < 3; i++) {
                    if (buscar == compras[i].clasificacion) {
                        printf(" Numero del articulo: %d \n", compras[i].numarticulo);
                        printf(" Nombre del articulo: %s \n", compras[i].nombrejuego.c_str());
                        printf(" Ano de lanzamiento: %d \n", compras[i].anodelanzamiento);
                        printf(" Clasificacion del articulo: %s \n", compras[i].clasificacion.c_str());
                        printf(" Descripcion del articulo: %s \n", compras[i].descripcion.c_str());
                        printf(" Genero del articulo: %s \n", compras[i].genero.c_str());
                        printf(" Precio unitario del articulo: %f \n", compras[i].precio_unitario);
                        printf(" Total: %f \n", compras[i].total);
                        printf("************************\n");
                        printf("\n");
                    }
                    else {
                        printf(" No hay Articulos de la clasificacion solicitada. \n");
                        return main();
                        break;
                    }
                }
            return main();
            break;

        case 3:
            printf("\t ***Articulos por genero*** \n");
            printf("\n");
            printf("Ingrese el genero: \n");
            cin.ignore();
            getline(cin, buscar2);
                for (int i = 0; i < 3; i++) {
                    if (buscar2 == compras[i].genero) {
                        printf(" Numero del articulo: %d \n", compras[i].numarticulo);
                        printf(" Nombre del articulo: %s \n", compras[i].nombrejuego.c_str());
                        printf(" Ano de lanzamiento: %d \n", compras[i].anodelanzamiento);
                        printf(" Clasificacion del articulo: %s \n", compras[i].clasificacion.c_str());
                        printf(" Descripcion del articulo: %s \n", compras[i].descripcion.c_str());
                        printf(" Genero del articulo: %s \n", compras[i].genero.c_str());
                        printf(" Precio unitario del articulo: %f \n", compras[i].precio_unitario);
                        printf(" Total: %f \n", compras[i].total);
                        printf("************************\n");
                        printf("\n");
                    }
                    else {
                        printf(" No hay Articulos del genero solicitado. \n");
                        return main();
                        break;
                        }
                }
            return main();
            break;

        default:
            cout << "ingrese una opcion correcta \n";
            return main();
        }

    case 3: //Modificar Articulo
        break;

    case 4://Eliminar Articulo
        break;

    case 5: //Articulos vigentes
        break;

    case 6: //Limpiar Pantalla
        system("cls"); //clean  se utiliza en web 
        return main();
        break;

    case 7: //salir
        cout << "Gracias por utilizar el programa \n";
        break;

    default:
        cout << "ingrese una opcion correcta \n";
        return main();

    }

}