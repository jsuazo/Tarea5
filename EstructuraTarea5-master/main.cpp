
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <set>          // std::list
using namespace std;

int infinito = 9999;

//Dado: un grafo con 5 nodos implementado en una tabla (arreglo bidimensional)
//Dado: las columnas de la tabla representan el inicio y las filas el destino
//Dado: las aristas tienen un valor de 0 si apuntan a ellas, infinito si no esta conectada y de lo contrario significa que sí hay una conexion entre los nodos

//Devuelve verdadero si existe al menos un camino para llegar desde el nodo inicio hasta el nodo destino
bool existeCamino(int grafo[5][5], int inicio, int destino)
{
    //En esta funcion trabaje con Gadi Orellana

    if(grafo[destino][inicio] != infinito)
        return false;

    return true;

    /*En el if se si existe camino entre los nodos si hay infinito si lo hay retorna false*/

    }

//Ej. si la profundidad es igual a 0 solo se devuelve el nodo inicial
//Ej. si la profundidad es igual a 1 se devuelve el nodo inicial y sus adjacentes
//Ej. si la profundidad es igual a 2 se devuelve el nodo inicial, sus adjacentes y los adjacentes de los adjacentes


set<int> obtenerAdjacentes(int grafo[5][5], int inicio, int profundidad)
{
    set<int> respuesta;

// se inserta el el inicio en el grafo
respuesta.insert(inicio);
// se hace la primera evaluacion
    if(profundidad<=0)//Verifica si la profundidad es igual a 0 solo se devuelve el nodo inicial
        return respuesta;

         for(int i=0; i<5; i++)
            if(grafo[inicio][i] > 0 && grafo[inicio][i] < infinito)
                respuesta.insert(i);

    /*Se hace un ciclo para que recorra el grafo en el cual verifica si es abjacente contal y grafo[inicio][i] no sea igual que 0 ni infinito al ser asi se ingresan las adjacentes al set*/

    if (profundidad == 1)//Verifica si la profundidad es igual a 1 se devuelve el nodo inicial y sus adjacentes
            return respuesta;

          for(int i=0; i<5; i++)
            if(grafo[inicio][i] > 0 && grafo[inicio][i] < infinito)
              for(int j=0; j<5; j++)
                    if(grafo[i][j] > 0 && grafo[i][j] < infinito)
                        respuesta.insert(j);

                        /*Se hace un ciclo para que recorra el grafo en el cual verifica si es abjacente contal y grafo[inicio][i] no sea igual que 0 ni infinito al ser asi
                        inicializa el otro ciclo que hace lo mismo nada mas que de manera mas profunda asi recorre todo el grafo,luego verifica si grafo[i][j]no sea 0 ni infinito para que se ingresen las adjacentes de las adjacentes al set*/

            return respuesta;//Como la profundidad no es ni 0 ni 1 entonces devuelvo el nodo inicial, las adjacentes y sus adjacentes correspondientes


}

int main ()
{
    //Trabaje con Gadi Orellana
    evaluar();

    return 1;
}
