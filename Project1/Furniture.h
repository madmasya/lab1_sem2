#pragma once

#include "Fabric.h"

class Furniture final : public Fabric
{
	string type, colour, material;
	int length, width, height, price;

public:
	Furniture();
	Furniture(string type, string colour, string material, int length, int width, int height, int price);
	Furniture(const Furniture& Furniture);
	~Furniture() { std::cout << "Деструктор Furniture был вызван" << std::endl; }

	virtual Furniture* clone() const override;
	virtual void inputFromConsole() override;
	virtual void inputFromFile(fstream& file) override;
	virtual void printToConsole() override;
	virtual void printToFile(fstream& out) override;
	virtual void change() override;

	string getType();
	void setType(string type);

	string getColour();
	void setColour(string colour);

	string getMaterial();
	void setMaterial(string material);

	int getHeight();
	void setHeight(int height);

	int getLength();
	void setLength(int length);

	int getWidth();
	void setWidth(int width);

	int getPrice();
	void setPrice(int price);
};