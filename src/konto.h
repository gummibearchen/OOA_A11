
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
    static int number;
    int inhaber;
    string pin;
    int nr;
    int stand;
    Date letzteAenderung;
    vector<Kontobewegung> bewegungen;

public:
    Konto(string inhaber, string nr, string pin, int betrag, Date tag);
    virtual ~Konto();
    virtual void einzahlen(int betrag, Date tag);
    virtual void auszahlen(int betrag, Date tag);
    virtual void ueberweisen(int kontonr, int betrag, Date tag, string info);
    virtual void zinsgutschrift(Date tag)=0;
    void hinzuKontobew(Kontobewegung kb);
    string auszug();
    virtual string toString();
    static Konto parse(string line);
    int holeInhaber();
    vector<Kontobewegung *> holeBewegungen();
};

#endif

