//
// Created by nikos on 21.12.2021.
//

#ifndef SALANIKODEM_ETAP1_PROGRAMISTA_H
#define SALANIKODEM_ETAP1_PROGRAMISTA_H
#include <iostream>
#include <string>
#include "Pracownicy.h"
class Programista:public Pracownicy{

public:
    Programista();
    ~Programista();
    Programista(std::string &x,std::string &naz, int y,std::string &stanowisko,std::string &umowa);
    void setPlaca(string);
    void WorkFromHome(int months);
};


#endif //SALANIKODEM_ETAP1_PROGRAMISTA_H
