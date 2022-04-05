//
// Created by nikos on 05.01.2022.
//

#include "Firma_obsluga.h"
#include <string>
#include <sstream>
#include <regex>
void Firma_obsluga::AddWorker(Firma &firma){
    int id;
    string name;
    string surname;
    bool checker;
        try {
            do {
                try {
                    cout << endl << "Enter ID: ";
                    id = readID();
                    checker= true;
                } catch (IdError &Id_error) {
                    checker = false;
                    cout << endl << "Throwing an expection: " << Id_error.what();
                }
            } while (!checker);
            do {
                try {
                    cout << endl << "Enter name: ";
                    name = readString();
                    checker = true;
                } catch (stringError &stringError) {
                    checker = false;
                    cout << endl << "Throwing an expection: " << stringError.message;
                }
            } while (!checker);
            do {
                try {
                    cout << endl << "Enter surname: ";
                    surname = readString();
                    checker = true;
                } catch (stringError &stringError) {
                    checker = false;
                    cout << endl << "Throwing an expection: " << stringError.message;
                }
            } while (!checker);
            string stanowisko = setStanowisko();
            if (stanowisko == "KSIEGOWY") {
                string umowa = "O-PRACE";
                firma.AddWorker(name, surname, id, stanowisko, umowa);
            } else {
                string umowa = Rodzaj_umowy();
                firma.AddWorker(name, surname, id, stanowisko, umowa);
            }
        } catch (IdDuplicate &idDuplicate){
            cout << endl << "Throwing an expection: " << idDuplicate.message;
        }
}
void Firma_obsluga::FireWorker(Firma &firma){
    try {
        cout << endl << "Enter ID: ";
        int id = readID();
        firma.FireWorker(id);
    } catch (NoID &noID) {
        cout << endl << "Throwing an expection: " << noID.message;
    }catch (EmptyBase &emptyBase){
        cout<<endl<<"Throwing an expection: "<<emptyBase.message;
    }
}
void Firma_obsluga::PrintOneOrMore(Firma &firma,int choice){
    int id;
    if (choice == 1) {
        try {
            cout << endl << "Enter ID: ";
            id = readID();
            firma.PrintOne(id);
        }catch (NoID &noID){
            cout<<endl<<"Throwing an expection: "<<noID.message;
        }catch (EmptyBase &emptyBase){
            cout<<endl<<"Throwing an expection: "<<emptyBase.message;
        }
    }
    if (choice == 2) {
        try {
            firma.Print();
        } catch (EmptyBase &emptyBase) {
            cout<<endl<<"Throwing an expection: "<<emptyBase.message;
        }
    }
}
string Firma_obsluga::readString() {
    string linia;
    if(!read_standardIN) {
        getline(cin, linia);
    }else {
        getline(*standard_in, linia);
    }//https://docs.microsoft.com/pl-pl/dotnet/standard/base-types/regular-expression-language-quick-reference
    bool noLetters = !regex_match(linia,std::regex("^[A-Za-z]+$"));
    if(noLetters)                           //wyrazenie regularne: [A-Z], takie cos dopasowuje znak z ciagu od A-Z
        throw stringError();                //znaczek ^ mowi nam ze dopasowanie musi wystapic na poczatku ciagu
                                            //znaczek $ mowi ze dopasowanie musi wystąpić na końcu ciągu
    return linia;
}
int Firma_obsluga::readID(){
    string id;
    if(!read_standardIN) {
        getline(cin, id);
    }else{
        getline(*standard_in,id);
    }

    bool  noINT = !regex_match(id, std::regex("^[0-9]+$"));
    if(noINT)
        throw IdError();
    if(stoi(id)<300 && stoi(id)>0)
        return stoi(id);
    throw IdError();

}
string Firma_obsluga::Rodzaj_umowy(){
    string umowa = " ";
    int choice;
    do{

            try {                                   //zostawiam po polsku
                cout << "\nChoose type of contract:\n1 - Umowa o prace\n2 - Umowa zlecenie\n3 - Umowa o dzielo\nWybor: ";
                choice = readValue();

            } catch (intError &intError) {
                choice = 0;
                cout << endl << "THROWING EXPECTION: " << intError.message;
            }

        switch(choice) {
                case 0:{
                    break;
                }
            case 1: {
                umowa = "O-PRACE";
                break;
            }
            case 2: {
                umowa = "ZLECENIE";
                break;
            }
            case 3: {
                umowa = "DZIELO";
                break;
            }
            default: {
                cout << "\nThere's no choice like that. Choose one more time: ";
                break;
            }
        }
    }while(umowa == " ");
    return umowa;
}
string Firma_obsluga::setStanowisko(){
    string stanowisko = " ";
    int choice;
    do {
        try {
            cout<< "\nChoose job position:\n1.Programista\n2.Stazysta\n3.Administrator\n"
                   "4.Analityk\n5.Ksiegowy\nWybor: ";
            choice = readValue();
        }catch (intError &intError) {
            choice = 0;
            cout << endl << "THROWING EXPECTION: " << intError.message;
        }
        switch (choice) {
            case 0:{
                break;
            }
            case 1: {
                stanowisko = "PROGRAMISTA";
                break;
            }
            case 2: {
                stanowisko = "STAZYSTA";
                break;
            }
            case 3: {
                stanowisko = "ADMINISTRATOR";
                break;
            }
            case 4: {
                stanowisko = "ANALITYK";
                break;
            }
            case 5: {
                stanowisko = "KSIEGOWY";
                break;
            }
            default: {
                cout<< "\nWRONG CHOICE. CHOOSE ONE MORE TIME: ";
                break;
            }
        }
    } while (stanowisko==" ");
    return stanowisko;
}
void Firma_obsluga::SaveFile(Firma &firma,ofstream &myfile){
    if(firma.getPracownicy().empty()){
        throw SaveError();
    }else {
        myfile.open("baza.txt",ios::out);
        cout<<endl<<"SAVING TO baza.txt";
        for (auto &k: firma.getPracownicy()) {
            myfile << *k << "\n";
        }
        myfile.close();
    }
}
void Firma_obsluga::ReadFile(Firma &firma,ifstream &infile){
    infile.open("baza.txt",ios::in);
    if (infile.fail()) {
        throw ReadError();
    }
    else{
        cout << endl << "READING FROM baza.txt";
        int id, chorbowe, wolne_dni;
        string imie, nazwisko, umowa, stanowisko;
        double wynagrodzenie;
        while (infile>>id>>imie>>nazwisko>>stanowisko>>wynagrodzenie>>chorbowe>>wolne_dni>>umowa) {//czytanie do konca pliku
            std::ostringstream ss;
            ss<<id<<" "<<imie<<" "<<nazwisko<<" "<<stanowisko<<" "<<wynagrodzenie<<" "<<chorbowe<<" "<<wolne_dni<<" "<<umowa;
            cout<<endl<<ss.str();
            std::istringstream ss2(ss.str());
            if(stanowisko=="PROGRAMISTA"){
                auto *p = new Programista();
                ss2>>(*p);
                firma.AddWorker(*p);
            }else if(stanowisko =="ADMINISTRATOR") {
                auto *p = new Administrator();
                ss2>>(*p);
                firma.AddWorker(*p);
            }
            else if(stanowisko=="ANALITYK") {
                auto *p = new Analityk();
                ss2>>(*p);
                firma.AddWorker(*p);
            }else if(stanowisko=="STAZYSTA"){
                auto *p = new Stazysta();
                ss2>>(*p);
                firma.AddWorker(*p);
            }
            else if(stanowisko =="KSIEGOWY"){
                auto *p = new Ksiegowy();
                ss2>>(*p);
                firma.AddWorker(*p);
            }
        }
        infile.close();
    }
}

