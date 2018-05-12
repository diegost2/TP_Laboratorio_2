#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;


int EspacioLibre(ePersona lista[], int , int );

int buscarPorDni(ePersona lista[], int , int );

void AgregarUsuario(ePersona lista[], int );

void OrdenamientoAux(ePersona lista[], int );

void mostrarAux(ePersona lista[], int );

void mostrarUsuarios(ePersona lista[],int , int );

void inicializarPersonas(ePersona lista[],int ,int );

void BorrarUnaPersona(ePersona lista[], int );

void graficoEdades(ePersona lista[], int );



#endif // FUNCIONES_H_INCLUDED


