// *******************************************************************
// konto.cpp
// *******************************************************************

#include "konto.h"
#include <string>
#include <sstream>
using namespace std;

// *******************************************************************
Konto::Konto(string inhaber, string nr, string pin, int betrag, Datum d) {
    this->inhaber = inhaber;
    this->nr = nr;
    this->pin = pin;
    letzteAenderung = d;
    stand = betrag;
}

// *******************************************************************
Konto::~Konto() {
}

// *******************************************************************
void Konto::zahleEin(int betrag, Datum d, string info) {
    stand += betrag;
    letzteAenderung = d;
    bewegungen.push_back(Kontobewegung(d, betrag, info));
}

// *******************************************************************
void Konto::hebeAb(int betrag, Datum d, string info) {
    stand -= betrag;
    letzteAenderung = d;
    bewegungen.push_back(Kontobewegung(d, -betrag, info));
}

// *******************************************************************
int Konto::kontostand() {
    return stand;
}

// *******************************************************************
string Konto::kontoauszug(Datum d) {
    // eigentlich: pruefen ob Datum d groesser als letzte Bewegung
    ostringstream os;
    vector<Kontobewegung>::iterator iter;

    os << "Kontoauszug fuer Kontonummer " << nr;
    os << " (" << inhaber;
    os << ") am " << d << endl;

    for (iter = bewegungen.begin(); iter != bewegungen.end(); iter++) {
        os << iter->tag << ": ";
        os << iter->info << " ";
        os << iter->betrag << endl;
    }
    bewegungen.clear();
    return os.str();
}
