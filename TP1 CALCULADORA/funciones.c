#include <stdio.h>
#include <stdlib.h>


/*float pedirUnNumero()
{
float numero;

printf("Por favor ingrese el primer numero:");
scanf("%f",&numero);

return numero;

}*/

float pedirUnNumero(char texto [])
{
    float numero;
    printf("%s",texto);
    scanf("%f",&numero);
    return numero;
}

float suma(float primerNumero,float segundoNumero)
{
    float resultadoSuma;

    resultadoSuma=(primerNumero+segundoNumero);

    return resultadoSuma;
}


float resta(float primerNumero,float segundoNumero)
{
  float resultadoResta;

  resultadoResta=(primerNumero-segundoNumero);

  return resultadoResta;
}


float multiplicacion(float primerNumero,float segundoNumero)
{
  float resultadoMultiplicacion;

  resultadoMultiplicacion=(primerNumero*segundoNumero);

  return resultadoMultiplicacion;
}

 float division(float primerNumero,float segundoNumero)
 {
  float resultadoDivision;

  resultadoDivision=(primerNumero/segundoNumero);

  return resultadoDivision;

 }


long long int factorial(int n){
int respuesta;

if(n==1)
{
    return 1;
}
respuesta=n*factorial(n-1);
return (respuesta);
}


int validacionDelDivisor(float numeroDos)
{
int respuestaDiv=1;
   if(numeroDos==0)
    {
        printf("\nERROR no se podra dividir un numero por cero.\n");
        printf("\nUsted debera reingresar el segundo numero y darle un valor distinto de 0.\n");
        respuestaDiv=0;
        system("pause");
    }
    return respuestaDiv;

}

int validacionDelFactorial(float numeroUno)
{
    if(numeroUno==0)
    {
        printf("\nEl factorial vale 1.\n");
        system("pause");
        return 1;

    }
   else
   {
       if(numeroUno<0)
       {
        printf("\nERROR , el factorial de un numero negativo no se podra calcular.\n");
        system("pause");
        return 1;


       }

       else
       {
          if(numeroUno-(int)numeroUno > 0)//ejem: numeroUno=4.75 - 4.00 =75 devolveria ERROR.
          {
          printf("\nERROR , no se puede calcular el factorial de un numero con decimales.\n");
          system("pause");
          return 1;
          }


       }
   }
}
