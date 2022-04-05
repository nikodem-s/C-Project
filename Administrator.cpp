//
// Created by nikos on 27.12.2021.
//

#include "Administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator(string &x, string &naz, int y, string &stanowisko, string &umowa) : Pracownicy(x,naz,y,stanowisko) {
    cout<<endl<<"Administrator Constructor!";
    pozostale_dni_wolne = 40;
    setUmowa(umowa);
}

Administrator::Administrator():Pracownicy(){}


void Administrator::setPlaca(string umowa_) {
    if (umowa_ == "O-PRACE")
        placa = 60;
    else if (umowa_ == "ZLECENIE")
        placa = 55;
    else if (umowa_ == "DZIELO")
        placa = 45;
}

Administrator::~Administrator(){
    cout<<endl<<"Administrator Destructor!";
}
