//
// Created by nikos on 21.12.2021.
//
#include "Analityk.h"
#include <iostream>

using namespace std;

Analityk::Analityk(string &x, string &naz, int y, string &stanowisko, string &umowa) : Pracownicy(x,naz,y,stanowisko) {

    setUmowa(umowa);
}

Analityk::Analityk():Pracownicy(){}

void Analityk::setPlaca(string umowa_) {
    if (umowa_ == "O-PRACE")
        placa = 44;
    else if (umowa_ == "ZLECENIE")
        placa = 32;
    else if (umowa_ == "DZIELO")
        placa = 28;
}
void Analityk::WorkFromHome(int months) {
    StartWork(months);
}

Analityk::~Analityk()=default;


