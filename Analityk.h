//
// Created by nikos on 27.12.2021.
//

#ifndef SALANIKODEM_ETAP1_ANALITYK_H
#define SALANIKODEM_ETAP1_ANALITYK_H
#include "Pracownicy.h"
#include <iostream>

class Analityk : public Pracownicy{

public:
    Analityk();
    ~Analityk();
    Analityk(std::string &x,std::string &naz, int y,std::string &stanowisko,std::string &umowa);
    void setPlaca(string);
    void WorkFromHome(int months);
};


#endif //SALANIKODEM_ETAP1_ANALITYK_H
