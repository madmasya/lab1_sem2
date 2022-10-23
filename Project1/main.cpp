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
			cout << "МЕНЮ" << endl
				<< "------------------" << endl
				<< "1) Добавить новый элемент" << endl
				<< "2) Удалить последний элемент" << endl
				<< "3) Изменить элемент" << endl
				<< "4) Вывести информацию о всех элементах на экран" << endl
				<< "5) Вывести информацию о элементе на экран" << endl
				<< "6) Сохранить текущие элементы в файл" << endl
				<< "7) Загрузить информацию об элементах из файла" << endl
				<< "0) Выход из программы" << endl
				<< "\nВаш выбор: ";
			answer = _getch();

			switch (answer)
			{
			case '1': {
				char choice = '1';
				while (choice != '0')
				{
					system("cls");
					cout << "Выберите тип нового элемента: " << endl
						<< "1) Мебель" << endl
						<< "2) Работник" << endl
						<< "3) Машина" << endl
						<< "0) Вернуться в меню" << endl
						<< "\nВаш выбор: ";
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
						cout << "Возвращение в меню" << endl;
						system("pause");
						break;
					}
					default: {
						system("cls");
						cout << "Неверный ввод" << endl;
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
				cout << "Введите номер элемента для редактирования: ";
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
				cout << "Введите номер элемента для вывода информации о нем на экран: ";
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
				cout << "Выход!" << endl;
				system("pause");
				break;
			}
			default: {
				system("cls");
				cout << "Неверный ввод" << endl;
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