#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"


void inicializarEstados(EMovie *pelicula,int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        (pelicula+i)->estado=0; //accedo al campo estado usando operador flecha
    }
}



int cargarPelicula(EMovie* pelicula,int cantidad)
{

    int auxiliar=0;
    int estado;
    int i;
    int estaLibre=1;


    char titulo[51];
    char genero[41];
    int  duracion;
    char descripcion[2000];
    int  puntaje;
    char imagen[500];

    if(estaLibre==0)
    {
        inicializarEstados(pelicula,cantidad);
        estaLibre=1;
    }

    if(estaLibre==1)
    {
        printf("Comencemos a cargar la Pelicula :) \n\n");

        printf("Ingrese titulo: ");
        fflush(stdin);
        scanf("%[^\n]",titulo);



        if (!getStringLetras("Ingrese el genero: ",genero))
        {
            printf ("El genero deben ser letras \n");

        while(!getStringLetras("Reingrese el Genero: ",genero))
            {
            printf("NO INGRESE NUMEROS ");

            }

        }


        printf("Ingrese duracion (minutos): ");
        scanf("%d",&duracion);



        printf("Ingrese una descripcion para la pelicula (menos de 50 caracteres): ");
        fflush(stdin);
        scanf("%[^\n]",descripcion);

        while(strlen(descripcion) > 2000)
       {
        printf("La descripcion debe ser de menos de 2000 caracteres: ");
        fflush(stdin);
         scanf("%[^\n]",descripcion);

       }


           printf("Ingrese el puntaje de la pelicula (del 1 al 100): ");
           scanf("%d",&puntaje);
           while(puntaje > 100 || puntaje < 1)
        {
        printf("El putaje de la pelicula debe estar entre 1 y 100: ");
        scanf("%d",&puntaje);
        }

        printf("Ingrese el link a la imagen de la pelicula: ");
        fflush(stdin);
        scanf("%[^\n]",imagen);


        estado=1;
        for(i=0;i<cantidad;i++)
        {
            if((pelicula+i)->estado==0)
            {
                agregarPelicula((pelicula+i),titulo,genero,duracion,descripcion,puntaje,imagen,estado);
                crearArchivo(pelicula,cantidad);
                auxiliar=1;
                break;
            }
        }
    }
    return auxiliar;
}



void agregarPelicula(EMovie  *pelicula,char titulo[],char genero[],int duracion,char descripcion[],int puntaje,char imagen[],int estado)
{
    strcpy(pelicula->titulo,titulo);
    strcpy(pelicula->genero,genero);
    pelicula->duracion=duracion;
    strcpy(pelicula->descripcion,descripcion);
    pelicula->puntaje=puntaje;
    strcpy(pelicula->imagen,imagen);
    pelicula->estado=estado;
}




void crearArchivo(EMovie *pelicula,int cantidad)
{
    FILE* punteroAFile; //sera el puntero a la estructura FILE.
    int i;

            punteroAFile=fopen("peliculas.dat","wb");
            if(punteroAFile!=NULL) //realizo la verificacion.
            {
                for(i=0;i<cantidad;i++)
                {
                    if((pelicula+i)->estado==1)
                    {
                        fwrite((pelicula+i),sizeof(EMovie),1,punteroAFile);
                    }
                }
            }
            else
            {
                printf("Lo sentimos no se  pudo generar el archivo  :( .\n");
                system("pause");
            }
            fclose(punteroAFile);

}




void borrarPelicula(EMovie* pelicula,int cantidad)
{
    int i;
    int auxiliar=0;
    char titulo[51];
    char opcion;

        for(i=0;i<cantidad;i++)
        {
            if((pelicula+i)->estado==1)
            {
                printf("PELICULAS:\n\n");
                for(i=0;i<cantidad;i++)
                {
                    if((pelicula+i)->estado==1)
                    {
                        printf("Pelicula:  %s\n",(pelicula+i)->titulo);
                    }
                }

                printf("\n\nIngrese el Titulo: ");
                fflush(stdin);
                scanf("%[^\n]",titulo);

                for(i=0;i<cantidad;i++)
                {
                    if(strcmp((pelicula+i)->titulo,titulo)==0)
                    {
                        printf("Pelicula:  %s\n\n",(pelicula+i)->titulo);
                        printf("Desea Borrar la pelicula (s/n): ");
                        fflush(stdin);
                        opcion = tolower(getch());

                        if(opcion=='s')
                        {
                            (pelicula+i)->estado=0;
                            printf("\nTitulo eliminado con exito!.\n\n");

                        }
                        else
                        {
                            printf("\n\nse cancelo la baja.\n\n");
                            system("pause");
                        }
                        auxiliar=1;
                        break;
                    }
                }
            break;
            }
        }

        if (auxiliar==1)
        {
            crearArchivo(pelicula,cantidad);
        }
}

