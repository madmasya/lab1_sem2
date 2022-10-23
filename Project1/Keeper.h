#pragma once

#include "Employee.h"
#include "Furniture.h"
#include "Car.h"

class keeper {
private:
    Fabric** mas;
    int capacity;
    int countOfItems = 0;

    void resizeOfArray();

public:
    keeper();

    keeper(int initialCapacity);

    keeper(const keeper& keeper2);

    ~keeper();

    void addNewItem(Fabric* newItem);

    void deleteItem();

    void writeInFile(const string& nameOfFile);

    void readFromFile(const string& nameOfFile);

    void displayData();

    void displayData(int number);

    void editData(int number);

    int getCountOfItems() const;

    keeper* clone() const;
};

bool endsWith(string const& value, string const& ending);