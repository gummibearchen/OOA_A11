// *******************************************************************
// datum.cpp
// *******************************************************************

#include "datum.h"
#include <ctime>

// *******************************************************************
Datum::Datum(int tag, int monat, int jahr) {
    this->tag = tag;
    this->monat = monat;
    this->jahr = jahr;
}

// *******************************************************************
bool Datum::isLeapYear() {
    return (jahr % 400 == 0 || (jahr % 4 == 0 && jahr % 100 != 0));
}

// *******************************************************************
int Datum::diffDays(Datum d) {
    struct tm d1;
    struct tm d2;

    time_t t1;
    time_t t2;

    d1.tm_sec = 0;
    d1.tm_min = 0;
    d1.tm_hour = 0;
    d1.tm_mday = this->tag;
    d1.tm_mon = this->monat - 1;
    d1.tm_year = this->jahr - 1900;

    d2.tm_sec = 0;
    d2.tm_min = 0;
    d2.tm_hour = 0;
    d2.tm_mday = d.tag;
    d2.tm_mon = d.monat - 1;
    d2.tm_year = d.jahr - 1900;

    t1 = mktime(&d1);
    t2 = mktime(&d2);

    return difftime(t1, t2) / (60 * 60 * 24);
}

// *******************************************************************
int Datum::diffToCurrentDate() {
    int res;
    Datum today = getCurrentDate();

    res = today.jahr - jahr;
    if (monat > today.monat ||
        (monat == today.monat && tag > today.tag))
        res -= 1;

    return res;
}

// *******************************************************************
ostream & operator<<(ostream &os, Datum &d) {
    os << d.tag << "." << d.monat << "." << d.jahr;
    return os;
}
