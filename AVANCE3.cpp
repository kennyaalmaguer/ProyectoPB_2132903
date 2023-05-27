include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct datos
{
    int  nart, year, unidades;
    float total, precio, impuesto;
    string articulo, descripcion, genero, clasificacion, consola, status, caracteristicas;
};



int alta;

datos* tienda;
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();
void validacion(int v, bool& k);



int main()
{
    int opcion;


    printf("\n\t%c BIENVENIDO A MEGAPLANET %c", 1, 1);
    printf("\n\t %c%c%c MEN%c DE OPCIONES %c%c%c\n", 16, 16, 16, 233, 17, 17, 17);
    printf("\n\t1-Alta de Art%cculos\n", 161);
    printf("\t2-Modificaci%cn de Art%culos\n", 162, 161);
    printf("\t3-Baja de Art%cculos\n", 161);
    printf("\t4-Lista de Art%cculos\n", 161);
    printf("\t5-Limpiar Pantalla\n");
    printf("\t6-Salir\n");
    printf("\nEscoga una opci%cn....\t", 162);
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1: //ALTA
        Alta();
        return main();
        break;

    case 2://MODIFICAR
        modificar();
        return main();
        break;

    case 3:
        eliminar();
        return main();
        break;

    case 4://LISTA
        listas();
        return main();
        break;

    case 5:
        system("cls"); // LIMPIAR PANTALLA
        return main();
        break;
    case 6:
        archivos();
        //exit(1); //CIERRA PANTALLA
        break;
    default:
        printf("\n%cIngrese opci%cn v%clida%c\n", 16, 162, 160, 17);
        return main();
        break;

    }

}

void Alta()
{


    printf("\n%cCu%cntos registros desea dar de alta%c\n", 168, 160, 63);
    scanf_s("%d", &alta);

    tienda = new datos[alta];

    int nua;
    bool k;

    for (int i = 0; i < alta; i++)
    {
        int l = i + 1;

        printf("\n\nART%cCULO %d\n", 214, l);

        do {

            printf("\nIngrese n%cmero de art%cculo: ", 163, 161);
            scanf_s("%d", &nua);

            validacion(nua, k);

        } while (k);

        tienda[i].nart = nua;

        while (getchar() != '\n');//se vacia el buffer o el espacio

        printf("\nIngrese nombre de art%cculo: ", 161);
        getline(cin, tienda[i].articulo);

        do
        {
            printf("\nIngrese el a%co de lanzamiento: ", 164);
            scanf_s("%d", &tienda[i].year);

            if (tienda[i].year < 1970 || tienda[i].year>2024)
            {
                printf("\n%cFavor de ingresar un a%co que este entre 1970-2024%c\n", 16, 164, 17);
            }

        } while (tienda[i].year < 1970 || tienda[i].year>2024);


        while (getchar() != '\n');

        printf("\nIngrese descripci%cn de art%cculo: ", 162, 161);
        getline(cin, tienda[i].descripcion);

        printf("\nIngrese g%cnero de art%cculo: ", 130, 161);
        getline(cin, tienda[i].genero);

        printf("\nIngrese clasificaci%cn del art%cculo: ", 162, 161);
        getline(cin, tienda[i].clasificacion);

        printf("\nIngrese caracter%csticas del art%cculo: ", 161, 161);
        getline(cin, tienda[i].caracteristicas);

        printf("\nIngrese consola del art%cculo: ", 161);
        getline(cin, tienda[i].consola);

        printf("\nIngrese n%cmero de unidades del art%cculo: ", 163, 161);
        scanf_s("%d", &tienda[i].unidades);

        printf("\nIngrese precio de art%cculo: ", 161);
        scanf_s("%f", &tienda[i].precio);

        tienda[i].total = tienda[i].precio * 1.16;
        tienda[i].impuesto = tienda[i].precio * 0.16;
    }
}

void validacion(int v, bool& k)
{

    for (int i = 0; i < alta; i++)
    {
        int j = i - 1;

        if (v == tienda[j].nart)
        {
            k = true;
            printf("\n%cN%cMERO DE ART%cCULO REPETIDO%c\nFavor de ingresar otro n%cmero de art%cculo\n", 16, 233, 214, 17, 163, 161);
            return;

        }
    }
    k = false;
}

