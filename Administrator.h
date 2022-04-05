//
// Created by nikos on 27.12.2021.
//

#ifndef SALANIKODEM_ETAP1_ADMINISTRATOR_H
#define SALANIKODEM_ETAP1_ADMINISTRATOR_H
#include <string>
#include <iostream>
#include "Pracownicy.h"
class Administrator : public Pracownicy{

public:
    Administrator();
    ~Administrator();
    Administrator(std::string &x,std::string &naz, int y,std::string &stanowisko,std::string &umowa);
    void setPlaca(string);
};


#endif //SALANIKODEM_ETAP1_ADMINISTRATOR_H
