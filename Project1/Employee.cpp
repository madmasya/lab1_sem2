#include "Employee.h"
#include "SafeInput.h"

Employee::Employee() : name("nil"), surname("nil"), patronymic("nil"), job("nil"), address("nil"), number("nil"), wage(0)
{
	cout << "Конструктор Employee был вызван" << endl;
}

Employee::Employee(string name, string surname, string patronymic, string job, string address, string number, unsigned int wage) : name(name), surname(surname), patronymic(patronymic), job(job), address(address), number(number), wage(wage)
{
	cout << "Конструктор Employee был вызван" << endl;
}

Employee::Employee(const Employee& Employee) : name(Employee.name), surname(Employee.surname), patronymic(Employee.patronymic), job(Employee.job), address(Employee.address), number(Employee.number), wage(Employee.wage)
{
	cout << "Конструктор копирования Employee был вызван" << endl;
}

void Employee::inputFromConsole()
{
	cout << "Введите имя работника: ";
	name = input<string>();
	cout << "Введите фамилию: ";
	surname = input<string>();
	cout << "Введите отчество: ";
	patronymic = input<string>();
	cout << "Введите должность работника: ";
	job = input<string>();
	cout << "Введите адрес работника: ";
	getline(cin, address);
	cout << "Введите телефонный номер работника: ";
	getline(cin, number);
	cout << "Введите зарплату работника: ";
	wage = input<unsigned int>();
}

Employee* Employee::clone() const
{
	return new Employee(*this);
}

void Employee::inputFromFile(fstream& file)
{
	string err = "Файл не может быть прочитан корректно\n";
	if (file.is_open())
	{
		getline(file, name);
		getline(file, surname);
		getline(file, patronymic);
		getline(file, job);
		getline(file, address);
		getline(file, number);
		string wageStr;
		getline(file, wageStr);
		wage = stoi(wageStr);
	}
	else throw err;
}

void Employee::printToConsole()
{
	cout << "РАБОТНИК" << endl
		<< "-----------------" << endl
		<< "Имя: " << name << endl
		<< "Фамилия: " << surname << endl
		<< "Отчество: " << patronymic << endl
		<< "Должность: " << job << endl
		<< "Адрес: " << address << endl
		<< "Телефонный номер: " << number << endl
		<< "-----------------" << endl
		<< "Зарплата: " << wage << endl;
}

void Employee::printToFile(fstream& out)
{
	string err = "Файл не может быть открыт корректно\n";
	if (out.is_open())
	{
		out << "2" << endl;
		out << name << endl;
		out << surname << endl;
		out << patronymic << endl;
		out << job << endl;
		out << address << endl;
		out << number << endl;
		out << wage << endl;
	}
	else throw err;

}

void Employee::change()
{
	cout << "Введите новое имя работника: ";
	name = input<string>();
	cout << "Введите новую фамилию: ";
	surname = input<string>();
	cout << "Введите новое отчество: ";
	patronymic = input<string>();
	cout << "Введите новую должность: ";
	job = input<string>();
	cout << "Введите новый адрес: ";
	getline(cin, address);
	cout << "Введите новый телефонный номер: ";
	getline(cin, number);
	cout << "Введите новую зарплату: ";
	wage = input<unsigned int>();
}


string Employee::getName() { return name; }
void Employee::setName(string name) { this->name = name; }

string Employee::getSurname() { return surname; }
void Employee::setSurname(string surname) { this->surname = surname; }

string Employee::getPatronymic() { return patronymic; }
void Employee::setPatronymic(string patronymic) { this->patronymic = patronymic; }

string Employee::getJob() { return job; }
void Employee::setJob(string job) { this->job = job; }

string Employee::getAddress() { return address; }
void Employee::setAddress(string address) { this->address = address; }

string Employee::getNumber() { return number; }
void Employee::setNumber(string number) { this->number = number; }

int Employee::getWage() { return wage; }
void Employee::setWage(int wage) { this->wage = wage; }