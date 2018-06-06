// *******************************************************************
// girokonto.h
// *******************************************************************

#ifndef _GIROKONTO_H
#define _GIROKONTO_H

#include "datum.h"
#include "konto.h"

class Girokonto : public Konto {
private:
    double zinssatz;
    int dispolimit;
    int zinsen;
    int berechneZins();
    int berechneZins(Datum d);

public:
    Girokonto(string inhaber, string nr, string pin, int betrag, int dispo,
              double zins, Datum d);
    void hebeAb(int betrag, Datum d, string info = "Barauszahlung");
    void zahleEin(int betrag, Datum d, string info = "Bareinzahlung");
    void ueberweise(int betrag, Datum d, string info);
    void zinsgutschrift(Datum d);
    int getDispo();
};

#endif
