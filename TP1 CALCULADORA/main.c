#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    system("color F0");
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    float flagNumeroUno=0;
    float flagNumeroDos=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorial;



    while(seguir=='s')
    {
        system("cls");


        printf("<+-*/>CALCULADORA MATEMATICA<+-*/> \n");
        printf("\nIngrese una opcion para comenzar: \n");

           if(flagNumeroUno == 0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A=%.2f)\n",numeroUno);
        }

        if(flagNumeroDos == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",numeroDos);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la multiplicacion (A*B)\n");
        printf("6- Calcular la division (A/B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            system("cls");
            numeroUno=pedirUnNumero("Ingrese primer operando: ");
            flagNumeroUno=1;
            system("cls");

            break;
            case 2:

            system("cls");
            numeroDos=pedirUnNumero("ingrese segundo operando: ");
            flagNumeroDos=1;
            system("cls");

            break;
            case 3:

                if(flagNumeroUno == 0 || flagNumeroDos == 0)//es decir si la bandera esta baja y no se ingreso NADA.
            {
                printf("\nNo se ha ingresado ningun numero para realizar la suma.\n");
            }
            else
            {
                resultadoSuma=suma(numeroUno,numeroDos);
                printf("La suma es: %.2f \n",resultadoSuma);
            }
            system("pause");

            break;

                break;
            case 4:
                  if(flagNumeroUno == 0 || flagNumeroDos == 0)//es decir si la bandera esta baja y no se ingreso NADA.
            {
                printf("\nNo se ha ingresado ningun numero para realizar la suma.\n");
            }
            else
            {
                resultadoResta=resta(numeroUno,numeroDos);
                printf("La resta es: %.2f \n",resultadoResta);
            }
            system("pause");


                break;
            case 5:
                if(flagNumeroUno == 0 || flagNumeroDos == 0)//es decir si la bandera esta baja y no se ingreso NADA.
            {
                printf("\nNo se ha ingresado ningun numero para realizar la suma.\n");
            }
            else
            {
                resultadoMultiplicacion=multiplicacion(numeroUno,numeroDos);
                printf("El producto es es: %.2f \n",resultadoMultiplicacion);
            }
            system("pause");

            break;
            case 6:
                if(flagNumeroUno == 0 || flagNumeroDos == 0)//es decir si la bandera esta baja y no se ingreso NADA.
            {
                printf("\nNo se ha ingresado ningun numero para realizar la division.\n");
            }


                    else
                    {
                    if(validacionDelDivisor(numeroDos)==0)
                    {
                    break;
                    }
                    else
                    {
                    resultadoDivision=division(numeroUno,numeroDos);
                    printf("El resultado de la division es: %.2f \n",resultadoDivision);
                    }
                    }

                system("pause");

            break;
            case 7:
                  if(flagNumeroUno == 0)//es decir si la bandera esta baja y no se ingreso NADA.
            {
                 printf("\nNo se ha ingresado ningun numero para calcular el factorial.\n");
            }
                else
                {
                     if(validacionDelFactorial(numeroUno)==1)
                {
                    break;
                }
                else
                {
                resultadoFactorial=(int)factorial(numeroUno);
                printf("El factorial es: %lld\n",resultadoFactorial);
                }
            }
            system("pause");
                break;




            case 8:
                 if(flagNumeroUno == 0 || flagNumeroDos == 0)//es decir si la bandera esta baja y no se ingreso NADA.
            {
                while(numeroUno==0)
                {
                    printf("El factorial de 0 es:1 ");
                    break;
                }
                printf("\nNo se han ingresado los dos operandos para realizar las demas  operaciones.\n Por favor ingrese un segundo operando para continuar \n");
            }
                else
                {

                resultadoSuma=suma(numeroUno,numeroDos);
                printf("La suma es: %.2f \n",resultadoSuma);

                resultadoResta=resta(numeroUno,numeroDos);
                printf("La resta es: %.2f \n",resultadoResta);


                resultadoMultiplicacion=multiplicacion(numeroUno,numeroDos);
                printf("El producto es: %.2f \n",resultadoMultiplicacion);


        if(validacionDelDivisor(numeroDos)!=0)
        {
        resultadoDivision=division(numeroUno,numeroDos);
        printf("La division es: %2.f \n",resultadoDivision);
         }

        if(validacionDelFactorial(numeroUno)!=1)
        {
        resultadoFactorial=(int)factorial(numeroUno);
        printf("El factorial es: %lld\n",resultadoFactorial);
        }
                }

        system("pause");
                break;


               case 9:
                seguir = 'n';
                break;
             default:
            printf("\nIngrese una opcion valida.\n");

            break;
        }
        }


    return 0;

}
