#include "Car.h"
#include "SafeInput.h"

Car::Car() : mark("nil"), model("nil"), number("nil")
{
	cout << "Конструктор Car был вызван" << endl;
}

Car::Car(string mark, string model, string number) : mark(mark), model(model), number(number)
{
	cout << "Конструктор Car был вызван" << endl;
}

Car::Car(const Car& Car) : mark(Car.mark), model(Car.model), number(Car.number)
{
	cout << "Конструктор копирования Car был вызван" << endl;
}

Car* Car::clone() const
{
	return new Car(*this);
}

void Car::inputFromConsole()
{
	cout << "Введите марку машины: ";
	mark = input<string>();
	cout << "Введите модель машины: ";
	getline(cin, model);
	cout << "Введите гос. номер: ";
	getline(cin, number);
}

void Car::inputFromFile(fstream& file)
{
	string err = "Файл не может быть прочитан корректно";
	if (file.is_open())
	{
		getline(file, mark);
		getline(file, model);
		getline(file, number);
	}
	else throw err;
}


void Car::printToConsole()
{
	cout << "МАШИНА" << endl
		<< "-----------------" << endl
		<< "Марка машины: " << mark << endl
		<< "Модель: " << model << endl
		<< "Гос. номер: " << number << endl;
}

void Car::printToFile(fstream& out)
{
	string err = "Файл не может быть открыт корректно\n";
	if (out.is_open())
	{
		out << "3" << endl;
		out << mark << endl;
		out << model << endl;
		out << number << endl;
	}
	else throw err;

}

void Car::change()
{
	cout << "Введите новую марку машины: ";
	mark = input<string>();
	cout << "Введите новую модель: ";
	getline(cin, model);
	cout << "Введите новый гос. номер: ";
	getline(cin, number);
}

string Car::getMark() { return mark; }
void Car::setMark(string mark) { this->mark = mark; }

string Car::getModel() { return model; }
void Car::setModel(string surmodelname) { this->model = model; }

string Car::getGovNumber() { return number; }
void Car::setGovNumber(string number) { this->number = number; }