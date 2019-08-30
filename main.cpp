/*
 *      == Evolving Sentences ==
 *      Un intento de Algoritmo Genético
 *      @mg0097 Twitter
 *      2019
 * 
 * 
 * 1) Cambia, si quieres, el maximo de la poblacion generada (MAXPBO)
 * 2) En Invividuo.h, pon en MAXLIN el numero de caracteres que componen tu palabra
 * 
 * -Cuando pueda intentare que no se tengan que hacer esos pasos previos ^^
 */

#include <cstdlib>
#include <time.h>
#include <vector> 
#include <algorithm>

#include "Individuo.h"
using namespace std;
const int MAXPOB = 1000; //(1)

/*@brief Generador de enteros (pseudo)aleatorios
 *@param inicio, fin - enteros
 *@return un nunmero entero, entre inicio y fin.
 */
int numero_aleatorio(int inicio, int fin){
    int rango = (fin-inicio)+1;
    int aleatorio = rand()%rango;
    return aleatorio;
}


int main(int argc, char** argv) {
    int gen = 0;
    bool encontrado = false;
    string resultado;
    srand(time(0));
    cout << "Introduce una frase a la que quieres que llegue algun individuo: ";
    getline(cin >> ws, resultado);
    vector<Individuo> poblacion;

    for (int i = 0; i < MAXPOB; i++) {
        poblacion.push_back(Individuo());
        poblacion[i].setLinea();
    }
    
    while (!encontrado) {
        gen++;
        for (int i = 0; i < MAXPOB; i++) {
            poblacion[i].calculaError(resultado);
        }
        //ordena de menor a mayor numero de errores
        sort(poblacion.begin(), poblacion.end());


        //Si el primero tiene 0 errores (fitness = 0) hemos acabado!
        if(poblacion[0].getErrores() == 0){
            encontrado = true;
            break;
        }
        cout << "\n==== GENERACION " << gen << " ====" << endl
             << "Mejor especimen:" << poblacion[0].getLinea() << endl
             << "Errores: " << poblacion[0].getErrores() << endl;
        vector<Individuo> sig_pob;
        //Mantenemos el 10% de los mejores
        for (int i = 0; i < MAXPOB*0.2;i++) {
            sig_pob.push_back(poblacion[i]);
        }
        
        //Reproduccion de dos individuos aleatorios hasta llenar el 90% restante.
        int alet;
        for (int i = 0; i < MAXPOB*0.8; i++) {
            alet = numero_aleatorio(0,40);
            Individuo padre = poblacion[alet];
            alet = numero_aleatorio(0,40);
            Individuo madre = poblacion[alet];
            Individuo hijo = padre.reproduce(madre);
            sig_pob.push_back(hijo);
        }
        //Copiamos la poblacion actual al vector principal.
        poblacion = sig_pob;
    }
    
    cout << "\n====GENERACION FINAL====\nNumero Generacion: " << gen 
            << "\nEspecimen: " << poblacion[0].getLinea() 
            << "\nObjetivo: " << resultado;

    return 0;
}