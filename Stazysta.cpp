#include "Stazysta.h"
#include "Firma_obsluga.h"
#include <iostream>
using namespace std;

Stazysta::Stazysta(string &x, string &naz, int y, string &stanowisko, string &umowa) : Pracownicy(x,naz,y,stanowisko) {

    setUmowa(umowa);
    pozostale_dni_wolne = 0;
}

Stazysta::Stazysta():Pracownicy(){}

void Stazysta::StartWork(int months) {
    if (months <= 12) {
        if (getStan())
            throw AlreadyInWork();
        else if (chorobowe>0)
            throw L4_Error();
        else if (!getStan() && chorobowe == 0) {
            cout << "\nWorker of ID - " << getId() << " starts to work. ";
            setStan(true);
            for (int i = 0; i < months; i++) {
                przepracowane_dni += Firma_obsluga::getWorkDays(1 + i);//licze od stycznia prace.
            }
        } else
            cout << "\nNiezidentyfikowany problem";
    } else {
        throw TooMuchMonthsError();
    }
}

void Stazysta::EndWork() {
    if (!getStan())
        throw NoInWork();
    else if (getWolne())
        throw HasDaysOffError();
    else if(chorobowe>0)
        throw L4_Error();
    else if (getStan() && !getWolne() && chorobowe ==0) {
        setPlaca(getUmowa());
        setWynagrodzenie(0.0);
        setWynagrodzenie(przepracowane_dni*8*placa - (wypite_kawy*6));
        cout<<"\nThis worker earned "<<getWynagrodzenie()<<"\nDays in work: "
            <<przepracowane_dni;
        przepracowane_dni = 0;
        setStan(false);
    }
}

int Stazysta::TakeDayOff(int days) {
    cout<<"\nApprentice can't take day off!";
    return days;
}

void Stazysta::setPlaca(string umowa_) {
    if (umowa_ == "O-PRACE")
        placa = 35;
    else if (umowa_ == "ZLECENIE")
        placa = 25;
    else if (umowa_ == "DZIELO")
        placa = 20;
}

int Stazysta::L4(int L4_days) {
    if (pozostale_chorobowe < L4_days || pozostale_chorobowe == 0) {
        throw NoMoreL4();
    } else if (!getStan() && chorobowe == 0) {
        chorobowe = L4_days;
        pozostale_chorobowe = pozostale_chorobowe - L4_days;
    } else if(getStan()){
        cout<<"\nEnd work to start medical leave: ";
    }
    else if (chorobowe>0) {
        throw L4_Error();
    }
    return L4_days;
}

Stazysta::~Stazysta()=default;
