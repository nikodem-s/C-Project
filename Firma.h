//
// Created by nikos on 02.12.2021.
//

#include <algorithm>
#include <vector>
#include <iostream>
#ifndef PROJECT_FIRMA_H
#define PROJECT_FIRMA_H
#include "Wyjatki.h"
#include "Pracownicy.h"
#include "Programista.h"
#include "Administrator.h"
#include "Stazysta.h"
#include "Ksiegowy.h"
#include "Analityk.h"
class Firma{
private:
    vector<Pracownicy*> pracownicy;
public:
    ~Firma();
    bool CheckIfExist(int id);
    const vector<Pracownicy *> &getPracownicy() const;
    void AddWorker(string &nameX,string &nazwisko,int &idX,string &stanowisko,string &umowa);
    void AddWorker(Pracownicy &p1);
    void Print();
    void FireWorker(int id);
    void PrintOne(int id);
    int getIndex(int id);
    void Sorting();
    void Sorting2();
    void SortingName();
    void SortingPosition();
};

#endif //PROJECT_FIRMA_H
