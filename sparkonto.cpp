// *******************************************************************
// sparkonto.cpp
// *******************************************************************

#include "sparkonto.h"
#include <cmath>

// *******************************************************************
Sparkonto::Sparkonto(string inhaber, string nr, string pin, int betrag,
                     double zins, Datum d) : Konto(inhaber, nr, pin, betrag, d) {
    this->zinssatz = zins;
    this->zinsen = 0;
}

// *******************************************************************
int Sparkonto::berechneZins(Datum d) {
    int diffTage = d.diffDays(letzteAenderung);

    return stand * zinssatz * diffTage / 360;
}

// *******************************************************************
void Sparkonto::hebeAb(int betrag, Datum d, string info) {
    if (stand - betrag < 0)
        throw "invalid operation";

    zinsen += berechneZins(d);
    Konto::hebeAb(betrag, d, info);
}

// *******************************************************************
void Sparkonto::zahleEin(int betrag, Datum d, string info) {
    zinsen += berechneZins(d);
    Konto::zahleEin(betrag, d, info);
}

// *******************************************************************
void Sparkonto::zinsgutschrift(Datum d) {
    zinsen += berechneZins(d);
    stand += zinsen;
    zinsen = 0;
}
