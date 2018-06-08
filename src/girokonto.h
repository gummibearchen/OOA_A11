// *******************************************************************
// girokonto.h
// *******************************************************************

#ifndef _GIROKONTO_H
#define _GIROKONTO_H

#include "datum.h"
#include "konto.h"

class Girokonto : public Konto {
private:
    int dispolimit;
    double zinssatz;
    int zinsen;
    int berechneZins();
    int berechneZins(Date tag);

public:
    Girokonto(string inhaber, string nr, string pin, int betrag, int dispo,
              double zins, Date tag);
    void einzahlen(int betrag, Date tag);
    void auszahlen(int betrag, Date tag);
    void ueberweisen(int betrag, Date tag, string info);
    void zinsgutschrift(Date tag);
    // int getDispo(); // nicht im UML
    string toString();
    static Konto parse(string line);
};

#endif
