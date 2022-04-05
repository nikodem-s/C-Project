//
// Created by nikos on 21.12.2021.
//
#include "Programista.h"
#include <thread>

using namespace std;

Programista::Programista(string &x, string &naz, int y, string &stanowisko, string &umowa) : Pracownicy(x,naz,y,stanowisko){

    setUmowa(umowa);
}

Programista::Programista():Pracownicy(){}

void Programista::setPlaca(string umowa_) {
    if (umowa_ == "O-PRACE")
        placa = 50;
    else if (umowa_ == "ZLECENIE")
        placa = 40;
    else if (umowa_ == "DZIELO")
        placa = 30;
}

void Programista::WorkFromHome(int months) {
    StartWork(months);
}

Programista::~Programista()=default;
