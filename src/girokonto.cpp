// *******************************************************************
// girokonto.cpp
// *******************************************************************

#include "girokonto.h"

// *******************************************************************
Girokonto::Girokonto(int inhaber, int nr, string pin, int betrag,
                     int dispo, double zins, Date tag) : Konto(inhaber, nr, pin, betrag, tag) {
    this->dispolimit = dispo;
    this->zinssatz = zins;
    this->zinsen = 0;
}

// *******************************************************************
int Girokonto::berechneZins(Date tag) {
    if (stand < 0) {
        int diffTage = tag.diffDays(letzteAenderung);

        return -stand * zinssatz * diffTage / 360;
    } else return 0;
}

// *******************************************************************
void Girokonto::auszahlen(int betrag, Date tag) {
    if (stand - betrag < -dispolimit)
        throw "invalid operation";

    zinsen += berechneZins(tag);
    Konto::hebeAb(betrag, tag, "Auszahlung");
}

// *******************************************************************
void Girokonto::zahleEin(int betrag, Date tag, string info) {
    zinsen += berechneZins(tag);
    Konto::zahleEin(betrag, tag, "Einzahlung");
}

// *******************************************************************
void Girokonto::ueberweisen(int betrag, Date tag, string info) {
    // Die Bank muss sicherstellen, dass zwei Kontobewegungen stattfinden,
    // dafÃ¼r ist nicht die Klasse Girokonto verantwortlich: Bei dem einen
    // Konto wird das Geld abgebucht, bei dem anderen gutgeschrieben.
    zinsen += berechneZins(tag);
    if (betrag < 0 && stand + betrag < -dispolimit)
        throw "invalid operation";
    Konto::zahleEin(betrag, tag, info);
}

// *******************************************************************
void Girokonto::zinsgutschrift(Date tag) {
    zinsen += berechneZins(tag);
    stand -= zinsen;
    zinsen = 0;
}

// *******************************************************************
int Girokonto::getDispo() {
    return dispolimit;
}
