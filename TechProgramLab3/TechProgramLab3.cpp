// TechProgramLab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <fstream>.
using namespace std;
void TaskOne(); //Обявление функций
void TaskTwo();
void TaskOneDop();
void TaskTwoDop();
void TaskThree();
void ReadDox();
string *st;
struct Clock //Структура
{
	string name;
	string county;
	int prize = 0;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	bool tf = true;
	bool tf1 = true;
	char num;
	st = new string; // Выделение динамической памяти
	while (tf)
	{
		system("cls"); //Главное меню
		cout << "Введите номер операции:\n";
		cout << "1. Выполнить задание №1.\n";
		cout << "2. Выполнить задание №2.\n";
		cout << "3. Выполнить задание №3.\n";
		cout << "4. Прочить информацию о предмете.\n";
		cout << "5. Завершить работу.\n";
		cin >> num;
		switch (num)
		{
			case '1': 
			{
				system("cls");
				tf1 = true;
				while (tf1)
				{
					system("cls");
					cout << "Введите номер конкретной операци:\n";
					cout << "1. Составить матрицу с помощью клавиатуры.\n";
					cout << "2. Составить матрицу автоматически.\n";
					cout << "3. Вернуться в главное меню.\n";
					cin >> num;
					switch (num)
					{
						case '1':
						{
							TaskOne();
							system("pause");
							tf1 = false;
							cout << "\n";
							break;
						}
						case '2':
						{
							TaskOneDop();
							system("pause");
							tf1 = false;
							cout << "\n";
							break;
						}
						case '3': tf1 = false; break;
						default: break;
					}	
				}
				break;
			}
			case '2': 
			{
				system("cls");
				tf1 = true;
				while (tf1)
				{
					system("cls");
					cout << "Введите номер конкретной операции:\n";
					cout << "1. Работа с определённой строкой согласно варианту.\n";
					cout << "2. Ввести другую строку.\n";
					cout << "3. Вернуться в главное меню.\n";
					cin >> num;
					switch (num)
					{
					case '1':
					{
						TaskTwo();
						system("pause");
						tf1 = false;
						cout << "\n";
						break;
					}

					case '2':
					{
						TaskTwoDop();
						system("pause");
						tf1 = false;
						cout << "\n";
						break;
					}
					case '3': tf1 = false; break;
					default: break;
					}
				}
				break;
			}
			case '3': TaskThree(); system("pause"); break;
			case '4': ReadDox(); system("pause"); break;
			case '5': tf = false; break;
			default: break;
		}
	}
	delete st; //Освобождение памяти
	return 0;
}

//Блок рассмотрения функций
void TaskOne()
{
	system("CLS");
	cout << "Введите 36 элементов матрицы:\n";
	char matr[6][6];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> matr[i][j];
		}
	}
	system("CLS");
	cout << "Конечная матрица:\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << matr[i][j];
		}
		cout << "\n";
	}
}

void TaskOneDop()
{
	system("CLS");
	char matr[6][6];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j == 2)
			{
				switch (i)
				{
				case 0: matr[i][j] = '2'; break;
				case 1: matr[i][j] = '3'; break;
				case 2: matr[i][j] = '4'; break;
				case 3: matr[i][j] = '5'; break;
				case 4: matr[i][j] = '6'; break;
				case 5: matr[i][j] = '7'; break;
				default: break;
				}
			}
			else
				matr[i][j] = '?';
		}
	}
	cout << "Конечная матрица:"<< endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << matr[i][j];
		}
		cout << "\n";
	}
}

