#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/* 1
Crea y retorna un nuevo ArrayList. Es el constructor, ya que en él daremos valores iniciales a
las variables y asignaremos las funciones a sus punteros.*/


ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void **)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/* DOS:
Función al_add
Agrega un elemento al final de ArrayList. Verificando que tanto el puntero pList como pElement
sean distintos de NULL. Si la verificación falla la función retorna (-1) y si tiene éxito (0).*/

int al_add(ArrayList* this, void* pElement)
{

    void** aux;
    int returnAux = -1;
    int flag=0;

    if(this!= NULL && pElement != NULL)
    {
        if(this->size >= this->reservedSize)
        {
         aux =(void**) realloc(this->pElements ,sizeof(void*) * (this->reservedSize + AL_INCREMENT));
         if(aux !=NULL)
         {
             this->pElements= aux;
             this->reservedSize =this ->reservedSize + AL_INCREMENT;

         }
         else{
              flag=1;
             }
        }
         if(flag==0)
         {
             this ->pElements[this->size] = pElement;
             this ->size++;
             returnAux= 0;
         }
        }


    return returnAux;
}


/* TRES:
Elimina el ArrayList . Verificando que el puntero pList sea distinto de NULL. Si la verificación
falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).*/


int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/*CUATRO:
Retorna el tamaño del ArrayList. Verificando que el puntero pList sea distinto de NULL. Si la
verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.*/

int al_len(ArrayList* this)
{
    int returnAux=-1;
    if(this!=NULL)
    {
        returnAux=this->size; //SIZE ME INDICARA QUE SI VALE 0 NO HABRA ELEMENTOS.
    }

    return returnAux; //la funcion me fallo por eso me retorno -1
}

/*CINCO:
Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero pList sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.*/

 void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    int tamanio;
    if(this!=NULL)
    {
        tamanio=this->len(this);
        if(index>=0&&index<tamanio)
        {
            returnAux=this->pElements[index];
        }
    }

    return returnAux;
}

/*SEIS
Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
puntero pList como pElement sean distintos de NULL. Si la verificación falla la función retorna
(-1) , si encuentra el elemento (1) y si no lo encuentra (0).*/


int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag=0;
    int tamanio;
    int i;
    if(this != NULL && pElement != NULL)
    {
        tamanio=this->len(this);
        for(i=0; i<tamanio; i++)
        {

            if(this->pElements[i]==pElement)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            returnAux=1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/*SIETE
Inserta un elemento en el ArrayList, en el índice especificado. Verificando que tanto el puntero
pList como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del
array. Si la verificación falla la función retorna (-1) y si tiene éxito (0).*/


int al_set(ArrayList* this, int index,void* pElement)
{
int returnAux= -1;
int flag=0;
int tamanio;
if(this!=NULL && pElement!=NULL)
{
  tamanio=this->len(this);
  if(index<=tamanio&&index>=0)
  {
      if(index==tamanio)
      {
          flag=al_add(this,pElement);
          if(flag==0)
          {
              returnAux=0;//significaria que la carga del elemento fue extosa
          }
      }
      else
        {
         this->pElements[index]=pElement;
         returnAux=0;

        }
  }

}
return returnAux;
}


/*OCHO
Elimina un elemento del ArrayList, en el índice especificado. Verificando que el puntero pList
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0).*/
//si uso set a veces lo piso



int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int auxInt;
    int tamanio;
    if(this != NULL)
    {
        tamanio=this->len(this);
        if(index<tamanio && index>-1)
        {
        auxInt = contract(this,index);
        }
        if(auxInt != -1)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/*NUEVE
Borra TODOS los elementos de ArrayList. Verificando que el puntero pList sea distinto de NULL.
Si la verificación falla la función retorna (-1) y si tiene éxito (0).**/

 int al_clear(ArrayList* this)
{
    int returnAux=-1;
    int i;
    int tamanio;
    if(this!=NULL)
    {
        tamanio=this->len(this);
        for(i=0;i<tamanio;i++)
        {
            free(this->pElements);
        }
        this->size=0; //ahora siz valdria 0
        returnAux=0;
    }
    return returnAux;
}


/*DIEZ
Retorna un nuevo ArrayList copia del ArrayList original. Verificando que el puntero pList sea
distinto de NULL. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el
nuevo array.**/


ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL; //sera mi nueva lista
    int i;
    int tamanio;

    if(this!=NULL)
    {
        returnAux=al_newArrayList();
        tamanio=this->len(this);
        if(returnAux!=NULL)
        {
            for(i=0;i<tamanio;i++)
            {
                returnAux->add(returnAux,this->get(this,i));
                //returnAux->add(returnAux,this->pElements[i]);
            }
        }

    }

    return returnAux;
}


/*ONCE
Desplaza los elementos e inserta en la posición index. Verificando que tanto el puntero pList como
pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del array.
Si la verificación falla la función retorna (-1) y si tiene éxito (0).**/

 int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux=-1;
    int aux;
    int tamanio;

    if(this!=NULL&&pElement!=NULL) //planteo que sean distintos de NULL
    {
        tamanio=this->len(this); //calculo el tamaño y se lo paso a tamanio
        if(index<tamanio&&index>=0)
        {
           aux=expand(this,index); //le paso la lista y el index a expand
           if(aux==0)
           {
                al_set(this,index,pElement); //Inserta un elemento en el ArrayList, en el índice especificado.
                returnAux=0;
           }
        }
        if(index==tamanio)
        {
            al_add(this,pElement);//Agrega un elemento al final de ArrayList.
        }

    }

    return returnAux;
}

/*DOCE
Retorna el índice de la primera aparición de un elemento (element) en el ArrayList. Verificando
que tanto el puntero pList como pElement sean distintos de NULL. Si la verificación falla o no
encuentra el elemento la función retorna (-1) y si encuentra el elemento retorna su índice.**/


int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux=-1;
    int i;
    int tamanio;
    if(this!=NULL&&pElement!=NULL)
    {
        tamanio=this->len(this); //obtengo el tamaño de la lista y se la paso a tamanio
        for(i=0;i<tamanio;i++) //voy a recorrer toda la lista
        {
            if(pElement==this->pElements[i]) //encontro el elemento a traves de su indice
            {
                returnAux=i; //como lo encontro me va a retornar el indice del elemento
                break;
            }
        }
    }

    return returnAux;
}