int menuModificacion(){
    int opcion;
    system("cls");
    system("color 0F");
    printf("---MODIFICACION---\n");
    printf("-1- Titulo\n");
    printf("-2- Genero\n");
    printf("-3- Duracion\n");
    printf("-4- Descripcion\n");
    printf("-5- Puntaje\n");
    printf("-6- Link Pelicula\n");
    printf("-7- Salir\n");
    printf("Elija una opcion: ");

    scanf("%d",&opcion);
    system("cls");
    return opcion;
}


void modificarPelicula(EMovie* pelicula,int max)
{
    int i;
    char confirma;
    int salir=0;
    char tituloModificar[51];
    char opcion;
    char auxTitulo[51];
    char auxGenero[41];
    int  auxDuracion;
    char auxDescripcion[2000];
    int  auxPuntaje;
    char auxImagen[500];

        for(i=0;i<max;i++)
        {
            if((pelicula+i)->estado==1)
            {
                printf("PELICULAS:\n\n");
                for(i=0;i<max;i++)
                {
                    if((pelicula+i)->estado==1)
                    {
                        printf("Titulo: %s\n",(pelicula+i)->titulo);
                    }
                }


                printf("\n\nIngrese el titulo: ");
                fflush(stdin);
                gets(tituloModificar);
                for(i=0;i<max;i++)
                {
                    if(strcmp((pelicula+i)->titulo,tituloModificar)==0)
                    {
                        printf("Pelicula:  %s\n\n",(pelicula+i)->titulo);
                        printf("Desea modificar la pelicula (s/n): ");
                        fflush(stdin);
                        opcion = tolower(getch());
                    }
                }
                        if(opcion=='s')
                        {
                        do{
                         switch(menuModificacion())
                         {
                         case 1:
                              {
                          do{
                          printf("\t [ Modificacion Titulo: ]\n");
                          printf("Ingrese nuevo titulo: ");
                          fflush(stdin);
                          scanf("%[^\n]",auxTitulo);



                           printf("Desea realizar la modificacion [s|n]: ");
                           fflush(stdin);
                           scanf("%c", &confirma);
                           confirma = tolower(confirma);
                           }while(confirma != 's' && confirma != 'n');

                           if(confirma == 's')
                           {
                           strcpy(pelicula->titulo,auxTitulo);

                           printf("\nSe ha realizado la modificacion:\n\n");
                           printf("Modificacion:\n ");

                           system("pause");
                           break;
                           }

                           else{
                            printf("\nSe ha cancelado la modificacion\n\n");
                            }
                            break;
                            }

                            case 2:
                                {
                          do{
                          printf("\t [ Modificacion Genero: ]\n");
                          if (!getStringLetras("Ingrese el genero: ",auxGenero))
                         {
                          printf ("El genero deben ser letras \n");

                         while(!getStringLetras("Reingrese el Genero: ",auxGenero))
                         {
                         printf("NO INGRESE NUMEROS ");

                         }

                         }


                           printf("Desea realizar la modificacion [s|n]: ");
                           fflush(stdin);
                           scanf("%c", &confirma);
                           confirma = tolower(confirma);
                           }while(confirma != 's' && confirma != 'n');

                           if(confirma == 's')
                           {
                           strcpy(pelicula->genero,auxGenero);

                           printf("\nSe ha realizado la modificacion:\n\n");

                           system("pause");
                           break;
                           }

                            else{
                            printf("\nSe ha cancelado la modificacion\n\n");
                            }
                            break;
                            }



                          case 3:
                          {
                          do{
                          printf("\t [ Modificacion Duracion: ]\n");
                          printf("Ingrese duracion (minutos): ");
                          scanf("%d",&auxDuracion);



                           printf("Desea realizar la modificacion [s|n]: ");
                           fflush(stdin);
                           scanf("%c", &confirma);
                           confirma = tolower(confirma);
                           }while(confirma != 's' && confirma != 'n');

                           if(confirma == 's')
                           {
                           pelicula->duracion=auxDuracion;


                           printf("\nSe ha realizado la modificacion:\n\n");
                           printf("Modificacion:\n ");

                           system("pause");
                           break;
                           }

                           else{
                           printf("\nSe ha cancelado la modificacion\n\n");
                           }
                           break;
                           }


                            case 4:
                            {
                          do{
                          printf("\t [ Modificacion Descripcion: ]\n");
                          printf("Ingrese una descripcion para la pelicula (menos de 50 caracteres): ");
                          fflush(stdin);
                          scanf("%[^\n]",auxDescripcion);

                          while(strlen(auxDescripcion) > 2000)
                          {
                          printf("La descripcion debe ser de menos de 2000 caracteres: ");
                          fflush(stdin);
                          scanf("%[^\n]",auxDescripcion);

                          }

                           printf("Desea realizar la modificacion [s|n]: ");
                           fflush(stdin);
                           scanf("%c", &confirma);
                           confirma = tolower(confirma);
                           }while(confirma != 's' && confirma != 'n');

                           if(confirma == 's')
                           {
                           strcpy(pelicula->descripcion,auxDescripcion);

                           printf("\nSe ha realizado la modificacion:\n\n");

                           system("pause");
                           break;
                           }

                            else{
                            printf("\nSe ha cancelado la modificacion\n\n");
                            }
                            break;
                            }



                            case 5:
                             {
                          do{
                          printf("\t [ Modificacion Puntaje: ]\n");
                          printf("Ingrese el puntaje de la pelicula (del 1 al 100): ");
                          scanf("%d",&auxPuntaje);
                          while(auxPuntaje > 100 || auxPuntaje < 1)
                          {
                          printf("El putaje de la pelicula debe estar entre 1 y 100: ");
                          scanf("%d",&auxPuntaje);
                          }

                           printf("Desea realizar la modificacion [s|n]: ");
                           fflush(stdin);
                           scanf("%c", &confirma);
                           confirma = tolower(confirma);
                           }while(confirma != 's' && confirma != 'n');

                           if(confirma == 's')
                           {
                           pelicula->puntaje=auxPuntaje;

                           printf("\nSe ha realizado la modificacion:\n\n");

                           system("pause");
                           break;
                           }

                            else{
                            printf("\nSe ha cancelado la modificacion\n\n");
                            }
                            break;
                            }



                            case 6:
                              {
                          do{
                          printf("\t [ Modificacion Link Imagen: ]\n");
                          printf("Ingrese el link a la imagen de la pelicula: ");
                          fflush(stdin);
                          scanf("%[^\n]",auxImagen);

                          while(strlen(auxImagen) > 200)
                          {
                          printf("El link a la imagen de la pelicula debe ser menor a 200 caracteres: ");
                          fflush(stdin);
                          scanf("%[^\n]",auxImagen);
                          }

                           printf("Desea realizar la modificacion [s|n]: ");
                           fflush(stdin);
                           scanf("%c", &confirma);
                           confirma = tolower(confirma);
                           }while(confirma != 's' && confirma != 'n');

                           if(confirma == 's')
                           {
                           strcpy(pelicula->imagen,auxImagen);

                           printf("\nSe ha realizado la modificacion:\n\n");

                           system("pause");
                           break;
                           }

                            else{
                            printf("\nSe ha cancelado la modificacion\n\n");
                            }
                            break;
                            }



                            case 7:
                            salir = 1;
                            break;

                           default:
                           printf("\nOpcion Incorrecta\n\n");
                           system("pause");
                            }

                        }while(salir!=1);
                        break;



         }

         }
}
}

