#include <iostream>
#include <string>
#include <utility>
#include <locale>
#include <fstream>
#include <Windows.h>
#include "car.h"


using namespace std;

int N;
car* collection;

int main(void) {

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	//Read ifo from file
	ifstream infile;
	infile.open("info_ads.txt");
	infile >> N;
	infile.get();

	collection = new car[N];
	for (int i = 0; i < N; i++) {
		collection[i].read_car(infile);
	}
	infile.close();

	authorization(); // Авторизация пользователя с сохранение Фамилии и Имени в отдельный файл

	// Пользовательский интерфейс -1-
	cout << "(*) Чтобы просмотреть обьявления нажмите (1)" << endl 
		 << "(*) Чтобы Добавить своё обьявление нажмите (2)" << endl;

	int flag;
	cin >> flag;
	
	if (flag == 1) {
		//Пользовательский интерфейс -2-
		cout << "(*) Чтобы просмотреть информацию о машинах и выбрать оптимальную нажмите (1)" << endl
			 << "(*) Чтобы узнать все комплектации по марке автомобиля нажмите (2)" << endl
			 << "(*) Чтобы закрырыть программу нажмите (0)" << endl;

		int flag_1;
		cin >> flag_1;

		if (flag_1 == 1) {

			for (int i = 0; i < N; i++) {
				collection[i].display_car();
			}

			optimal_car(collection, N);
		}
		if (flag_1 == 2)
			find_car(collection, N);
		if (flag_1 == 0)
			return 0;

		delete[] collection;

		system("pause");
	}
	if (flag == 2) {

		cout << "Образец обьявления: " << endl;
		collection[0].display_car("show");

		enter_car();

		delete[] collection;
	}

	return 0;
}