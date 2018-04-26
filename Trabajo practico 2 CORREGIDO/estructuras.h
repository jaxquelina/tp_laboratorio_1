#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/**Mi programa:
Se debera hacer un programa el cual me permita ingresar hasta 20 personas , dandolas de alta es decir
podiendo ingresar su DNI , NOMBRE , EDAD , y nuevamente su DNI ya que el primer DNI que se pedira
sera para verificar que ese DNI no este repetido. Luego se podran eliminar de el programa a la persona
que se quiera eliminar , mostrando a esta persona para no cometer errores. Luego mostrara a las personas
ordenadas por nombre y finalmente mostrar un grafico que tendra en cuenta si las personas ingresadas
tienen menos de 18 , tienen de 19 a 35 o tienen mas de 35 años.*/





struct Epersona{
               char nombre [71];
               char edad;
               long long int DNI;
               int estaLibre;
               };




/** \brief La fancion Menu contendra el menu con las opciones para el usuario.
 *
 * \return esta funcion retornara un entero que sera la opcion que el usuario mingrese.
 */
int menu();



/** \brief Esta funcion se encargara de inicializar cuando se ingrese una persona.
 *
 * \param gente[] La estructura persona.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \return sera void es decir no devolvera nada.
 *
 */
void inicializarPersonas(struct Epersona gente[],int cantidad);



/** \brief Mostrara a una persona sola me servira para usar en otras funciones
 *
 * \param gente[] La estructura persona.
 * \return void
 *
 */
void mostrarPersona(struct Epersona gente);



/** \brief esta funcion me indicara si habra espacio para seguir agregando personas o no
 *
 * \param gente[] La estructura persona.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \return int retornara -1 en caso de que no alla mas espacio discponible
 *
 */
int buscarLibre(struct Epersona gente[], int cantidad);


/** \brief Esta funcion me permitira buscar a una persona por medio del DNI que sea el dato unico
           de cada persona.
 *  \param gente[] La estructura persona.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \param DNI int
 * \return int Si el DNI  ya fue ingresado por otro usuario devolvera -1.
 *
 */
int buscarPersona(struct Epersona gente[], int cantidad, int DNI);


/** \brief Esta funcion me permitira ingresar nuevas personas siempre y cuando alla espacio y el documento
           no este repetido.
 *
* \param gente[] La estructura persona.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \return void es decir no retornara nada.
 *
 */
void altaPersona(struct Epersona gente[], int cantidad);


/** \brief Esta funcion me permitira borrar del programa las personas que se ingresen.
 *
* \param gente[] La estructura persona.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \return void es decir no retornara nada.
 *
 */
void bajaPersona(struct Epersona gente[], int cantidad);



/** \brief Esta funcion me permitira ordenar a las personas ingresadas por su nombre.
 *
* \param gente[] La estructura persona.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \return void es decir no retornara nada.
 *
 */
void ordenarPersonas(struct Epersona gente[], int cantidad);


/** \brief Me permitira realizar un grafico que tenga en cuenta la cantidad de personas ingresadas con sus
           respectivas edades.
 *
 * \param  gente[] La estructura persona.
 * \param  contador que lleva la cuenta de las personas que tienen hasta 18 anios.
 * \param  contador que lleva la cuenta de las personas que tienen de 19 a 35 anios.
 * \param  contador que lleva la cuenta de las personas que tienen mas de 35 anios.
 * \param int cantidad La cantidad de personas que se podran ingresar.
 * \return void es decir no retornara nada.
 */

void graficoPersonas(struct Epersona gente[],int hasta18 , int de19a35 ,int mayorde35 ,int cantidad);

#endif // FUNCIONES_H_INCLUDED
