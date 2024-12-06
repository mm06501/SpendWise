#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include <vector>


using namespace std;

class Category {
private:
    int categoryID;
    string name;
    double budget;
    double totalSpending;

public:
    // Constructor to initialize category with ID, name, and budget
    Category(int id, const string& categoryName, double categoryBudget);

    // Getter for category name
    string getName() const;

	void setTotalSpending(double amount);
   
    double getBudget() const;

    double getSpending() const;
	
	void setBudget(double amount);

    int getCategoryID() const;




};

#endif  // CATEGORY_H
