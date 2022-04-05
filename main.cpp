#include <iostream>
#include <thread>
#include <sstream>
#include "Wyjatki.h"
#include "Pracownicy.h"
#include "Firma.h"
#include "Firma_obsluga.h"
#include "Praca_obsluga.h"
using namespace std;
bool Firma_obsluga::read_standardIN = false;
std::ifstream  * Firma_obsluga::standard_in = nullptr;
int main(int argc, char *argv[]) {
    Firma firma;
    int wybor;
    ofstream myfile;
    ifstream infile;
    if(argc==2) {
        ifstream STDIN;
        string kierowanei;
        STDIN.open(argv[1],ios::in);
        if(!STDIN.good()){
            cout<<endl<<"CAN'T READ THAT FILE";
        }
        Firma_obsluga::standard_in = &STDIN;
        Firma_obsluga::read_standardIN = true;
        bool a = true;
        while(a){
            cout << "\n\n1.Hire an emploee\n2.Fire an emploee\n3.Print employee with entered ID\n"
                    "4.Print list of emplyees\n5.Sort\n6.Go to emplyee menu\n7.Save\n"
                    "8.Read data\n9.End program\nChoose action:";
            getline(STDIN,kierowanei);
            switch (stoi(kierowanei)) {
                case 1: {
                    Firma_obsluga::AddWorker(firma);
                    break;
                }
                case 2: {
                    Firma_obsluga::FireWorker(firma);
                    break;
                }
                case 3: {
                    Firma_obsluga::PrintOneOrMore(firma,1);
                    break;
                }
                case 4: {
                    Firma_obsluga::PrintOneOrMore(firma,2);
                    break;
                }
                case 5:{
                    Firma_obsluga::sortVector(firma);
                    break;
                }
                case 6:{
                    bool b = true;
                    string kierowanie2;
                    do{
                        cout << "\n1.Start to work\n2.End work\n3.Medical leave\n4.Take day off\n5.End medical leave"
                                "\n6.Drink coffe\n7.End vacation\n8.Work from home\n9.Go back to Company menu\nChoose action:";
                        getline(STDIN,kierowanie2);
                        switch (stoi(kierowanie2)){
                            case 1: {
                                Praca_obsluga::StartWork(firma);
                                break;
                            }
                            case 2: {
                                Praca_obsluga::FinishWork(firma);
                                break;
                            }
                            case 3: {
                                Praca_obsluga::L4(firma);
                                break;
                            }
                            case 4: {
                                Praca_obsluga::TakeDayOff(firma);
                                break;
                            }
                            case 5: {
                                Praca_obsluga::EndL4(firma);
                                break;
                            }
                            case 6: {
                                Praca_obsluga::CoffeTime(firma);
                                break;
                            }
                            case 7: {
                                Praca_obsluga::BackToWork(firma);
                                break;
                            }
                            case 8: {
                                Praca_obsluga::WorkFromHome(firma);
                                break;
                            }
                            case 9:{
                                b = false;
                                break;
                            }
                            default: {
                                cout << endl << "Zly wybor! Wybierz jeszcze raz!";
                                break;
                            }
                        }

                    }while(b);
                }
                case 7: {
                    try {
                        Firma_obsluga::SaveFile(firma, myfile);
                    } catch (SaveError &saveError) {
                        cout<<endl<<saveError.message;
                    }
                    break;
                }
                case 8: {
                    try {
                        Firma_obsluga::ReadFile(firma, infile);
                    }catch (ReadError &readError){
                        cout<<endl<<readError.message;
                    }
                    break;
                }
                case 9:{
                    a = false;
                    break;
                }
            }
            //a = false;
        }
    }
    else{
        do {
            cout << "\n\n1.Hire an employee\n2.Fire an emploee\n3.Print employee with entered ID\n"
                    "4.Print list of employees\n5.Sort\n6.Go to emplyee menu\n7.Save\n"
                    "8.Read data\n9.End program\nChoose action:";
            wybor = Firma_obsluga::readID();
            switch (wybor) {
                case 1: {
                    Firma_obsluga::AddWorker(firma);
                    break;
                }
                case 2: {
                    Firma_obsluga::FireWorker(firma);
                    break;
                }
                case 3: {
                    Firma_obsluga::PrintOneOrMore(firma,1);
                    break;
                }
                case 4: {
                    Firma_obsluga::PrintOneOrMore(firma,2);
                    break;
                }
                case 5:{
                    Firma_obsluga::sortVector(firma);
                    break;
                }
                case 6: {
                    int wybor2;
                    do {
                        cout << "\n1.Start to work\n2.End work\n3.Medical leave\n4.Take day off\n5.End medical leave"
                                "\n6.Drink coffe\n7.End vacation\n8.Work from home\n9.Go back to Company menu\nChoose action:";
                        wybor2 = Firma_obsluga::Firma_obsluga::readID();
                        switch (wybor2) {
                            case 1: {
                                Praca_obsluga::StartWork(firma);
                                break;
                            }
                            case 2: {
                                Praca_obsluga::FinishWork(firma);
                                break;
                            }
                            case 3: {
                                Praca_obsluga::L4(firma);
                                break;
                            }
                            case 4: {
                                Praca_obsluga::TakeDayOff(firma);
                                break;
                            }
                            case 5: {
                                Praca_obsluga::EndL4(firma);
                                break;
                            }
                            case 6: {
                                Praca_obsluga::CoffeTime(firma);
                                break;
                            }
                            case 7: {
                                Praca_obsluga::BackToWork(firma);
                                break;
                            }
                            case 8: {
                                Praca_obsluga::WorkFromHome(firma);
                                break;
                            }
                            default: {
                                cout << endl << "Zly wybor! Wybierz jeszcze raz!";
                                break;
                            }
                        }
                    }while (wybor2 != 9);
                    break;
                    }

                case 7: {
                    try {
                        Firma_obsluga::SaveFile(firma, myfile);
                    } catch (SaveError &saveError) {
                        cout<<endl<<saveError.message;
                    }
                    break;
                }
                case 8: {
                    try {
                        Firma_obsluga::ReadFile(firma, infile);
                    }catch (ReadError &readError){
                        cout<<endl<<readError.message;
                    }
                    break;
                }
                case 9: {
                    break;
                }
                default: {
                    cout << endl << "\nZly wybor! Wybierz jeszcze raz:";
                }
            }
        } while (wybor != 9);
    }
    return 0;
}


