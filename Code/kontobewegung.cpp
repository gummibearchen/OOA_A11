// *******************************************************************
// kontobewegung.cpp
// *******************************************************************

#include "kontobewegung.h"

Kontobewegung::Kontobewegung(Datum tag, int betrag, string info) {
    this->tag = tag;
    this->betrag = betrag;
    this->info = info;
}
