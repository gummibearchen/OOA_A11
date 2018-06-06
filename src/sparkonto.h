// *******************************************************************
// sparkonto.h
// *******************************************************************

#ifndef _SPARKONTO_H
#define _SPARKONTO_H

#include "datum.h"
#include "konto.h"

class Sparkonto : public Konto {
private:
    double zinssatz;
    int zinsen;
    int berechneZins(Datum d);

public:
    Sparkonto(string inhaber, string nr, string pin, int betrag, double zins,
              Datum d);
    void hebeAb(int betrag, Datum d, string = "Barauszahlung");
    void zahleEin(int betrag, Datum d, string = "Bareinzahlung");
    void zinsgutschrift(Datum d);
};

#endif
