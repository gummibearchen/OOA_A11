//
// Created by Matt on 06.06.18.
//

#ifndef OOA_U_A11_BANK2_BANK_H
#define OOA_U_A11_BANK2_BANK_H

#include <string>
#include "datum.h"
using namespace std;


class Bank {

private:
    //map<int, konto*> _konten;
    //map<int key, kunde* value> _kunden;         //map<int key, kunde* value> _kunden; variablen key und value, hier kann man mit _kunden[3] direkt aufrufen, Inex_OPerator uberladung, man kann auch mit map<string, konto*> _k; kann man auch so holen _k["Max Meier"]

public:

    void schreibenInDatei(string name);
    void lesenAusDatei(string name);
    void girokontoAnlegen(int kundeID, string pin, int betrag, int dispo, double zinssatz, Datum tag = Datum::getCurrentDate());
    void sparkontoAnlegen(int kundeID, string pin, int betrag, double zinssatz, Datum tag = Datum::getCurrentDate());
    void kontoEntfernen(int nr);
    string kontenliste();
    void kundeAnlegen(string name, string ort);
    void kundeEntfernen(int id);
    void kundeBearbeiten(int id, string name, string ort);
    string kundenliste();
    void einzahlen(int kontonr, int betrag, Datum tag = Datum::getCurrentDate());
    void auszahlen(int kontonr, int betrag, Datum tag = Datum::getCurrentDate());
    void ueberweisen(int von, int nach, int betrag, string info, Datum tag = Datum::getCurrentDate());
    void zinsgutschrift(Datum tag = Datum::getCurrentDate());
    bool existiertKonto(int nr);
    bool existiertKunde(int nr);
    string auszug(int nr);


};


#endif //OOA_U_A11_BANK2_BANK_H
