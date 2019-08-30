/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Individuo.cpp
 * Author: Manuel
 * 
 * Created on 29 de agosto de 2019, 19:43
 */

#include "Individuo.h"
#include <stdlib.h>

Individuo::Individuo() {
}


Individuo::Individuo(const Individuo& orig) : error(orig.error), linea(orig.linea) {
}

Individuo::~Individuo() {
}

std::string Individuo::getLinea() const {
    return linea;
}


void Individuo::mutar(Individuo& ind) {
    double probMutar;
    char mutacion;
    int aux;
    for (int i = 0; i < MAXLIN; i++) {
        probMutar = rand()%100;
        if (probMutar >= 75) {
            aux = rand() % 94;
            mutacion = ' ' + aux;
            ind.linea[i] = mutacion;
        }

    }

}

void Individuo::calculaError(std::string resultado) {
    int error = 0;
    for (int i = 0; i < MAXLIN; i++) {
        if(linea[i]!=resultado[i]) error++;
    }
    this->error = error; //evitar ambiguedad con this

}

/*@brief cruce de individuos
 *@param Ind - individuo
 *@post Individuo "hijo" que comparte caracteristicas de los "padres"
 *@return otro inidividuo
 */

Individuo Individuo::reproduce(Individuo& ind) {
    int prob;
    Individuo hijo;
    for (int i = 0; i < MAXLIN; i++) {
        prob = rand()%100; //0-99
        if (prob <= 55) hijo.linea += linea[i]; // <=55%
        else if (prob <= 99) hijo.linea += ind.linea[i]; // 55%<x<=99%
    }
    mutar(hijo);

    return hijo;
}

bool Individuo::operator<(const Individuo &ind2) 
{ 
    return this->error < ind2.error; 
} 

bool Individuo::operator>(const Individuo& ind) {
    return !(*this < ind);
}

int Individuo::getErrores() {
    return error;
}

//Generador random de caracteres ASCII
void Individuo::setLinea(){
    int aux;
    char random;
    for (int i = 0; i < MAXLIN; i++) {
        aux = rand() % 94;
        random = ' ' + aux;
        linea+=random;
    }

}