void listas()
{
    int opcion;
    string clave;

    printf("\nFiltrar la informaci%cn: \n1-Categor%ca\n2-G%cnero\n3-Consola\n", 162, 161, 130);
    scanf_s("%d", &opcion);

    printf("Ingrese palabra clave: ");
    cin.ignore();
    getline(cin, clave);

    while (getchar() != '\n');

    for (int i = 0; i < alta; i++)
    {
        int l = i + 1;
        if (tienda[i].status == "ELIMINADO")
        {
            printf("\nREGISTRO ELIMINADO %d\n", l);
        }
        else
        {
            switch (opcion)
            {
            case 1:

                if (tienda[i].clasificacion == clave)
                {
                    printf("\nART%cCULO %d\n", 214, l);
                    printf("N%cmero de art%cculo: %d\n", 163, 161, tienda[i].nart);
                    printf("Nombre del videojuego: %s\n", tienda[i].articulo.c_str());
                    printf("A%co de lanzamiento: %d\n", 164, tienda[i].year);
                    printf("Descripcion: %s\n", tienda[i].descripcion.c_str());
                    printf("G%cnero: %s\n", 130, tienda[i].genero.c_str());
                    printf("Clasificaci%cn: %s\n", 162, tienda[i].clasificacion.c_str());
                    printf("Caracter%csticas: %s\n", 161, tienda[i].caracteristicas.c_str());
                    printf("Consola: %s\n", tienda[i].consola.c_str());
                    printf("Unidades: %d\n", tienda[i].unidades);
                    printf("Precio Unitario: %f\n", tienda[i].precio);
                    printf("Impuesto: %f\n", tienda[i].impuesto);
                    printf("Precio Total: %f\n", tienda[i].total);
                }
                else
                {
                    printf(" ");
                }

                break;
            case 2:
                if (tienda[i].genero == clave)
                {
                    printf("\nART%cCULO %d\n", 214, l);
                    printf("N%cmero de art%cculo: %d\n", 163, 161, tienda[i].nart);
                    printf("Nombre del videojuego: %s\n", tienda[i].articulo.c_str());
                    printf("A%co de lanzamiento: %d\n", 164, tienda[i].year);
                    printf("Descripcion: %s\n", tienda[i].descripcion.c_str());
                    printf("G%cnero: %s\n", 130, tienda[i].genero.c_str());
                    printf("Clasificaci%cn: %s\n", 162, tienda[i].clasificacion.c_str());
                    printf("Caracter%csticas: %s\n", 161, tienda[i].caracteristicas.c_str());
                    printf("Consola: %s\n", tienda[i].consola.c_str());
                    printf("Unidades: %d\n", tienda[i].unidades);
                    printf("Precio Unitario: %f\n", tienda[i].precio);
                    printf("Impuesto: %f\n", tienda[i].impuesto);
                    printf("Precio Total: %f\n", tienda[i].total);
                }
                else
                {
                    printf(" ");
                }
                break;
            case 3:

                if (tienda[i].consola == clave)
                {
                    printf("\nART%cCULO %d\n", 214, l);
                    printf("N%cmero de art%cculo: %d\n", 163, 161, tienda[i].nart);
                    printf("Nombre del videojuego: %s\n", tienda[i].articulo.c_str());
                    printf("A%co de lanzamiento: %d\n", 164, tienda[i].year);
                    printf("Descripcion: %s\n", tienda[i].descripcion.c_str());
                    printf("G%cnero: %s\n", 130, tienda[i].genero.c_str());
                    printf("Clasificaci%cn: %s\n", 162, tienda[i].clasificacion.c_str());
                    printf("Caracter%csticas: %s\n", 161, tienda[i].caracteristicas.c_str());
                    printf("Consola: %s\n", tienda[i].consola.c_str());
                    printf("Unidades: %d\n", tienda[i].unidades);
                    printf("Precio Unitario: %f\n", tienda[i].precio);
                    printf("Impuesto: %f\n", tienda[i].impuesto);
                    printf("Precio Total: %f\n", tienda[i].total);
                }
                else
                {
                    printf(" ");
                }
                break;

            default:
                printf("\n%cIngrese opci%cn v%clida%c\n", 16, 162, 160, 17);
                return listas();
                break;
            }


        }
    }

}

