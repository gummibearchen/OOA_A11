
// *******************************************************************
// konto.h
// *******************************************************************

#ifndef _KONTO_H
#define _KONTO_H

#include <iostream>
#include <string>
#include <vector>
#include "kontobewegung.h"
using namespace std;

class Konto {
protected:
    string inhaber, nr, pin;
    Datum letzteAenderung;
    int stand;
    vector<Kontobewegung> bewegungen;

public:
    Konto(string inhaber, string nr, string pin, int betrag, Datum d);
    virtual ~Konto();
    virtual void zahleEin(int betrag, Datum d, string info = "Bareinzahlung");
    virtual void hebeAb(int betrag, Datum d, string info = "Barauszahlung");
    int kontostand();
    string kontoauszug(Datum d);
};

#endif

