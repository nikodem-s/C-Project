//
// Created by nikos on 02.12.2021.
//
#include "Firma.h"
#include "Pracownicy.h"
#include <iostream>
#include <iomanip>
//enum Stanowisko{PROGRAMISTA=0,ADMINISTRATOR=1,STAZYSTA=2,KSIEGOWY=3,ANALITYK=4};
void Firma::AddWorker(string &nameX,string &nazwisko,int &idX,string &stanowisko,string &umowa) {
    if(!CheckIfExist(idX)) { //zeby nie mozna bylo uzyc tego samego ID dla dwoch pracownikow
        if(stanowisko=="PROGRAMISTA")
            pracownicy.push_back(new Programista(nameX,nazwisko,idX,stanowisko,umowa));
        else if(stanowisko == "ADMINISTRATOR")
            pracownicy.push_back(new Administrator(nameX,nazwisko,idX,stanowisko,umowa));
        else if(stanowisko == "STAZYSTA")
            pracownicy.push_back(new Stazysta(nameX,nazwisko,idX,stanowisko,umowa));
        else if(stanowisko == "KSIEGOWY")
            pracownicy.push_back(new Ksiegowy(nameX,nazwisko,idX,stanowisko,umowa));
        else if(stanowisko == "ANALITYK")
            pracownicy.push_back(new Analityk(nameX,nazwisko,idX,stanowisko,umowa));
    }
    else
        throw IdDuplicate();
}
void Firma::AddWorker(Pracownicy &p1){
        pracownicy.push_back(&p1);
}
void Firma::Print() {
    if(pracownicy.empty())
        throw EmptyBase();
    else {
        cout <<left<< "\n"<<setw(6)<<"ID"<<setw(12)<<"IMIE"<<setw(15)<<"NAZWISKO"<<setw(15)<<"STANOWISKO"<<setw(10)<<"PENSJA"
        <<setw(12)<<"CHOROBOWE"<<setw(8)<<"WOLNE"<<setw(12)<<"UMOWA";
        for (auto &k: pracownicy) {
            cout << "\n" <<left<< *k;
        }
    }
}
bool Firma::CheckIfExist(int id){
        for (auto &k: pracownicy) {
            if (k->getId() == id) {
                return true;
            }
        }
    return false;
}
void Firma::FireWorker(int id){
    if(getPracownicy().empty())
        throw EmptyBase();
    else if(!CheckIfExist(id))
        throw NoID();
    else {
        cout << "\nFiring worker of ID - " << pracownicy[ getIndex(id)]->getId();
        pracownicy.erase(pracownicy.begin() +  getIndex(id));
    }
}


void Firma::PrintOne(int id){
    if(getPracownicy().empty())
        throw EmptyBase();
    else if(CheckIfExist(id)) {
        cout <<left<< "\n"<<setw(6)<<"ID"<<setw(12)<<"IMIE"<<setw(15)<<"NAZWISKO"<<setw(15)<<"STANOWISKO"<<setw(10)<<"PENSJA"
             <<setw(12)<<"CHOROBOWE"<<setw(8)<<"WOLNE"<<setw(12)<<"UMOWA";
        for (auto &k: pracownicy) {
            if (k->getId() == id) {
                cout << endl << *k;
                break;
            }
        }
    }
    else
        throw NoID();

}
int Firma::getIndex(int id){
    int index_of_vector = 0;
    if(!CheckIfExist(id))
        throw NoID();
    else {
        for (auto &k: pracownicy) {
            if (k->getId() == id)
                break;
            index_of_vector++;
        }
    }
    return index_of_vector;
}
const vector<Pracownicy *> &Firma::getPracownicy() const {
    return pracownicy;
}
Firma::~Firma() {
    cout<<"Firma Destructor"; //pierwszy odpala sie ten destruktor, nastepnie konstruktor
    for(auto & i : pracownicy){ //klasy Pracownicy - a na koncu destruktor z danej klasy pochodnej do pracownika
        delete i;               //taka kolejnosc dla kazdej iteracji tej pętli
    }
}

void Firma::Sorting() {
    std::sort(pracownicy.begin(),pracownicy.end(),Pracownicy::compare);
}

void Firma::Sorting2() {
    std::sort(pracownicy.begin(),pracownicy.end(),Pracownicy::compareASC);
}

void Firma::SortingName() {
    std::sort(pracownicy.begin(), pracownicy.end(),Pracownicy::compareNameSurname);
}
void Firma::SortingPosition(){
    std::sort(pracownicy.begin(), pracownicy.end(),Pracownicy::comparePosition);
}
