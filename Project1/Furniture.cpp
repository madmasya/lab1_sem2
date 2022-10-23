#include "Furniture.h"
#include "SafeInput.h"

Furniture::Furniture() : type("nil"), colour("nil"), material("nil"), height(0), width(0), length(0), price(0)
{
	cout << "����������� Furniture ��� ������" << endl;
}

Furniture::Furniture(string type, string colour, string material, int length, int width, int height, int price) : type(type), colour(colour), material(material), length(length), width(width), height(height), price(price)
{
	cout << "����������� Furniture ��� ������" << endl;
}

Furniture::Furniture(const Furniture& Furniture) : type(Furniture.type), colour(Furniture.colour), material(Furniture.material), length(Furniture.length), width(Furniture.width), height(Furniture.height), price(Furniture.price)
{
	cout << "����������� ����������� Furniture ��� ������" << endl;
}

Furniture* Furniture::clone() const
{
	return new Furniture(*this);
}

void Furniture::inputFromConsole()
{
	cout << "������� ��� ������: ";
	type = input<string>();
	cout << "������� ����(�): ";
	getline(cin, colour);
	cout << "������� ��������(�): ";
	getline(cin, material);
	cout << "������� ����� ������: ";
	length = input<unsigned int>();
	cout << "������� ������ ������: ";
	width = input<unsigned int>();
	cout << "������� ������ ������: ";
	height = input<unsigned int>();
	cout << "������� ���������: ";
	price = input<unsigned int>();
}

void Furniture::inputFromFile(fstream& file)
{
	string err = "���� �� ����� ���� �������� ���������\n";
	if (file.is_open())
	{
		getline(file, type);
		getline(file, colour);
		getline(file, material);
		string lengthStr, widthStr, heightStr, priceStr;
		getline(file, lengthStr);
		getline(file, widthStr);
		getline(file, heightStr);
		getline(file, priceStr);
		length = stoi(lengthStr);
		width = stoi(widthStr);
		height = stoi(heightStr);
		price = stoi(priceStr);
	}
	else throw err;
}

void Furniture::printToConsole()
{
	cout << "������" << endl
		<< "-----------------" << endl
		<< "���: " << type << endl
		<< "����(�): " << colour << endl
		<< "��������(�): " << material << endl
		<< "��������:" << endl
		<< "�����: " << length << endl
		<< "������: " << width << endl
		<< "������: " << height << endl
		<< "-----------------" << endl
		<< "���������: " << price << endl;
}

void Furniture::printToFile(fstream& out)
{
	string err = "���� �� ����� ���� ������ ���������\n";
	if (out.is_open())
	{
		out << "1" << endl;
		out << type << endl;
		out << colour << endl;
		out << material << endl;
		out << length << endl;
		out << width << endl;
		out << height << endl;
		out << price << endl;
	}
	else throw err;
}

void Furniture::change()
{
	cout << "������� ����� ��� ������: ";
	type = input<string>();
	cout << "������� �����(�) ����(�): ";
	getline(cin, colour);
	cout << "������� �����(�) ��������(�): ";
	getline(cin, material);
	cout << "������� ����� �����: ";
	length = input<unsigned int>();
	cout << "������� ����� ������: ";
	width = input<unsigned int>();
	cout << "������� ����� ������: ";
	height = input<unsigned int>();
	cout << "������� ����� ����: ";
	price = input<unsigned int>();
}

string Furniture::getType() { return type; }
void Furniture::setType(string type) { this->type = type; }

string Furniture::getColour() { return colour; }
void Furniture::setColour(string colour) { this->colour = colour; }

string Furniture::getMaterial() { return material; }
void Furniture::setMaterial(string material) { this->material = material; }

int Furniture::getHeight() { return height; }
void Furniture::setHeight(int height) { this->height = height; }

int Furniture::getLength() { return length; }
void Furniture::setLength(int length) { this->length = length; }

int Furniture::getWidth() { return width; }
void Furniture::setWidth(int width) { this->width = width; }

int Furniture::getPrice() { return price; }
void Furniture::setPrice(int price) { this->price = price; }