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
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����.
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������.

	// �������� � ����� ���������� ��������� ��������� ����������.
	ifstream file;
	file.open("info_ads.txt");
	int n;
	file >> n;
	n++;				// ���������� ���������� ��������� ��� ���� ����� � ������ ���� ���� ���� ��������� ���������� ������.
	file.get();
	file.close();
	carstore my_carstore(n);

	my_carstore.read_from_file("info_ads.txt");

	authorization(); // ����������� ������������ � ���������� ������� � ����� � ��������� ����.

	// ���������������� ��������� (-1-)
	cout << "(*) ����� ����������� ���������� ������� (1)" << endl 
		 << "(*) ����� �������� ��� ���������� ������� (2)" << endl;

	int flag;
	cin >> flag;
	
	if (flag == 1) 
	{
		//���������������� ��������� (-2-)
		cout << "(*) ����� ����������� ���������� � ������� � ������� ����������� ������� (1)" << endl
			 << "(*) ����� ������ ��� ������������ �� ����� ���������� ������� (2)" << endl
			 << "(*) ����� ��������� ��������� ������� (0)" << endl;

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
		cout << "������� ����������: " << endl;
		my_carstore.example_car();

		my_carstore.enter_car();
	}

	return 0;
}