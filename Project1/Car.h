#pragma once

#include "Fabric.h"

class Car final : public Fabric
{
	string mark, model, number;

public:
	Car();
	Car(string mark, string model, string number);
	Car(const Car& Car);
	~Car() { std::cout << "Деструктор Car был вызван" << std::endl; }

	virtual Car* clone() const override;
	virtual void inputFromConsole() override;
	virtual void inputFromFile(fstream& file) override;
	virtual void printToConsole() override;
	virtual void printToFile(fstream& out) override;
	virtual void change() override;

	string getMark();
	void setMark(string mark);

	string getModel();
	void setModel(string surmodelname);

	string getGovNumber();
	void setGovNumber(string number);
};