//
// Created by nikos on 02.12.2021.
//
#include "Firma.h"
#include "Firma_obsluga.h"
#include "Pracownicy.h"
#include <istream>
#include <iomanip>
Pracownicy::Pracownicy(string &x,string &naz, int y,string &stanowisko) {
    cout<<endl<<"Pracownicy constructor!";
    this->stanowisko = stanowisko;
    this->name=x;
    this->surname=naz;
    this->ID=y;
    wynagrodzenie = 0.0;
    pozostale_dni_wolne = 26;
    stan = false;
    wolne = false;
    pozostale_chorobowe = 182;
    przepracowane_dni = 0.0;
    placa = 0;
}

Pracownicy::Pracownicy() {//potrzebny w moim programie szczegolnie w celu czytania danych z pliku
    ID=0;
    name = "Nikodem";
    surname = " Sala";
    wynagrodzenie = 0.0;
    pozostale_dni_wolne = 0.0;
    stan = false;
    wolne = false;
    przepracowane_dni = 0.0;
    pozostale_chorobowe = 0.0;
    placa = 0;
}

Pracownicy::~Pracownicy(){
    cout<<endl<<"Pracownicy Destructor!";
}

ostream &operator<<(ostream &os, const Pracownicy &pracownicy) {
    os <<setw(6)<<pracownicy.ID<<setw(12)<<pracownicy.name<<setw(15)<<pracownicy.surname<<setw(15)<<pracownicy.stanowisko<<setw(10)
    <<pracownicy.wynagrodzenie<<setw(12)<<pracownicy.pozostale_chorobowe<<setw(8)<<pracownicy.pozostale_dni_wolne<<setw(12)
    <<pracownicy.umowa;
    return os;
}

istream &operator>>(istream &input, Pracownicy &pracownicy){
    input>>pracownicy.ID>>pracownicy.name>>pracownicy.surname>>pracownicy.stanowisko>>pracownicy.wynagrodzenie
         >>pracownicy.pozostale_chorobowe>>pracownicy.pozostale_dni_wolne>>pracownicy.umowa;
    return input;
}

void Pracownicy::StartWork(int months) {
    if (months <= 12) {
        if (getStan())
            throw AlreadyInWork();
        else if (getWolne())
            throw HasDaysOffError();
        else if (chorobowe>0)
            throw L4_Error();
        else if (!getStan() && !getWolne() && chorobowe == 0) {
            cout << "\nEmployee with ID of - " << getId() << " starts work. ";
            setStan(true);
            for (int i = 0; i < months; i++) {
                przepracowane_dni += Firma_obsluga::getWorkDays(1 + i);//licze od stycznia prace.
            }
        } else
            cout << "\nUNIDENTIFIED PROBLEM";
    } else {
        throw TooMuchMonthsError();
    }
}

void Pracownicy::EndWork() {
    if (!getStan())
        throw NoInWork();
    else if (getWolne())
        throw HasDaysOffError();
    else if(chorobowe>0)
        throw L4_Error();
    else if (getStan() && !getWolne() && chorobowe ==0) {
        setPlaca(getUmowa());
        setWynagrodzenie(0.0);
        double premia = 0.1 * (placa*8*przepracowane_dni);//domyslnie premia jako 10% zarobku od przepracowanych dni
        if(temp_wolne==0){premia = premia;}     //w zaleznosci od tego czy pracowal ciagle, czy bral wolne
        else if(temp_wolne<=2) {premia = premia * 0.8;} //premaij est zwiekszana lub zmniejzana
        else if(temp_wolne<=4){premia = premia * 0.6;}
        else if(temp_wolne<=6){premia = premia * 0.4;}
        else{premia = 0;}
        setWynagrodzenie(przepracowane_dni*8*placa);

        cout<<"\nDays at work: "<<przepracowane_dni - temp_wolne;
        cout<<"\nClean earn: "<< getWynagrodzenie();
        cout<<"\nBonus: "<<premia -(wypite_kawy*8);
        setWynagrodzenie(getWynagrodzenie() -(premia - (wypite_kawy*8)));
        cout<<"\nTotal payment: "<<getWynagrodzenie();
        przepracowane_dni = 0;
        temp_wolne = 0;
        setStan(false);
    }
}

void Pracownicy::End_L4() {
    setPlaca(getUmowa());
    if(chorobowe>0 && !getWolne() && temp_wolne == 0 && !getStan()){
        setWynagrodzenie(chorobowe*0.7*8*placa);
        cout<<endl<<"Salary due for medical leave in amount of: "<<getWynagrodzenie();
        chorobowe = 0;
    }
    else
        throw isNotOnL4();
}

int Pracownicy::L4(int L4_days) {
    if (pozostale_chorobowe < L4_days || pozostale_chorobowe == 0) {
        throw NoMoreL4();
    } else if (!getStan() && !getWolne() && chorobowe == 0) {
        chorobowe = L4_days;
        pozostale_chorobowe = pozostale_chorobowe - L4_days;
    } else if(getStan()){
        cout<<"\nEND YOUR JOB TO GO ON MEDICAL LEAVE";
    }
    else if (chorobowe>0) {
        throw L4_Error();
    }else if(getWolne())
        throw HasDaysOffError();
    return L4_days;
}

void Pracownicy::CoffeTime() {
    if(getStan() && !getWolne() && chorobowe==0){
        wypite_kawy = wypite_kawy + 1;
    }
    else if(!getStan())
        throw NoInWork();
    else if(getWolne())
        throw HasDaysOffError();
    else if(chorobowe>0)
        throw L4_Error();
}

int Pracownicy::TakeDayOff(int days) {
        if (days > pozostale_dni_wolne || pozostale_dni_wolne == 0) {
            throw NoMoreDaysOff();
        } else if (!getWolne() && !getStan() && chorobowe == 0) {
            pozostale_dni_wolne = pozostale_dni_wolne - days;
            cout << endl << pozostale_dni_wolne;
            temp_wolne = days;
            setWolne(true);
            // cout << endl << urlop;
        } else if (getWolne()) {
            throw HasDaysOffError();
        } else if(getStan() && !getWolne()){
            cout<<"\nEmployee needs to end work to leave at request.";
        }else if (chorobowe>0)
            throw L4_Error();
        return days;
    }

void Pracownicy::WorkFromHome(int months){
    cout<<endl<<"Working remotely is available only for Analysts and Programmers!";
}

bool Pracownicy::compare(Pracownicy *a, Pracownicy *b) {
    return a->ID > b->ID;
}

bool Pracownicy::compareASC(Pracownicy *a, Pracownicy *b) {
    return a->ID < b->ID;
}

bool Pracownicy::compareNameSurname(Pracownicy *a, Pracownicy *b) {
    if(a->name != b->name)
    return a->name > b->name;
    else
        return a->surname > b->surname;
}
bool Pracownicy::comparePosition(Pracownicy *a, Pracownicy *b) {
    return a->stanowisko > b->stanowisko;
}