#ifndef REPORT_H
#define REPORT_H
#include "Account.h"
#include "Date.h"
using namespace std;
class Report {
    Date start_date;
    Date end_date;
    Account* account;

public:
    void generateReport(Account* account);
    void exportReport();
};

#endif 