void modificar()
{
    int j, opcion, op2;
    do
    {
        printf("\nIngrese el n%cmero registro a modificar:", 163);
        scanf_s("%d", &j);


        j = j - 1; // esto debido a que i inicia en 0

        for (int i = j; i == j; i++)
        {
            int l = i + 1;

            if ((tienda[i].status == "ELIMINADO"))
            {
                printf("REGISTRO %d ELIMINADO\n", l);
                printf("Ingrese un registro v%clido \n", 160);
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
    } while (op2 == 1);
    printf("\n%cQu%c que desea modificar%c\n1-Nombre\n2-A%co\n3-Descripci%cn\n4-G%cnero\n5-Clasificaci%cn\n6-Caracter%csticas\n7-Consola\n8-Unidades\n9-Precio\n", 168, 130, 63, 164, 162, 130, 162, 161);
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');
            printf("Ingrese nombre:");
            getline(cin, tienda[i].articulo);
        }
        break;

    case 2:
        for (int i = j; i == j; i++)
        {
            do
            {
                printf("\nIngrese el a%co de lanzamiento: ", 164);
                scanf_s("%d", &tienda[i].year);

                if (tienda[i].year < 1970 || tienda[i].year>2024)
                {
                    printf("\n%cFavor de ingresar un a%co que este entre 1970-2024%c\n", 16, 164, 17);
                }
            } while (tienda[i].year < 1970 || tienda[i].year>2024);
        }
        break;

    case 3:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("Ingrese descripci%cn:", 162);
            getline(cin, tienda[i].descripcion);
        }

        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');//se vacia el buffer o el espacio
            printf("Ingrese g%cnero:", 130);
            getline(cin, tienda[i].genero);
        }
        break;
    case 5:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("Ingrese clasificaci%cn:", 162);
            getline(cin, tienda[i].clasificacion);
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("Ingrese caracter%csticas:", 161);
            getline(cin, tienda[i].caracteristicas);
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("Ingrese consola:");
            getline(cin, tienda[i].consola);
        }
        break;

    case 8:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("Ingrese unidades:");
            scanf_s("%d", &tienda[i].unidades);
        }
        break;

    case 9:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("Ingrese precio:");
            scanf_s("%f", &tienda[i].precio);

            tienda[i].total = tienda[i].precio * 1.16;
            tienda[i].impuesto = tienda[i].precio * 0.16;
        }
        break;
    default:
        printf("\n%cIngrese opci%cn v%clida%c", 16, 162, 160, 17);
        return modificar();
        break;

    }
}

void eliminar()
{
    int j;
    printf("Ingrese el registro a eliminar\n");
    scanf_s("%d", &j);

    j = j - 1;

    for (int i = j; i == j; i++)
    {
        int l = i + 1;
        printf("\nREGISTRO %d ELIMINADO\n", l);
        tienda[i].status = "ELIMINADO";

        tienda[i].nart = 0;
        tienda[i].articulo = "--";
        tienda[i].year = 0;
        tienda[i].descripcion = "--";
        tienda[i].genero = "--";
        tienda[i].clasificacion = "--";
        tienda[i].caracteristicas = "--\t";
        tienda[i].consola = "--";
        tienda[i].unidades = 0;
        tienda[i].precio = 0;
        tienda[i].impuesto = 0;
        tienda[i].total = 0;
    }
}

void archivos()
{
    ofstream file; //clase ifstream para leer archivos
    string namefile;
    int texto;
    string texto2;
    float texto3;

    namefile = "megaplanet.txt";

    file.open(namefile.c_str(), ios::out);

    if (file.fail())
    {
        printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
        exit(1);
    }

    file << "ARTICULO" << "\t" << "\t";
    file << "NOMBRE" << "\t" << "\t";
    file << "YEAR" << "\t" << "\t";
    file << "DESCRIPCION" << "\t";
    file << "GENERO" << "\t" << "\t";
    file << "CLASIFICACION" << "\t";
    file << "CARACTERISTICAS" << "\t";
    file << "CONSOLA" << "\t" << "\t";
    file << "UNIDADES" << "\t" << "\t";
    file << "PRECIO  UNITARIO" << "\t";
    file << "IMPUESTO" << "\t" << "\t";
    file << "PRECIO IVA" << "\t" << "\t";
    file << "STATUS" << "\t" <<"\n";

    for (int i = 0; i < alta; i++)
    {

        texto = tienda[i].nart;
        file << texto << "\t" << "\t";
        texto2 = tienda[i].articulo;
        file << texto2 << "\t" << "\t";
        texto = tienda[i].year;
        file << texto << "\t" << "\t";
        texto2 = tienda[i].descripcion;
        file << texto2 << "\t" << "\t" ;
        texto2 = tienda[i].genero;
        file << texto2 << "\t" << "\t";
        texto2 = tienda[i].clasificacion;
        file << texto2 << "\t" << "\t";
        texto2 = tienda[i].caracteristicas;
        file << texto2 << "\t" << "\t";
        texto2 = tienda[i].consola;
        file << texto2 << "\t" << "\t" ;
        texto = tienda[i].unidades;
        file << texto << "\t" << "\t";
        texto3 = tienda[i].precio;
        file << texto3 << "\t" << "\t";
        texto3 = tienda[i].impuesto;
        file << texto3 << "\t" << "\t";
        texto3 = tienda[i].total;
        file << texto3 << "\t" << "\t";
        texto2 = tienda[i].status;
        file << texto2 << "\t" << "\n";
    }


    file.close();
}
