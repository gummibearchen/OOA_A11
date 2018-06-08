// *******************************************************************
// sparkonto.cpp
// *******************************************************************

#include "sparkonto.h"
#include <cmath>

// *******************************************************************
Sparkonto::Sparkonto(int inhaber, int nr, string pin, int betrag,
                     double zins, Date tag) : Konto(inhaber, nr, pin, betrag, tag) {
    this->zinssatz = zins;
    this->zinsen = 0;
}

// *******************************************************************
int Sparkonto::berechneZins(Date tag) {
    int diffTage = tag.diffDays(letzteAenderung);

    return stand * zinssatz * diffTage / 360;
}

// *******************************************************************
void Sparkonto::auszahlen(int betrag, Date tag) {
    if (stand - betrag < 0)
        throw "invalid operation";

    zinsen += berechneZins(tag);
    Konto::hebeAb(betrag, tag, "Auszahlung");
}

// *******************************************************************
void Sparkonto::einzahlen(int betrag, Date tag) {
    zinsen += berechneZins(tag);
    Konto::zahleEin(betrag, tag, "Einzahlung");
}

// *******************************************************************
void Sparkonto::zinsgutschrift(Date tag) {
    zinsen += berechneZins(tag);
    stand += zinsen;
    zinsen = 0;
}
