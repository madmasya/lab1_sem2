#include "Keeper.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	system("chcp 1251");
	keeper keeper = NULL;
	char answer = '1';
	while (answer != '0')
	{
		try {
			system("cls");
			cout << "����" << endl
				<< "------------------" << endl
				<< "1) �������� ����� �������" << endl
				<< "2) ������� ��������� �������" << endl
				<< "3) �������� �������" << endl
				<< "4) ������� ���������� � ���� ��������� �� �����" << endl
				<< "5) ������� ���������� � �������� �� �����" << endl
				<< "6) ��������� ������� �������� � ����" << endl
				<< "7) ��������� ���������� �� ��������� �� �����" << endl
				<< "0) ����� �� ���������" << endl
				<< "\n��� �����: ";
			answer = _getch();

			switch (answer)
			{
			case '1': {
				char choice = '1';
				while (choice != '0')
				{
					system("cls");
					cout << "�������� ��� ������ ��������: " << endl
						<< "1) ������" << endl
						<< "2) ��������" << endl
						<< "3) ������" << endl
						<< "0) ��������� � ����" << endl
						<< "\n��� �����: ";
					choice = _getch();
					switch (choice)
					{
					case '1': {
						system("cls");
						Furniture* item = new Furniture;
						item->inputFromConsole();
						keeper.addNewItem(item);
						system("pause");
						break;
					}
					case '2': {
						system("cls");
						Employee* item = new Employee;
						item->inputFromConsole();
						keeper.addNewItem(item);
						system("pause");
						break;
					}
					case '3': {
						system("cls");
						Car* item = new Car;
						item->inputFromConsole();
						keeper.addNewItem(item);
						system("pause");
						break;
					}
					case '0': {
						system("cls");
						cout << "����������� � ����" << endl;
						system("pause");
						break;
					}
					default: {
						system("cls");
						cout << "�������� ����" << endl;
						system("pause");
						break;
					}
					}
				}
				break;
			}
			case '2': {
				system("cls");
				keeper.deleteItem();
				system("pause");
				break;
			}
			case '3': {
				system("cls");
				cout << "������� ����� �������� ��� ��������������: ";
				int number = input<int>();
				keeper.editData(number);
				system("pause");
				break;
			}
			case '4': {
				system("cls");
				keeper.displayData();
				system("pause");
				break;
			}
			case '5': {
				system("cls");
				cout << "������� ����� �������� ��� ������ ���������� � ��� �� �����: ";
				int number = input<int>();
				keeper.displayData(number);
				system("pause");
				break;
			}
			case '6': {
				system("cls");
				keeper.writeInFile("file.txt");
				system("pause");
				break;
			}
			case '7': {
				system("cls");
				keeper.readFromFile("file.txt");
				system("pause");
				break;
			}
			case '0': {
				system("cls");
				cout << "�����!" << endl;
				system("pause");
				break;
			}
			default: {
				system("cls");
				cout << "�������� ����" << endl;
				system("pause");
				break;
			}
			}
		}
		catch (string& err)
		{
			system("cls");
			cout << err;
			system("pause");
		}
	}
}