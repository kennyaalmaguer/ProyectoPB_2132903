#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using namespace std;

struct datos
{
    int  nart, desicion;
    float total, precio;
    string articulo, descripcion, genero, clasificacion, consola;
}
;

int main()
{
    datos rep[3];
    int opcion;
   
    do
    {

    printf ("\n---MENU DE OPCIONES---\n");
    printf("1- Alta\n");
    printf("2.-Modificacion\n");
    printf("3-Baja\n");
    printf("4.-Lista\n");
    printf("5.-Limpiar Pantalla\n");
    printf("6.-Salir\n");
    scanf_s("%d",&opcion);

    
        switch (opcion)
        {
        case 1: //ALTA

            for (int i = 0; i <3; i++)
            {
               

                printf("\n\nIngrese numero de articulo\n");
                cin.ignore();
                scanf_s("%d", &rep[i].nart);
               
                printf("Ingrese nombre de articulo\n");
                cin.ignore();
                getline(cin, rep[i].articulo);
                
                printf("Ingrese descripcion de articulo\n");
                //cin.ignore(); 
                getline(cin, rep[i].descripcion);
                

                printf("Ingrese genero de articulo\n");
                //cin.ignore();
                getline(cin, rep[i].genero);
               

                printf("Ingrese clasificacion de articulo\n");
                //cin.ignore();
                getline(cin, rep[i].clasificacion);

                printf("Ingrese consola de articulo\n");
                //cin.ignore();
                getline(cin, rep[i].consola);

                printf("Ingrese precio de articulo\n");
                scanf_s("%f", &rep[i].precio);

                rep[i].total = rep[i].precio * 1.16;
                
            }

            break;

        case 2:
            break;

        case 3:
            break;

        case 4://LISTA

            for (int i = 0; i < 3; i++)
            {
                printf("\nNumero de articulo: %d\n", rep[i].nart);
                printf("Nombre de articulo: %s\n", rep[i].articulo.c_str());
                printf("Descripcion: %s\n", rep[i].descripcion.c_str());
                printf("Genero: %s\n", rep[i].genero.c_str());
                printf("Clasificacion: %s\n", rep[i].clasificacion.c_str());
                printf("Consola: %s\n", rep[i].consola.c_str());
                printf("Precio: %f\n", rep[i].total);
            }
            break;

        case 5:
            system("cls"); // LIMPIAR PANTALLA
            return main();
            break;
        case 6:
            exit(1); //CIERRA PANTALLA
            break;

        }
    } while(opcion!=6);
}