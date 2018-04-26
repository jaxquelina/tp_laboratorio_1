#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estructuras.h"

#define CANT 20

int main()
{
    struct Epersona gente[CANT];
    int salir=0;
    int gente18 , genteDel9a35 ,gentemayorde35;

    inicializarPersonas(gente, CANT);

    do
    {
        switch(menu())
        {

        case 1:
            altaPersona(gente,CANT);
            system("pause");
            break;


        case 2:
            bajaPersona(gente,CANT);
            system("pause");
            break;


        case 3:
            ordenarPersonas(gente,CANT);
            system("pause");
            break;


        case 4:
           gente18=0;
           genteDel9a35=0;
           gentemayorde35=0;
           graficoPersonas(gente, gente18, genteDel9a35, gentemayorde35, CANT);
           system("pause");

            break;

        case 5:
            salir = 1;
            break;


        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
           }
      }while(salir != 1);

return 0;
}
