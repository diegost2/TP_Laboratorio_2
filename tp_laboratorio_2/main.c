#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define CANT 20


int main()
{
    ePersona usuario[CANT];
    char seguir='s';
    int opcion=0;
    inicializarPersonas(usuario,CANT, -1);
    while(seguir=='s')
    {
        system("cls");
        printf("\n----------------------------------\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("-------------------------------------\n\n");
        scanf("%d",&opcion);

        switch(opcion)
        {

            case 1:
                system("cls");
                AgregarUsuario(usuario, CANT);

                break;
            case 2:
                BorrarUnaPersona(usuario,CANT);
                getch();
                break;
            case 3:
                system("cls");

                mostrarUsuarios(usuario, CANT, -1);
                getch();
                break;
            case 4:
                system("cls");
                mostrarUsuarios(usuario, CANT, -1);
                printf("\n\n-------------------------------------\n\n");

                graficoEdades(usuario, 3);
                printf("\n\n");
                printf("   <<18--------19-35---------35>>");
                getch();
                break;
            case 5:
                seguir = 'n';

                break;
        }
    }

    return 0;

}
