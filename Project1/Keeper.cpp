#include "Keeper.h"

void keeper::deleteItem() {
    if (countOfItems == 0) {
        string err = "Пока что в программе нет элементов для удаления!\n";
        throw err;
    }
    delete mas[countOfItems - 1];
    countOfItems--;
    std::cout << "Элемент успешно удален!\n";
}

void keeper::addNewItem(Fabric* newItem) {
    if (capacity == countOfItems) {
        resizeOfArray();
    }

    mas[countOfItems] = newItem;
    countOfItems++;
    std::cout << "Элемент успешно добавлен в массив!\n";
}

keeper::keeper() {
    capacity = 10;
    mas = new Fabric * [capacity];
}

keeper::keeper(int initialCapacity) {
    capacity = initialCapacity;
    mas = new Fabric * [capacity];
}

void keeper::resizeOfArray() {
    int newSize = capacity + 10;
    auto biggerArray = new Fabric * [newSize];

    for (int i = 0; i < countOfItems; i++) {
        biggerArray[i] = mas[i]->clone();
    }

    for (int i = 0; i < countOfItems; i++) {
        delete mas[i];
    }
    delete[] mas;
    capacity = newSize;
    mas = biggerArray;
    std::cout << "Размера массива увеличен до " << capacity << "\n";
}

void keeper::readFromFile(const std::string& nameOfFile) {
    std::fstream file;

    if (!endsWith(nameOfFile, ".txt")) {
        string err = "Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n";
        throw err;
    }

    file.open(nameOfFile, std::ios::in);
    if (!file.is_open()) {
        file.close();
        string err = "Ошибочное открытие файла!\n";
        throw err;
    }

    std::string className;
    while (std::getline(file, className)) {

        if (countOfItems == capacity) {
            resizeOfArray();
        }

        if (className == "1") {
            mas[countOfItems] = new Furniture;
        }
        else if (className == "2") {
            mas[countOfItems] = new Employee;
        }
        else if (className == "3") {
            mas[countOfItems] = new Car;
        }
        else {
            file.close();
            string err = "Считывается странный объект из файла, выход!\n";
            throw err;
        }

        mas[countOfItems++]->inputFromFile(file);
    }

    std::cout << "Данные успешно считаны из файла!\n\n";
    file.close();
}

void keeper::writeInFile(const std::string& nameOfFile) {
    if (!endsWith(nameOfFile, ".txt")) {
        string err = "Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n";
        throw err;
    }

    std::fstream file;
    file.open(nameOfFile, std::ios::out);
    if (!file.is_open()) {
        file.close();
        string err = "Ошибочное открытие файла!\n";
        throw err;
    }

    for (int i = 0; i < countOfItems; i++) {
        mas[i]->printToFile(file);
    }
    std::cout << "Данные успешно были записаны в файл!\n\n";
    file.close();
}

keeper::~keeper() {
    std::cout << "Вызван деструктор для класса keeper!\n";
    for (int i = 0; i < countOfItems; i++) {
        delete mas[i];
    }
    delete[] mas;
}

void keeper::displayData() {
    if (countOfItems == 0) {
        string err = "Пока что элементов в программе нет!\n";
        throw err;
    }

    std::cout << "Созданных объектов в программе: " << countOfItems << "\n";
    for (int i = 0; i < countOfItems; i++) {
        cout << endl << "Элемент " << i << ":" << endl << endl;
        mas[i]->printToConsole();
    }
}

void keeper::editData(int number) {
    if (number + 1 > countOfItems || number < 0)
    {
        string err = "Элемента с этим индексом не существует!\n";
        throw err;
    }
    mas[number]->change();
    std::cout << "Данные об объекте изменены упешно!\n";
}

void keeper::displayData(int number) {
    if (countOfItems == 0) {
        string err = "Пока что элементов в программе нет!\n";
        throw err;
    }
    cout << endl << "Элемент " << number << ":" << endl << endl;
    mas[number]->printToConsole();
}

int keeper::getCountOfItems() const {
    return countOfItems;
}

keeper::keeper(const keeper& keeper2) {
    std::cout << "Вызван конструктор копирования для класса keeper!\n";
    capacity = keeper2.capacity;
    countOfItems = keeper2.countOfItems;
    mas = new Fabric * [capacity];
    for (int i = 0; i < countOfItems; i++) {
        mas[i] = (keeper2.mas[i])->clone();
    }
}

keeper* keeper::clone() const {
    return new keeper(*this);
}

bool endsWith(std::string const& value, std::string const& ending) {
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}