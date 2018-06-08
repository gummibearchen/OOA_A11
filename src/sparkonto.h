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
    int berechneZins(Date tag);

public:
    Sparkonto(string inhaber, string nr, string pin, int betrag, double zins,
              Date tag);
    void auszahlen(int betrag, Date tag);
    void einzahlen(int betrag, Date tag);
    void ueberweisen(int kontonr, int betrag, Date tag, string info);
    void zinsgutschrift(Date tag);
    string toString();
    static Konto parse(string line);
};

#endif
