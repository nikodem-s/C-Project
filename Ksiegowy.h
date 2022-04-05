//
// Created by nikos on 27.12.2021.
//

#ifndef SALANIKODEM_ETAP1_KSIEGOWY_H
#define SALANIKODEM_ETAP1_KSIEGOWY_H
#include <iostream>
#include "Pracownicy.h"
class Ksiegowy : public Pracownicy{

public:
    Ksiegowy();
    ~Ksiegowy();
    Ksiegowy(std::string &x,std::string &naz, int y,std::string &stanowisko,std::string &umowa);
    void setPlaca(string);
};


#endif //SALANIKODEM_ETAP1_KSIEGOWY_H
