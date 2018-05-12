#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int EspacioLibre(ePersona lista[], int tam, int valor)
{

    for(int i=0 ; i<tam ; i++)
    {
        if(lista[i].estado==valor)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int tam, int dni)
{
    int i;

    for(i=0 ; i<tam ; i++)
    {
        if(lista[i].dni==dni)
        {
            return i;
        }
    }
    return -1;
}

/** \brief Da de alta a un usuario
 *
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño de la cantidad de usuarios a ingresar.
 * \return //no retorna nada
 */
void AgregarUsuario(ePersona lista[], int TAM)
{
    ePersona nuevoUsuario;
    int lugar;
    int dni;



    lugar=EspacioLibre(lista,TAM,-1);

    if(lugar==-1)
    {
        printf("\n\nNo hay lugar en el sistema.\n\n");
        getch();

    }
    else{
        printf("\n\nIngrese su DNI : ");
        scanf("%d",&dni);

        if(buscarPorDni(lista,TAM,dni)!=-1)
        {
            printf("\n\nEl DNI: %d ya se encuentra ingresado.\n\n",dni);
            getch();
        }
        else
        {
            nuevoUsuario.dni=dni;
            printf("\n\nIngrese su nombre: ");
            fflush(stdin);
            gets(nuevoUsuario.nombre);

            printf("\n\nIngrese su edad: ");
            fflush(stdin);
            scanf("%d",&nuevoUsuario.edad);


            nuevoUsuario.estado=1;
            lista[lugar]=nuevoUsuario;


         }
    }


}

/** \brief Auxiliar para el ordenamiento por nombre
 *
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño de la cantidad de usuarios a ingresar.
 * \return //no retorna nada
 */
void OrdenamientoAux(ePersona lista[], int tam)
{
    ePersona aux;

            for(int i=0; i < tam - 1; i++)
                {
                    if(lista[i].estado == -1)
                    {
                        continue;
                    }
                    for(int j=i+1; j < tam; j++)
                    {
                        if(lista[j].estado == -1)
                        {
                            continue;
                        }
                        if(strcmp(lista[i].nombre,lista[j].nombre) > 0)
                        {
                            aux = lista[j];
                            lista[j] = lista[i];
                            lista[i] = aux;
                        }
                    }
                }
}

/** \brief Auxiliar para mostrar a los usuarios ordenados
 *
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño de la cantidad de usuarios a ingresar.
 * \return //no retorna nada
 */
void mostrarAux(ePersona lista[], int tam)
{
        for(int i=0;i < tam; i++)
        {
            if(lista[i].estado != -1)
            {
                printf("\n%s ---- %d ---- %d",lista[i].nombre,lista[i].dni,lista[i].edad);
            }
        }

}

/** \brief Muestra el listado completo de usuarios ordenados
 *
 * \param lista el array se pasa como parametro.
 * \param tam se pasa el tamaño de la cantidad de usuarios a ingresar.
 * \param valor Verificacion si existen usuarios para mostrar o no
 * \return //no retorna nada
 */
void mostrarUsuarios(ePersona lista[],int tam)
    {
        int flag=1;

        for(int i=0;i<tam;i++)
        {

            if(lista[i].estado==flag)
            {
                        printf("\nListado de Usuarios\n\n"); //////////////////////////////////
                        printf("NOMBRE       DNI      EDAD \n");

                OrdenamientoAux(lista,tam);
                mostrarAux(lista,tam);
                flag=0;
                break;
            }

            if(flag==1)
            {
                printf("\nNo hay usuarios para mostrar.\n");
                break;
            }
        }
    }

/** \brief Inicializa el valor de estado
 *
 * \param lista el array se pasa como parametro.
 * \param se pasa el tamaño de la cantidad de usuarios a ingresar.
 * \param valor inicia al estado con -1
 * \return //no retorna nada
 */
void inicializarPersonas(ePersona lista[],int tam,int valor)
{
    int i;
    for(i=0;i < tam; i++)
    {
        lista[i].estado = valor;
    }
}

/** \brief Borra a una persona
 *
 * \param lista el array se pasa como parametro.
 * \param tam cantidad de usuarios
 * \param valor se ingresa el dni para verificar que exista o no
 * \return //no retorna nada
 */
void BorrarUnaPersona(ePersona lista[], int tam)
{

        int borrar;
        int dni;
        int operacion;
        printf("Ingrese DNI del usuario a eliminar : ");
        scanf("%d",&dni);
        borrar=buscarPorDni(lista,tam,dni);
        if(borrar==-1)
        {
            printf("No se encuentra el DNI.");
        }
        else
        {
        printf("\n\n¿Esta seguro de querer eliminar al usuario %d ? ",dni);

            printf("\n\n SI) 1\n\n");
            printf("\n\n NO) 2\n\n");
            scanf("%d",&operacion);
            switch(operacion)
             {

                        case 1:
                                lista[borrar].estado=-1;
                                printf("\n\nUsuario borrado con exito.");
                                printf("\n-------------------------------------\n");
                                break;

                        case 2:
                                printf("\nCancelado.");
                                break;

            }
        }
}

/** \brief Grafico que muestra respectivas edades ingresadas ordenadas por Menor - edad Media - Mayor
 *
 * \param lista el array se pasa como parametro.
 * \param columnas se ingresa la cantidad de colunmas deseadas
 * \return //no retorna nada
 *
 */
void graficoEdades(ePersona lista[], int columnas)
{

    int contMenor[50];
    int contMedio[50];
    int contMayor[50];


    for(int i=0 ; i<lista[i].edad; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            contMenor[i]=lista[i].edad;
            contMedio[i]=lista[i].edad;
            contMayor[i]=lista[i].edad;
        }
    }

    for(int i=0;i<lista[i].edad;i++){
		for(int j=0;j<columnas;j++){
			if(contMenor[i]<18)
            {
                printf("     %d ",contMenor[i]);

                break;
            }
            if(contMedio[i]>18 && contMedio[i]<35)
            {
                printf("                %d ",contMedio[i]);

                break;
            }
            if(contMayor[i]>35)
            {
                printf("                             %d ",contMayor[i]);

                break;
            }

		}
		printf("\n");
	}

}




#endif // FUNCIONES_H_INCLUDED



