// *******************************************************************
// datum.h
// *******************************************************************

#ifndef _DATUM_H
#define _DATUM_H

#include <iostream>
using namespace std;

class Datum {
    friend ostream & operator<<(ostream &os, Datum &d);

private:
    int tag, monat, jahr;

public:
    Datum(int tag = 1, int monat = 1, int jahr = 1900);
    bool isLeapYear();
    int diffDays(Datum d);
    int diffToCurrentDate();

    static Datum getCurrentDate() {
        Datum d;
        time_t t;
        struct tm *today;

        t = time(0);
        today = localtime(&t);
        d.tag = today->tm_mday;
        d.monat = today->tm_mon + 1;
        d.jahr = today->tm_year + 1900;

        return d;
    }
};

#endif