/*TRECE
Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero pList sea
distinto de NULL. Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene
elementos (0).**/

int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size==0) //SI SIZE SERA 0 ENTONCES PODRE AGREGAR UN ELEMENTO PORQUE HAY LUGAR LIBRE.
        //if(this->len(this))
        {
            returnAux=1; //SI ESTA EN 0 ENTONCES LE COLOCO UN 1 QUE SERIA EL PRIMER VALOR QUE L AGREGARE
        }
        else
        {
            returnAux=0; //SIGNIFICA QUE CONTIENE ELEMENTOS YA
        }
    }

    return returnAux; //LA VERIFICACION FALLO POR ESO ME RETORNO -1
}




/*CATORCE
Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
de la lista. Verificando que el puntero pList sea distinto de NULL y que index sea positivo e
inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
retorna el elemento.*/


void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    int tamanio;
    if(this!=NULL)
    {
        tamanio=this->len(this); //le paso el tamaño de a lista a tamanio
        if(index>=0&&index<=tamanio)
        {
            returnAux=al_get(this,index);//Retorna un puntero al elemento que se encuentra en el índice especificado
            al_remove(this,index);//luego lo elimina de la lista
        }
    }
    return returnAux;
}

/*QUINCE
Retorna un nuevo ArrayList con el subconjunto de elementos. Verificando que el puntero pList
sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo
array**/



ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    int aux;
    int i;
    if(this!=NULL)
    {
        returnAux=al_newArrayList();
        if(returnAux!=NULL)
        {
             if(from>=0&&to<=this->size&&from<to)
            {
                for(i=from; i<to; i++)
                {
                    aux=al_add(returnAux,this->pElements[i]);
                    if(aux==-1)
                    {
                        returnAux=NULL;
                        break;
                    }
                }
            }
            else
            {
                returnAux=NULL;
            }
        }

    }


    return returnAux ;
}




/*DIECISEIS
Comprueba si los elementos pasados son contenidos por el ArrayList. Verificando que tanto el
puntero pList como pList2 sean distintos de NULL. Si la verificación falla o no encuentra el
elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna
(1).*/


int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux=-1;
    int aux;
    int i;
    int tamAL2;
    if(this!=NULL&&this2!=NULL)
    {
        tamAL2=this2->len(this2);
        returnAux=1;
        for(i=0;i<tamAL2;i++)
        {
            aux=al_contains(this,this2->pElements[i]);
            if(aux==0||aux==-1)
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}


/*DIECISIETE
Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
de determinar que elemento es mas grande que otro y si se debe ordenar de manera
ascendente o descendente. Verificando que tanto el puntero pList como el puntero a la funcion
pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).**/

int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i, j;
    int auxResp = 1;
    void* auxVoid;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(i=0; i<this->size-1; i++)
        {
            for(j=i+1; j<this->size; j++)
            {

                auxResp = pFunc(al_get(this,i),al_get(this,j));
                if(order==1 && auxResp == 1)
                {
                    auxVoid = al_get(this,i);
                    al_set(this,i,al_get(this,j));
                    al_set(this,j,auxVoid);
                }
                else if(order == 0 && auxResp == -1)
                {
                    auxVoid = al_get(this,j);
                    al_set(this,j,al_get(this,i));
                    al_set(this,i,auxVoid);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;

}
/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */

int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void* auxLista;
    if(this!=NULL)
    {
        auxLista= realloc(this->pElements,sizeof(void*)*(this->size+AL_INCREMENT));
        if(auxLista!=NULL)
        {
            this->pElements=auxLista;
            this->reservedSize=this->reservedSize+AL_INCREMENT;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief  Expandir una lista de array
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int auxiliar=0;
    int tamanio;
    int i;
    if(this!=NULL)
    {
         tamanio=this->len(this);
        //tamanio=this->size
        if(index<tamanio&&index>=0)
        {
            if(this->reservedSize==tamanio)
            {
                auxiliar=resizeUp(this);
            }
            if(auxiliar==0)
            {
                for(i=tamanio;i>index;i--)
                {
                    this->pElements[i]=this->pElements[i-1];
                }
                this->size++;
                returnAux=0;
            }
        }

    }

    return returnAux;
}


/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */

int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i, auxResp, flag = 0;
    void* auxElem = NULL;
    if(this != NULL && index < this->size && index >-1)
    {
        for(i=index; i<this->size-1; i++)
        {
            auxElem=al_get(this,i+1);
            if(auxElem!=NULL)
            {
                auxResp=al_set(this,i,auxElem);
                if(auxResp!=0)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag!=1)
        {
            this->size--;
            returnAux = 0;
            auxResp=resizeDown(this);
            if (auxResp != 0)
            {
                returnAux = -1;
            }
        }
    }
    return returnAux;
}

/** \brief Decrement the number of elements in pList in Size + AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->reservedSize>this->size+AL_INCREMENT) //if(this->reservedSize-AL_INCREMENT>this->size)
        {
            this->reservedSize-=AL_INCREMENT;
        }
        returnAux = 0;
    }
    return returnAux;
}
