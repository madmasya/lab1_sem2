#include "Car.h"
#include "SafeInput.h"

Car::Car() : mark("nil"), model("nil"), number("nil")
{
	cout << "����������� Car ��� ������" << endl;
}

Car::Car(string mark, string model, string number) : mark(mark), model(model), number(number)
{
	cout << "����������� Car ��� ������" << endl;
}

Car::Car(const Car& Car) : mark(Car.mark), model(Car.model), number(Car.number)
{
	cout << "����������� ����������� Car ��� ������" << endl;
}

Car* Car::clone() const
{
	return new Car(*this);
}

void Car::inputFromConsole()
{
	cout << "������� ����� ������: ";
	mark = input<string>();
	cout << "������� ������ ������: ";
	getline(cin, model);
	cout << "������� ���. �����: ";
	getline(cin, number);
}

void Car::inputFromFile(fstream& file)
{
	string err = "���� �� ����� ���� �������� ���������";
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
	cout << "������" << endl
		<< "-----------------" << endl
		<< "����� ������: " << mark << endl
		<< "������: " << model << endl
		<< "���. �����: " << number << endl;
}

void Car::printToFile(fstream& out)
{
	string err = "���� �� ����� ���� ������ ���������\n";
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
	cout << "������� ����� ����� ������: ";
	mark = input<string>();
	cout << "������� ����� ������: ";
	getline(cin, model);
	cout << "������� ����� ���. �����: ";
	getline(cin, number);
}

string Car::getMark() { return mark; }
void Car::setMark(string mark) { this->mark = mark; }

string Car::getModel() { return model; }
void Car::setModel(string surmodelname) { this->model = model; }

string Car::getGovNumber() { return number; }
void Car::setGovNumber(string number) { this->number = number; }