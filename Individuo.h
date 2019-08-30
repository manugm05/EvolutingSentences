/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Individuo.h
 * Author: Manuel
 *
 * Created on 29 de agosto de 2019, 19:43
 */

#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <iostream>

class Individuo {
public:
    static const int MAXLIN=20;// (2)
    Individuo();
    Individuo(const Individuo& orig);
    Individuo reproduce(Individuo& ind);
    bool operator<(const Individuo& ind);
    bool operator>(const Individuo& ind);
    void calculaError(std::string resultado);
    void mutar(Individuo& ind);
    int getErrores();
    virtual ~Individuo();
    std::string getLinea() const;
    void setLinea();
private:
    std::string linea="";
    int error=-1;
};

#endif /* INDIVIDUO_H */

