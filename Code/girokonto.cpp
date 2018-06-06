// *******************************************************************
// girokonto.cpp
// *******************************************************************

#include "girokonto.h"

// *******************************************************************
Girokonto::Girokonto(string inhaber, string nr, string pin, int betrag,
                     int dispo, double zins, Datum d) : Konto(inhaber, nr, pin, betrag, d) {
    this->dispolimit = dispo;
    this->zinssatz = zins;
    this->zinsen = 0;
}

// *******************************************************************
int Girokonto::berechneZins(Datum d) {
    if (stand < 0) {
        int diffTage = d.diffDays(letzteAenderung);

        return -stand * zinssatz * diffTage / 360;
    } else return 0;
}

// *******************************************************************
void Girokonto::hebeAb(int betrag, Datum d, string info) {
    if (stand - betrag < -dispolimit)
        throw "invalid operation";

    zinsen += berechneZins(d);
    Konto::hebeAb(betrag, d, info);
}

// *******************************************************************
void Girokonto::zahleEin(int betrag, Datum d, string info) {
    zinsen += berechneZins(d);
    Konto::zahleEin(betrag, d, info);
}

// *******************************************************************
void Girokonto::ueberweise(int betrag, Datum d, string info) {
    // Die Bank muss sicherstellen, dass zwei Kontobewegungen stattfinden,
    // dafÃ¼r ist nicht die Klasse Girokonto verantwortlich: Bei dem einen
    // Konto wird das Geld abgebucht, bei dem anderen gutgeschrieben.
    zinsen += berechneZins(d);
    if (betrag < 0 && stand + betrag < -dispolimit)
        throw "invalid operation";
    Konto::zahleEin(betrag, d, info);
}

// *******************************************************************
void Girokonto::zinsgutschrift(Datum d) {
    zinsen += berechneZins(d);
    stand -= zinsen;
    zinsen = 0;
}

// *******************************************************************
int Girokonto::getDispo() {
    return dispolimit;
}
