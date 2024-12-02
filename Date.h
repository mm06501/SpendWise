#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
using namespace std;

class Date {
public:
    int month;
    int day;
    int year;

    Date();
    Date(int m, int d, int y);
    void setDate(int m, int d, int y);
    string getDate() const;};

#endif
