//
// Created by nikos on 05.01.2022.
//

#ifndef SALANIKODEM_ETAP1_PRACA_OBSLUGA_H
#define SALANIKODEM_ETAP1_PRACA_OBSLUGA_H
#include "Firma.h"
#include "Wyjatki.h"
#include "Firma_obsluga.h"

class Praca_obsluga {
public:
    static void StartWork(Firma &firma);
    static void FinishWork(Firma &firma);
    static void L4(Firma &firma);
    static void TakeDayOff(Firma &firma);
    static void EndL4(Firma &firma);
    static void CoffeTime(Firma &firma);
    static void BackToWork(Firma &firma);
    static void WorkFromHome(Firma &firma);
};


#endif //SALANIKODEM_ETAP1_PRACA_OBSLUGA_H
