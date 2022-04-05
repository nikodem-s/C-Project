//
// Created by nikos on 05.01.2022.
//

#include "Praca_obsluga.h"

void Praca_obsluga::StartWork(Firma &firma) {
    int ajdi;
    int index;
    int months;
        try {
            cout << endl << "Enter ID in order to start work: ";
            ajdi = Firma_obsluga::readID();
            //firma.CheckIfExist(ajdi);
            index = firma.getIndex(ajdi);
            cout << endl << "Enter how many months you want to work: ";
            months = Firma_obsluga::readID();
            firma.getPracownicy()[index]->StartWork(months);
        }catch (IdError &Id_error) {
            cout << endl << "Throwing an expection: " << Id_error.message;
        } catch (NoID &noID) {
            cout << endl << "Throwing an expection: " << noID.message;
        }catch (TooMuchMonthsError &tooMuchMonthsError) {
            cout << endl << "Throwing an expection: " << tooMuchMonthsError.message;
        }catch (AlreadyInWork &alreadyInWork) {
            cout << endl << "Throwing an expection: " << alreadyInWork.message;
        }catch (HasDaysOffError &hasDaysOffError) {
            cout << endl << "Throwing an expection: " << hasDaysOffError.message;
        }catch (L4_Error &l4Error) {
            cout << endl << "Throwing an expection: " << l4Error.message;
        }
}

void Praca_obsluga::FinishWork(Firma &firma) {
    try {
        cout << endl << "Enter ID in order to end work: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);
        firma.getPracownicy()[index]->EndWork();
    }catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    } catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }catch (NoInWork &noInWork) {
        cout << endl << "Throwing an expection: " << noInWork.message;
    }catch (HasDaysOffError &hasDaysOffError) {
        cout << endl << "Throwing an expection: " << hasDaysOffError.message;
    }catch (L4_Error &l4Error) {
        cout << endl << "Throwing an expection: " << l4Error.message;
    }
}

void Praca_obsluga::L4(Firma &firma) {
    try {
        cout << endl << "Enter ID to take sick leave: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);
        cout << endl << "Enter how many days you will be on sick leave: ";
        int days = Firma_obsluga::readID();
        firma.getPracownicy()[index]->L4(days);
    }catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    } catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    } catch (NoMoreL4 &noL4) {
        cout << endl << "Throwing an expection: " << noL4.message;
    }catch (L4_Error &l4Error) {
        cout << endl << "Throwing an expection: " << l4Error.message;
    }catch (HasDaysOffError &hasDaysOffError) {
        cout << endl << "Throwing an expection: " << hasDaysOffError.message;
    }
}

void Praca_obsluga::TakeDayOff(Firma &firma) {
    try {
        cout << endl << "Enter ID to take day-off: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);
        cout << endl << "Enter how many days you want to take off: ";
        int days = Firma_obsluga::readID();
        firma.getPracownicy()[index]->TakeDayOff(days);
    }catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    }catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }catch (NoMoreDaysOff &noMoreDaysOff){
        cout << endl << "Throwing an expection: " << noMoreDaysOff.message;
    }catch (HasDaysOffError &hasDaysOffError) {
        cout << endl << "Throwing an expection: " << hasDaysOffError.message;
    }catch (L4_Error &l4Error) {
        cout << endl << "Throwing an expection: " << l4Error.message;
    }
}

void Praca_obsluga::EndL4(Firma &firma) {
    try {
        cout << endl << "Enter ID to end L4: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);
        firma.getPracownicy()[index]->End_L4();
    }catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    }catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }catch (isNotOnL4 &notOnL4) {
        cout << endl << "Throwing an expection: " << notOnL4.message;
    }

}

void Praca_obsluga::CoffeTime(Firma &firma) {
    try {
        cout << endl << "Enter ID in order to drink coffe: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);
        firma.getPracownicy()[index]->CoffeTime();
    } catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    }catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }catch (NoInWork &noInWork) {
        cout << endl << "Throwing an expection: " << noInWork.message;
    }catch (HasDaysOffError &hasDaysOffError) {
        cout << endl << "Throwing an expection: " << hasDaysOffError.message;
    }catch (L4_Error &l4Error) {
        cout << endl << "Throwing an expection: " << l4Error.message;
    }
}

void Praca_obsluga::BackToWork(Firma &firma) {
    try {
        cout << endl << "Enter ID to finish off: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);   //mozna dodac komunikat jakby czasem stazysta chcial zakonczyc wolne, a on nie moze brac
        firma.getPracownicy()[index]->setWolne(false);  //cos w stylu ten pracownik jest tsazysta nie mog wziac wolnego!
    }catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    }catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }
}

void Praca_obsluga::WorkFromHome(Firma &firma) {
    try {
        cout << endl << "Enter ID to work online: ";
        int ajdi = Firma_obsluga::readID();
        int index = firma.getIndex(ajdi);
        cout << endl << "Enter how many months you want to work from home: ";
        int months = Firma_obsluga::readID();
        firma.getPracownicy()[index]->WorkFromHome(months);
    }catch (IdError &Id_error) {
        cout << endl << "Throwing an expection: " << Id_error.message;
    } catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }catch (TooMuchMonthsError &tooMuchMonthsError) {
        cout << endl << "Throwing an expection: " << tooMuchMonthsError.message;
    }catch (AlreadyInWork &alreadyInWork) {
        cout << endl << "Throwing an expection: " << alreadyInWork.message;
    }catch (HasDaysOffError &hasDaysOffError) {
        cout << endl << "Throwing an expection: " << hasDaysOffError.message;
    }catch (L4_Error &l4Error) {
        cout << endl << "Throwing an expection: " << l4Error.message;
    }
}