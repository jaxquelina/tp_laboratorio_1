#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**Mi programa:
Se encargara de pedir al usuario que cargue peliculas en donde se piden los siguientes datos:
*Titulo ,*Genero , *Duracion , *Descripcion , *Puntaje , *Imagen , luego permitira
borrar o modificar dicha pelicula , y con la opcion 4 se le permitira crear una pagina wed donde apareceran
los datos que se ingresaron*/


typedef struct{
    char titulo[31];
    char genero[21];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;
}EMovie;


/**
 *  Esta funcion se en cargara de inicializar los estados de la estructura MOVIE.
 *  \param El primer parametro sera la estructura EMovie a agregar.
 *  \param Sera tipo entero al ser el tamaño del puntero.
 *  \return Void ,es decir no devolvera nada.
 */
void inicializarEstados(EMovie*,int);



/**
 *  Esta funcion se encargara de ingresar los datos de la estructura pidiensolos a el usurario
 *  \param  El primer parametro sera la estructura EMovie a agregar.
 *  \param  Sera tipo entero al ser el tamaño del puntero.
 *  \return Int , sera un entero que indicara si se pudo ingresar correctamente los datos.
 */

int cargarPelicula(EMovie*,int);




/**
 *  Esta funcion se encargara de agregar la pelicula al archivo
 *  \param Sera la estructura EMovie la cual se agregara.
 *  \param Sera el titulo tipo Char.
 *  \param Sera el genero tipo Char.
 *  \param Sera la duracion tipo Int.
 *  \param Sera la descripcion tipo Char.
 *  \param int con el puntaje tipo Int.
 *  \param char link de la imagen tipo Char.
 *  \param tamaño del puntero tipo Int.
 *
 */
void agregarPelicula(EMovie*,char[],char[],int,char[],int,char[],int);




/**
 *  Se encargara de crear el archivo.
 *  \param Sera la estructura EMovie la cual se agregara al archivo.
 *  \param Sera el tamaño del puntero.
 */
void crearArchivo(EMovie*,int);


/**
 *  Esta funcion se encargara de eliminar una pelicula que el usuario elija.
 *  \param Sera la estructura EMovie que contendra las peliculas a eliminar.
 *  \param Sera el tamaño del puntero.
 */
void borrarPelicula(EMovie*,int);



/**
 *  Esta funcion se encargara de modificar una pelicula.
 *  \param Sera la estructura EMovie con la pelicula la cual se quera modificar.
 *  \param Sera el tamaño del puntero.
 */
void modificarPelicula(EMovie*,int);



/**
 *  Esta funcion se encargara de realizar una página web
 *  \param estructura EMovie con la que se creara la pagina
 *  \param sera el tamaño del puntero tipo int.
 */
void crearPagina(EMovie*,int);




#endif // FUNCIONES_H_INCLUDED
