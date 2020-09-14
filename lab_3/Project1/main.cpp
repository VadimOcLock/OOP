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

	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

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

	authorization(); // ����������� ������������ � ���������� ������� � ����� � ��������� ����

	// ���������������� ��������� -1-
	cout << "(*) ����� ����������� ���������� ������� (1)" << endl 
		 << "(*) ����� �������� ��� ���������� ������� (2)" << endl;

	int flag;
	cin >> flag;
	
	if (flag == 1) {
		//���������������� ��������� -2-
		cout << "(*) ����� ����������� ���������� � ������� � ������� ����������� ������� (1)" << endl
			 << "(*) ����� ������ ��� ������������ �� ����� ���������� ������� (2)" << endl
			 << "(*) ����� ��������� ��������� ������� (0)" << endl;

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

		cout << "������� ����������: " << endl;
		collection[0].display_car("show");

		enter_car();

		delete[] collection;
	}

	return 0;
}