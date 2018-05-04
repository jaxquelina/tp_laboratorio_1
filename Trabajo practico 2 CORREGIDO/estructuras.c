#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estructuras.h"

int menu()
{
    int opcion;

    system("cls");
    system("color F0");
    printf("---Bienvenido al programa para cargar Usuarios ---\n\n");
    printf("1-Alta\n");
    printf("2-Baja\n");
    printf("3-Imprimir lista ordenada por nombre\n");
    printf("4-Imprimir grafico de edades\n");
    printf("5-Salir\n");
    printf("\nIndique opcion para comenzar: ");
    scanf("%d", &opcion);



    return opcion;
}




void inicializarPersonas(struct Epersona gente[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        gente[i].estaLibre=1;

    }
}



void mostrarPersona(struct Epersona gente)
{
    printf("  %s     %d     %lld ", gente.nombre, gente.edad, gente.DNI);
}



int buscarLibre(struct Epersona gente[], int cantidad)
{
    int indice = -1;
    int i;

    for(i=0; i <cantidad; i++)
    {
        if(gente[i].estaLibre== 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarPersona(struct Epersona gente[], int cantidad, int DNI)
{
    int indice = -1;
    int i;

    for(i=0; i < cantidad; i++)
    {
        if(gente[i].estaLibre == 0 && gente[i].DNI == DNI)
        {
            indice = i;
            break;
        }
    }
    return indice;
}




void altaPersona(struct Epersona gente[], int cantidad)
{

    struct Epersona nuevaPersona;
    int indice;
    int esta;
    long long int DNI;
    char dniAuxStr[50];
    char nombreAux[50];
    char Auxnombre[50];
    char edadAuxStr[50];
    char nombre[50];
    int letras;

    system("cls");
    printf("---Alta Persona--\n\n");

    indice = buscarLibre(gente, cantidad);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta nuevas personas.\n\n");
    }
    else
    {
       if (!getStringNumeros("Ingrese el Dni: ",dniAuxStr))
        {

            printf ("El dni debe ser numerico\n");

                while(!getStringNumeros("Reingrese el Dni: ",dniAuxStr))
                  {
                      printf("NO INGRESE LETRAS ");

                  }


       }



        DNI = atoi(dniAuxStr);

        esta = buscarPersona(gente,cantidad,DNI);

        if(esta != -1)
        {
            printf("\nEl DNI %lld ya esta dado de alta en el sistema\n", DNI);
                   mostrarPersona(gente[esta]);

        }
        else{
                   nuevaPersona.estaLibre = 0;
                   nuevaPersona.DNI = DNI;

                if (!getStringLetras("Ingrese el nombre: ",nombreAux))
                 {
                  printf ("El nombre deben ser letras \n");

                 while(!getStringLetras("Reingrese el Nombre: ",nombreAux))
                  {
                      printf("NO INGRESE NUMEROS ");

                  }

                  }

                   strcpy(nuevaPersona.nombre,(strlwr(nombreAux)));



                if (!getStringNumeros("Ingrese la edad: ",edadAuxStr))
             {
                while(!getStringNumeros("Reingrese la edad: ",edadAuxStr))
                  {
                      printf("NO INGRESE LETRAS ");

                  }
             }

                nuevaPersona.edad = atoi(edadAuxStr);

             while(nuevaPersona.edad <0 || nuevaPersona.edad >= 110)
             {
                 printf("POR FAVOR LA EDAD DEBE SER MENOR A 0 Y MAYOR A 100: ");
                 scanf("%d",&nuevaPersona.edad);
             }


                   gente[indice] = nuevaPersona;

                   printf("\nAlta exitosa!!!\n\n");

           }

  }

}

void bajaPersona(struct Epersona gente[], int cantidad){
long long int  DNI;
int esta;
char confirma;

system("cls");
printf("---Baja Persona---\n\n");

   printf("Ingrese DNI: ");
        scanf("%lld", &DNI);

        esta = buscarPersona(gente, cantidad, DNI);

        if(esta == -1)
        {
            printf("\nEl DNI %lld no se encuentra en el sistema\n\n", DNI);

        }
        else{

                mostrarPersona(gente[esta]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            gente[esta].estaLibre = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
        }

        }
}




void ordenarPersonas(struct Epersona gente[], int cantidad)
{
    int i;
    int j;
    struct Epersona auxPersona;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(gente[i].nombre, gente[j].nombre)>0)
            {
                auxPersona = gente[i];
                gente[i] = gente[j];
                gente[j] = auxPersona;
            }
        }

    }

    printf("\nNombre\tEdad\tDNI\n");

    for(i=0; i<cantidad; i++)
    {
        if(gente[i].estaLibre==0)
        {
            printf("%s\t%d\t%lld\n", gente[i].nombre, gente[i].edad, gente[i].DNI);
        }
    }


}



void graficoPersonas(struct Epersona gente[],int gente18 , int genteDe19a35 ,int gentemayorde35 ,int cantidad)
{
    int i,flag;
    for(i=0; i<cantidad; i++)
    {
        flag=0;
        if(gente[i].estaLibre==0)
        {
            if(gente[i].edad<=18)
            {
                gente18++;
            }
            else
            {
                if(gente[i].edad>35)
                {
                    gentemayorde35++;
                }
                else
                {
                    genteDe19a35++;
                }
            }
        }
    }
    if(gente18 >= genteDe19a35 && gente18 >= gentemayorde35)
    {
        cantidad = gente18;
    }
    else
    {
        if(genteDe19a35 >= gente18 && genteDe19a35 >= gentemayorde35)
        {
           cantidad = genteDe19a35;
        }
        else
        {
           cantidad = gentemayorde35;
        }
    }
    for(i=cantidad; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }

        if(i<= gente18)
        {
            printf("*");
        }
        if(i<= genteDe19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= gentemayorde35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("-------------------");
    printf("\n  |<18\t19-35\t>35");
}
