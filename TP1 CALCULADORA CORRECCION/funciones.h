#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED




/*Crear una calculadora:
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones*/



/** \brief Esta funcion pide un numero por medio de un texto y guardara este valor ingresado por
           el usuario.
 *
 * \param Tipo de dato char , Texto que se le muestra al usuario.
 * \return Sera el valor ingresado.
 *
 */
float pedirUnNumero(char texto []);

/**
 * \brief La funcion suma , sumara dos numeros ya sean enteros o decimales ingresados por el usuario.
 * \param Primer numero ingresado por el usuario podra ser entero o decimal.
 * \param Segundo numero ingresado por el usuario podra ser entero o decimal.
 * \return Esta funcion Suma , retornara el resultado de sumar primer numero mas segundo numero.
 *
 */

 float suma(float primerNumero,float segundoNumero);



 /**
 * \brief La funcion resta , restara dos numeros ya sean enteros o decimales ingresados por el usuario.
 * \param Primer numero ingresado por el usuario podra ser entero o decimal.
 * \param Segundo numero ingresado por el usuario podra ser entero o decimal.
 * \return Esta funcion Resta , retornara el resultado de restar primer numero con segundo numero.
 *
 */

 float resta(float primerNumero,float segundoNumero);


 /**
 * \brief La funcion multiplicar ,realizara el producto de dos numeros ya sean enteros o decimales
          ingresados por el usuario.
 * \param Primer numero ingresado por el usuario podra ser entero o decimal.
 * \param Segundo numero ingresado por el usuario podra ser entero o decimal.
 * \return Esta funcion Multiplicar , retornara el resultado de hacer el producto entre
           el primer numero y el  segundo numero.
 *
 */

 float multiplicacion(float primerNumero,float segundoNumero);

 /**
 * \brief La funcion dividir ,realizara la division de dos numeros ya sean enteros o decimales
          ingresados por el usuario.
 * \param Primer numero ingresado por el usuario podra ser entero o decimal.
 * \param Segundo numero ingresado por el usuario podra ser entero o decimal.
 * \return Esta funcion division, retornara el resultado de dividir el primer numero y el  segundo numero.
 *
 */

 float division(float primerNumero,float segundoNumero);


 /** \brief Valida que el segundo numero (el divisor) sea distinto de 0.
 *
 * \param Tipo de dato float del segundo numero ingreso a dividir.
 * \return Tipo de dato int , sera 0 si el segundo numero ingresado (divisor) es 0 y 1 si el
           divisor es otro numero
 *
 */

 int validacionDelDivisor(float);


 /**
 * \brief La funcion factorial, calculara el factorial de un numero ingresado.
 * \param Primer numero ingresado por el usuario  sera un entero.
 * \return Esta Funcion factorial , devolvera el factorial del numero ingresado.
 */

 long long int factorial(int n);


 /** \brief Esta funcion validara un numero al que se le podra calcular el factorial
 *         siendo este , positivo y entero (no se puede calcular el factorial de un decimal (float)
                                            y a la par el factorial de 0.
 *
 * \param  Tipo de dato float del numero a validar.
 * \return Tipo de dato int 1 si el factorial no se puede calcular , con los printf
           correspondientes que expliquen el porque en cada caso.
 *
 */

int validacionDelFactorial(float);