void TaskTwo()
{
	system("CLS");
	cout << "Рассматриваемая строка:\n";
	*st = ("One Five Zero\n");
	cout << *st;
	string str = *st;
	string::difference_type n = count(str.begin(), str.end(), 'o');
	cout << "Количество букв 'о' в строке: ";
	cout << n<< "\n";
}
void TaskTwoDop()
{
	system("CLS");
	cout << "Рассматриваемая строка:\n";
	while (isspace(cin.peek())) cin.ignore(); //dodge spaces, line breaks.
	getline(cin, *st);
	string str = *st;
	string::difference_type n = count(str.begin(), str.end(), 'o');
	cout << "Количество букв 'о' в строке: ";
	cout << n << "\n";
}
void TaskThree()
{
	system("CLS");
	cout << "Произвелась запись в документ.\n";
	struct Clock clocks[5];//Массив структурных переменных

	clocks[0].name = "Rolex";
	clocks[0].county = "Швейцария";
	clocks[0].prize = 740000;

	clocks[1].name = "Audemars";
	clocks[1].county = "Швейцария";
	clocks[1].prize = 1484000;

	clocks[2].name = "Chopard";
	clocks[2].county = "Швейцария";
	clocks[2].prize = 1722000;

	clocks[3].name = "Cartier";
	clocks[3].county = "Франция";
	clocks[3].prize = 650000;

	clocks[4].name = "Omega";
	clocks[4].county = "Швейцария";
	clocks[4].prize = 680000;

	ofstream dox;
	dox.open("dox.txt");
	if (!dox)
		cout << "Ошибка открытия документа.\n";
	else
		for (int i = 0; i < 5; i++)
		dox << setiosflags(ios::left)
		<< setw(15) << clocks[i].name;
	dox << endl;
	for (int i = 0; i < 5; i++)
		dox << setiosflags(ios::left)
		<< setw(15) << clocks[i].county;
	dox << endl;
	for (int i = 0; i < 5; i++)
		dox << setiosflags(ios::left)
		<< setw(15) << clocks[i].prize;
	dox << endl;
	int max = 1;
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		if (clocks[i].prize > max)
		{
			max = clocks[i].prize;
			j = i;
		}
	}
	dox << "Самый дорогой экземпляр: " << clocks[j].name;
	dox.close();
}
void ReadDox()
{
	system("CLS");
	bool tf2 = true;
	char num;
	cout << "О каком предмете вы хотите посмотреть информацию?\n";
	cout << "1.Rolex.\n";
	cout << "2.Audemars.\n";
	cout << "3.Chopard.\n";
	cout << "4.Cartier.\n";
	cout << "5.Omega.\n";
	cout << "6.Ввернуться в главное меню.\n";
	cin >> num;
	ifstream dox;
	dox.open("dox.txt");
	struct Clock clocks[5];
	if (!dox)
		cout << "Ошибка открытия документа.\n";
	else
	{
		
		for (int i = 0; i < 5; i++)
			dox >> setiosflags(ios::left)
			>> setw(15) >> clocks[i].name;
		for (int i = 0; i < 5; i++)
			dox >> setiosflags(ios::left)
			>> setw(15) >> clocks[i].county;
		for (int i = 0; i < 5; i++)
			dox >> setiosflags(ios::left)
			>> setw(15) >> clocks[i].prize;
	}
	system("CLS");
	while (tf2)
	{
		switch (num)
		{
		case '1': cout << clocks[0].name << "\n"
			<< clocks[0].county << "\n" << clocks[0].prize << "\n"; tf2 = false; break;
		case '2': cout << clocks[1].name << "\n"
			<< clocks[1].county << "\n" << clocks[1].prize << "\n"; tf2 = false; break;
		case '3': cout << clocks[2].name << "\n"
			<< clocks[2].county << "\n" << clocks[2].prize << "\n"; tf2 = false; break;
		case '4':cout << clocks[3].name << "\n"
			<< clocks[3].county << "\n" << clocks[3].prize << "\n"; tf2 = false; break;
		case '5':cout << clocks[4].name << "\n"
			<< clocks[4].county << "\n" << clocks[4].prize << "\n"; tf2 = false; break;
		case '6': tf2 = false; break;
		default:
			break;
		}
	}
	dox.close();
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
