#include <stdio.h>
#include <stdlib.h>
#include "dataWareHouse.h"

#define TAMMASCOTAS 10
#define TAMSERVICIOS 3
#define TAMTRABAJOS 200
#define TAMTIPOS 10
#define TAMCOLORES 10
#define CANTHARCODEO 5

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id ;
    char descripcion[20];

}eTipo;

typedef struct
{
    int id;
    char nombre[20];

}eColor;

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;

}eMascota;

typedef struct
{
    int id ;
    char descripcion[20];
    float precio;

}eServicio;

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;

}eTrabajo;

//*********************
void harcodearMascotas(eMascota mas[],int tamMas);
//*********************
int menu();
int buscarLibre(eMascota mas[],int tamMas);
void iniciarMascotas(eMascota mas[],int tamMas);
int altaMascota(eMascota mas[],int tamMas);
void mostrarMascota(eMascota mas);
void mostrarMascotas(eMascota mas[],int tamMas);
void bajaMascota(eMascota mas[],int tamMas);
int buscarMascotas(int id,eMascota mas[],int tamMAs);
void modificarMascota(eMascota mas[],int tamMas);
void mostrarMascotasPorTipoNombre(eMascota mas[],int tamMas);
void mostrarTipos(eTipo tipo[],int tamTipo);




