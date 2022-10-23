#include "Employee.h"
#include "SafeInput.h"

Employee::Employee() : name("nil"), surname("nil"), patronymic("nil"), job("nil"), address("nil"), number("nil"), wage(0)
{
	cout << "����������� Employee ��� ������" << endl;
}

Employee::Employee(string name, string surname, string patronymic, string job, string address, string number, unsigned int wage) : name(name), surname(surname), patronymic(patronymic), job(job), address(address), number(number), wage(wage)
{
	cout << "����������� Employee ��� ������" << endl;
}

Employee::Employee(const Employee& Employee) : name(Employee.name), surname(Employee.surname), patronymic(Employee.patronymic), job(Employee.job), address(Employee.address), number(Employee.number), wage(Employee.wage)
{
	cout << "����������� ����������� Employee ��� ������" << endl;
}

void Employee::inputFromConsole()
{
	cout << "������� ��� ���������: ";
	name = input<string>();
	cout << "������� �������: ";
	surname = input<string>();
	cout << "������� ��������: ";
	patronymic = input<string>();
	cout << "������� ��������� ���������: ";
	job = input<string>();
	cout << "������� ����� ���������: ";
	getline(cin, address);
	cout << "������� ���������� ����� ���������: ";
	getline(cin, number);
	cout << "������� �������� ���������: ";
	wage = input<unsigned int>();
}

Employee* Employee::clone() const
{
	return new Employee(*this);
}

void Employee::inputFromFile(fstream& file)
{
	string err = "���� �� ����� ���� �������� ���������\n";
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
	cout << "��������" << endl
		<< "-----------------" << endl
		<< "���: " << name << endl
		<< "�������: " << surname << endl
		<< "��������: " << patronymic << endl
		<< "���������: " << job << endl
		<< "�����: " << address << endl
		<< "���������� �����: " << number << endl
		<< "-----------------" << endl
		<< "��������: " << wage << endl;
}

void Employee::printToFile(fstream& out)
{
	string err = "���� �� ����� ���� ������ ���������\n";
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
	cout << "������� ����� ��� ���������: ";
	name = input<string>();
	cout << "������� ����� �������: ";
	surname = input<string>();
	cout << "������� ����� ��������: ";
	patronymic = input<string>();
	cout << "������� ����� ���������: ";
	job = input<string>();
	cout << "������� ����� �����: ";
	getline(cin, address);
	cout << "������� ����� ���������� �����: ";
	getline(cin, number);
	cout << "������� ����� ��������: ";
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