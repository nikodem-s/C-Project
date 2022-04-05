//
// Created by nikos on 01.12.2021.
//
#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include "Wyjatki.h"
#include "Firma.h"
#ifndef PROJECT_PRACOWNICY_H
#define PROJECT_PRACOWNICY_H
using namespace std;

class Pracownicy{

private:
    double wynagrodzenie;
    int ID;
    string name;
    string surname;
    string stanowisko;
    string umowa;
    bool stan;
    bool wolne;
    int temp_wolne = 0;
protected:
    int chorobowe = 0 ;
    int przepracowane_dni;
    int pozostale_dni_wolne;
    int pozostale_chorobowe;
    int wypite_kawy = 0;
    int placa;
    //KONSTRUKTORY
public:
    Pracownicy(string &x,string &naz, int y,string &stanowisko);
    Pracownicy();
    virtual ~Pracownicy();
    //METODY
    void CoffeTime();
    virtual void WorkFromHome(int months);
    virtual void EndWork();
    virtual void StartWork(int);
    virtual int TakeDayOff(int);
    virtual void setPlaca(string)=0; //dla kazdego inaczej to wyglada, wiec funkcja czysto wirtualna
    virtual int L4(int); //zostawiam virtual bo jest troche inne dla Stazysty
    void End_L4();
    //GETTERY I SETTERY
    void setUmowa(const string &umowa_){this->umowa = umowa_;}
    void setStan(const bool &stan_){this->stan=stan_;}
    void setWolne(const bool &wolne_){this->wolne = wolne_;}
    void setWynagrodzenie(double wynagrodzenie_){this->wynagrodzenie=wynagrodzenie_;}
    //////////////////////////////////
    bool getStan()const{return stan; }
    string getUmowa()const{return umowa;}
    bool getWolne()const{return wolne;}
    int getId() const{return ID;}
    double getWynagrodzenie() const{return wynagrodzenie;}
    /////////////////////////////////
    friend ostream &operator<<(ostream &os, const Pracownicy &pracownicy);
    friend istream &operator>>(istream &input,Pracownicy &pracownicy);
    static bool compare(Pracownicy* a,Pracownicy* b);
    static bool compareASC(Pracownicy* a,Pracownicy* b);
    static bool compareNameSurname(Pracownicy* a, Pracownicy* b);
    static bool comparePosition(Pracownicy* a, Pracownicy* b);
};

#endif //PROJECT_PRACOWNICY_H
