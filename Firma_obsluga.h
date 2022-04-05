//
// Created by nikos on 05.01.2022.
//

#ifndef SALANIKODEM_ETAP1_FIRMA_OBSLUGA_H
#define SALANIKODEM_ETAP1_FIRMA_OBSLUGA_H
#include "Wyjatki.h"
#include "Pracownicy.h"
#include "Firma.h"
class Firma_obsluga {
public:
    static std::ifstream * standard_in;
    static bool read_standardIN;
    static void AddWorker(Firma &firma);
    static void FireWorker(Firma &firma);
    static void PrintOneOrMore(Firma &firma,int choice);
    static string readString();
    static int readID();
    static int readValue();
    static string Rodzaj_umowy();
    static string setStanowisko();
    static void SaveFile(Firma &firma,ofstream &myfile);
    static void ReadFile(Firma &firma,ifstream &infile);
    static int getWorkDays(int);
    static void sortVector(Firma &firma);
};


#endif //SALANIKODEM_ETAP1_FIRMA_OBSLUGA_H