int Firma_obsluga::readValue() {
    string value;
    if(!read_standardIN) {
        getline(cin, value);
    }else{
        getline(*standard_in,value);
    }
    bool contains_illegal_signs; //
    contains_illegal_signs = !regex_match(value,std::regex("^[0-9]+$"));

    if(contains_illegal_signs)
        throw intError();
    return stoi(value);
}

int Firma_obsluga::getWorkDays(int month) {
    if(month >=13)
        month =1;
    if(month==2)
        return 28;
    else if(month == 1 ||month == 5||month == 7||month == 8||month == 10||month == 12)
        return 31;
    else
        return 30;
}

void Firma_obsluga::sortVector(Firma &firma) {
    int id;
    try {
        cout << endl << "Choose sorting:\n1.Descending by ID\n2.Ascending by ID\n3.Sort by Name\n4.Sort by position\nYour choice: ";
         id = readValue();
        switch(id){
            case 1:{
                firma.Sorting();
                break;
            }
            case 2:{
                firma.Sorting2();
                break;
            }
            case 3:{
                firma.SortingName();
                break;
            }
            case 4:{
                firma.SortingPosition();
                break;
            }
            default:{
                cout<<endl<<"No choice like that!";
                break;
            }
        }
        cout<<endl<<"###########SORTED##########";
        PrintOneOrMore(firma,2);
    }catch (intError &intError){
        cout<<endl<<"THROWING AN EXPECTION: "<<intError.message;
    }catch (EmptyBase &emptyBase){
        cout<<endl<<"THROWING AN EXPECTION: "<<emptyBase.message;
    }

}

