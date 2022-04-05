//
// Created by nikos on 27.12.2021.
//

#include "Ksiegowy.h"
#include <thread>

using namespace std;

Ksiegowy::Ksiegowy(string &x, string &naz, int y, string &stanowisko, string &umowa) : Pracownicy(x,naz,y,stanowisko) {

    setUmowa(umowa);
}

Ksiegowy::Ksiegowy():Pracownicy(){}

void Ksiegowy::setPlaca(string umowa_) {
    placa = 23;
}

Ksiegowy::~Ksiegowy()=default;

