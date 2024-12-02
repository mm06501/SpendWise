#include "Date.h"
#include<string>
using namespace std;

Date::Date() : month(1), day(15), year(2024) {}

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

void Date::setDate(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

string Date::getDate() const {
    string m = to_string(month);
    string d = to_string(day);
    string y = to_string(year);

	if (month < 10)
        m = "0" + m;

	if (day < 10)
        d = "0" + d;

	string formattedDate = m + "/" + d + "/" + y;
    return formattedDate;
}

