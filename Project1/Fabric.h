#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include "SafeInput.h"

using namespace std;

class Fabric
{
public:
	Fabric();
	virtual ~Fabric();

	virtual Fabric* clone() const = 0;
	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(fstream& file) = 0;
	virtual void printToConsole() = 0;
	virtual void printToFile(fstream& out) = 0;
	virtual void change() = 0;
};