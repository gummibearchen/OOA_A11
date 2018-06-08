// *******************************************************************
// konto.cpp
// *******************************************************************

#include "konto.h"
#include <string>
#include <sstream>
using namespace std;

// *******************************************************************
Konto::Konto(int inhaber, int nr, string pin, int betrag, Date tag) {
    this->inhaber = inhaber;
    this->nr = nr;
    this->pin = pin;
    letzteAenderung = tag;
    stand = betrag;
}

// *******************************************************************
Konto::~Konto() {
}

// *******************************************************************
void Konto::einzahlen(int betrag, Date tag) {
    stand += betrag;
    letzteAenderung = tag;
    bewegungen.push_back(Kontobewegung(tag, betrag, "Einzahlung"));
}

// *******************************************************************
void Konto::auszahlen(int betrag, Date tag) {
    stand -= betrag;
    letzteAenderung = tag;
    bewegungen.push_back(Kontobewegung(d, -betrag, "Auszahlung"));
}

// *******************************************************************
int Konto::kontostand() {
    return stand;
}

// *******************************************************************
string Konto::auszug(Date tag) {
    // eigentlich: pruefen ob Date tag groesser als letzte Bewegung
    ostringstream os;
    vector<Kontobewegung>::iterator iter;

    os << "Kontoauszug fuer Kontonummer " << nr;
    os << " (" << inhaber;
    os << ") am " << tag << endl;

    for (iter = bewegungen.begin(); iter != bewegungen.end(); iter++) {
        os << iter->tag << ": ";
        os << iter->info << " ";
        os << iter->betrag << endl;
    }
    bewegungen.clear();
    return os.str();
}
