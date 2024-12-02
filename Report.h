#ifndef REPORT_H
#define REPORT_H

//#include "Date.h"
using namespace std;
class Report {
    int report_id;
    Date start_date;
    Date end_date;

public:
    void generate_report();
    void display_report();
    void export_to_csv();
};

#endif 
