// *******************************************************************
// kontobewegung.h
// *******************************************************************

#ifndef _KONTOBEWEGUNG_H
#define _KONTOBEWEGUNG_H

#include "datum.h"

struct Kontobewegung {
    Datum tag;
    int betrag;
    string info;

    Kontobewegung(Datum tag, int betrag, string info);
};

#endif