int main()
{
    char continuar='s';
    char confirmar;
    int idMascotas=1000;

    eMascota lista[TAMMASCOTAS];
    eServicio secrvcios[TAMSERVICIOS]={{"Corte",250 }, {"Desparasitado",300},{"Castrado",400}};
    eColor colores [TAMCOLORES] ={{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eTipo tipo[TAMTIPOS]={{1000,"Ave"}, {1001,"Perro"},{1002,"Gato"},{1003,"Roedor"}, {1004,"Pez"}};
    eTrabajo trabajos[TAMTRABAJOS];

    iniciarMascotas(lista,TAMMASCOTAS);
    harcodearMascotas(lista,CANTHARCODEO);
    idMascotas+=CANTHARCODEO;


        while(continuar=='s')
    {
        switch(menu())
        {
        case 1:
            if(altaMascota(lista,TAMMASCOTAS))
            {
                idMascotas++;
            }
            else
            {
                printf("*****No se pudo efectuar al operacion*****\n");
            }
            break;
        case 2:
            modificarMascota(lista,TAMMASCOTAS);
            break;
        case 3:
            bajaMascota(lista,TAMMASCOTAS);
            break;
        case 4:
            mostrarMascotas(lista,TAMMASCOTAS);
            break;
        case 5:
            printf("mostrar por tipo y mombre ");
            break;
        case 6:
            printf("mostrar por color");
            break;
        case 7:
            printf("mostrar serveicios");
            break;
        case 8:
            printf("alta trabajos");
            break;
        case 9:
            printf("listar trabajos");
            break;
        case 10:
            printf("¿Seguro desea salir?");
            fflush(stdin);
            scanf("%c",&confirmar);
            if(confirmar =='s')
            {
                continuar='n';
            }
            break;
        }
    }
    return 0;
}
void harcodearMascotas(eMascota mas[],int tamhard)
{
    for (int i=0;i< tamhard;i++)
    {
        mas[i].id=ids[i];
        strcpy(mas[i].nombre,nombres[i]);
        mas[i].edad=edades[i];

        mas[i].isEmpty=0;

    }
}


int menu()
{
    int opciom;

    system("cls");

    printf("******* Gestion de Mascotas *******\n\n");

    printf("1-Alta Mascota.\n");
    printf("2-Modificar Mascota.\n");
    printf("3-Baja Mascota.\n");
    printf("4-Listar Mascitas.\n");
    printf("5-Listar tipos.\n");
    printf("6-Listar colores\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos\n");
    printf("10-Salir.\n\n");
    printf("Ingrese opcion.\n");
    scanf("%d",&opciom);

    return opciom;
}

int buscarLibre(eMascota mas[],int tamMas)
{
    int indice=-1;

    for(int i=0; i<tamMas; i++)
    {
        if (mas[i].isEmpty==1)// es redundante poner 1.
        {
            indice = i ;
            break;
        }
    }

    return indice;
}
void iniciarMascotas(eMascota mas[],int tamMas)
{
    for(int i=0; i<tamMas; i++)
    {
        mas[i].isEmpty=1;
    }
}

int altaMascota(eMascota mas[],int tamMas)
{
    int indice;
    int existe=-1;
    eMascota auxMascota;

    indice = buscarLibre(mas,tamMas);

    printf("*******Alta Mascota*******\n\n");

    if(indice==-1)
    {
        printf("Sistema completo\n");
    }
    else
    {
            printf("ingrese ID\n");
            scanf("%d",& auxMascota.id);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxMascota.nombre);

            printf("ingrese edad: ");
            scanf("%d",&auxMascota.edad);

            // agregar idTipo idColor

            auxMascota.isEmpty = 0;

            mas[indice]=auxMascota;

            existe=1;
        }

    return existe;
}
void mostrarMascota(eMascota mas)
{
    printf("%d %s %d \n",mas.id,mas.nombre,mas.edad);
}
void mostrarMascotas(eMascota mas[],int tamMas)
{
    int bandera=1;

    system("cls");

    printf("******************Lista de empleados******************\n\n");
    printf("    ID      Nombre   Edad\n\n");


    for (int i=0; i < tamMas; i++)
    {
        if (mas[i].isEmpty==0)
        {
            mostrarMascota(mas[i]);
            bandera=0;
        }
    }
    if (bandera)
    {
        printf("****No se cargaron mascotas****\n");
    }
}
int buscarMascotas(int id,eMascota mas[],int tamMas)
{
    int existe=-1;

    system("cls");

    for(int i=0; i<tamMas; i++)
    {
        if(mas[i].id==id && mas[i].isEmpty==0)// no compara con empleadodados de baja o formularios vacios
        {
            existe=i;
            break;
        }
    }
}
void bajaMascota(eMascota mas[],int tamMas)
{
    int indice;
    int id;
    char confirmar;

    system("cls");
    printf("---------Baja Mascota---------\n");
    mostrarMascotas(mas,tamMas);
    printf("---------ingrese id de baja------\n ");
    scanf("%d",&id);

    indice = buscarMascotas(id,mas,tamMas);

    if(indice==-1)
    {
        printf("El ID no existe");
    }
    else
    {
        printf("ID      Nombre    Edad   \n\n");

        mostrarMascotas(mas,tamMas);

        printf("¿Confirma la baja? s=Si n=No\n");
        fflush(stdin);
        scanf("%c",&confirmar);
        if (confirmar=='s')
        {
            mas[indice].isEmpty=1;

            printf("La baja se realizo con exito\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n");
        }
    }
}
void modificarMascota(eMascota mas[],int tamMas)
{
    int indice;
    int id;
    char confirmar;
    char continuar='s';
    int opcion;

    system("cls");
    printf("******Modificar Mascota******\n");
    printf("ingrese ID: ");
    scanf("%d",&id);

    indice = buscarMascotas(id,mas,tamMas);

    if(indice==-1)
    {
        printf("El ID no existe\n");
    }
    else
    {
        while(continuar=='s')
        {
            system("cls");
            printf("ID      Nombre    Edad   \n\n");
            mostrarMascota(mas[indice]);

            printf("1-Tipo\n");
            printf("2-Edad\n");
            printf("5-Salir\n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo nombre.\n");
                gets(mas[indice].idTipo);
                break;
            case 2:
                printf("Ingrese nueva edad.\n");
                scanf("%d",&mas[indice].edad);
                break;
            case 5:
                printf("¿Desea realizar otra modificaion? s=Si n=No\n");
                scanf("%c",&confirmar);
                if(confirmar=='s')
                {
                    continuar='s';
                }
                break;
            }
        }
    }
}
void mostrarTipos(eTipo tipo[],int tamTipo)
{
    printf("****Listado de Animales*****\n");
    printf("Id Descripcion \n");

    for (int i=0;i<tamTipo;i++)
    {
        printf(" %d  %10s  \n",tipo[i].id,tipo[i].descripcion);
    }
}
void cargarTipos(char descripcion[],int id,eTipo tipo[],int tamTipo)
{
    int todoOk=0;

    for (int i=0; i < tamTipo;i++)
    {
        if(id == tipo[i].id)
        {
            strcpy(descripcion,tipo[i].descripcion);
            todoOk=1;
        }
    }
    return todoOk;
}
void mostrarMascotasPorTipoNombre(eMascota mas[],int tamMas)
{
    for(int i=0,i<tamMas-1,i++)
    {
        for(int j)

    }
}
