#include <iostream>
#include <string>
#include <utility>
#include <locale>
#include <fstream>
#include <Windows.h>
#include "CarStore.h"

using namespace std;

int main(void) 
{
	SetConsoleCP(1251);// Установка кодовой страницы win-cp 1251 в поток ввода.
	SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода.

	// Считываю с файла количество элементов коллекции контейнера.
	ifstream file;
	file.open("info_ads.txt");
	int n;
	file >> n;
	n++;				// Увеличиваю количество элементов для того чтобы в случае чего было куда добавлять обьявление машины.
	file.get();
	file.close();
	carstore my_carstore(n);

	my_carstore.read_from_file("info_ads.txt");

	authorization(); // Авторизация пользователя с сохранение Фамилии и Имени в отдельный файл.

	// Пользовательский интерфейс (-1-)
	cout << "(*) Чтобы просмотреть обьявления нажмите (1)" << endl 
		 << "(*) Чтобы Добавить своё обьявление нажмите (2)" << endl;

	int flag;
	cin >> flag;
	
	if (flag == 1) 
	{
		//Пользовательский интерфейс (-2-)
		cout << "(*) Чтобы просмотреть информацию о машинах и выбрать оптимальную нажмите (1)" << endl
			 << "(*) Чтобы узнать все комплектации по марке автомобиля нажмите (2)" << endl
			 << "(*) Чтобы закрырыть программу нажмите (0)" << endl;

		int flag_1;
		cin >> flag_1;

		if (flag_1 == 1) 
		{
			my_carstore.display_all();

			my_carstore.optimal_car();
		}
		if (flag_1 == 2)
			my_carstore.find_car();
		if (flag_1 == 0)
			return 0;

		system("pause");
	}
	if (flag == 2) 
	{
		cout << "Образец обьявления: " << endl;
		my_carstore.example_car();

		my_carstore.enter_car();
	}

	return 0;
}