void crearPagina(EMovie* movie, int cantidadPeliculas)
{
    FILE* miArchivoHTML;
    char nombre[20];
    int i;
    int j,q;
    int auxInt=0;
    char auxCadena[268];
    char segundoAuxiliarCadena[268];
    printf("Ingrese nombre de la pagina: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre,".html");
    miArchivoHTML=fopen(nombre,"w");
    if(miArchivoHTML==NULL)
    {
        printf("La pagina no se va a poder generar.");
    }
    else
    {

        for(i=0;i<cantidadPeliculas;i++)
        {
            fprintf(miArchivoHTML,"<img  src=%s alt=%s style=width:200px;hight:200px>",(movie+i)->imagen,(movie+i)->titulo);


            fprintf(miArchivoHTML,"<h2><a href=#>%d)%s</a></h2>",i+1,(movie+i)->titulo);



            fprintf(miArchivoHTML,"<h4><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h4>",(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion);
            fprintf(miArchivoHTML,"<pre>");
            strcpy(auxCadena,(movie+i)->descripcion);
            q=0;
            for(j=0;j<268;j++)
            {
                segundoAuxiliarCadena[j]=auxCadena[q];
                q++;
                if(j==60||j==124||j==188)
                {
                    j++;
                    segundoAuxiliarCadena[j]='<';
                    j++;
                    segundoAuxiliarCadena[j]='b';
                    j++;
                    segundoAuxiliarCadena[j]='r';
                    j++;
                    segundoAuxiliarCadena[j]='>';

                }
            }
            auxInt=strlen(segundoAuxiliarCadena);
            fwrite(&segundoAuxiliarCadena,sizeof(char),auxInt,miArchivoHTML);
            fprintf(miArchivoHTML,"</pre>");
        }
        fprintf(miArchivoHTML,"</html> <body>");
    }
    fclose(miArchivoHTML);
    printf("Felicidades la  pagina se genero correctamente.\n");
}
