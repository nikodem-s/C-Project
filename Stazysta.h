//
// Created by nikos on 27.12.2021.
//

#ifndef SALANIKODEM_ETAP1_STAZYSTA_H
#define SALANIKODEM_ETAP1_STAZYSTA_H
#include "Pracownicy.h"

class Stazysta : public Pracownicy {

public:
    Stazysta();
    ~Stazysta();
    Stazysta(std::string &x,std::string &naz, int y,std::string &stanowisko,std::string &umowa);
    void EndWork();
    void StartWork(int);
    int TakeDayOff(int days);
    void setPlaca(string);
    int L4(int);
};


#endif //SALANIKODEM_ETAP1_STAZYSTA_H
