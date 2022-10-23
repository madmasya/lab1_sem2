#pragma once

#include "Fabric.h"

class Employee final : public Fabric
{
	string name, surname, patronymic, job, address, number;
	int wage;

public:
	Employee();
	Employee(string name, string surname, string patronymic, string job, string address, string number, unsigned int wage);
	Employee(const Employee& Employee);
	~Employee() { std::cout << "Деструктор Employee был вызван" << std::endl; }

	virtual Employee* clone() const override;
	virtual void inputFromConsole() override;
	virtual void inputFromFile(fstream& file) override;
	virtual void printToConsole() override;
	virtual void printToFile(fstream& out) override;
	virtual void change() override;

	string getName();
	void setName(string name);

	string getSurname();
	void setSurname(string surname);

	string getPatronymic();
	void setPatronymic(string patronymic);

	string getJob();
	void setJob(string job);

	string getAddress();
	void setAddress(string address);

	string getNumber();
	void setNumber(string number);

	int getWage();
	void setWage(int wage);
};