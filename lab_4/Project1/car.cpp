#include "car.h"
#include <iostream>
using namespace std;

string car::GetBrand() 
{
	return brand;
}

string car::GetModel() 
{
	return model;
}

string car::GetSegment() 
{
	return segment;
}

string car::GetBody() 
{
	return body;
}

double car::GetVolume() 
{
	return volume;
}

double car::GetPower() 
{
	return power;
}

unsigned int car::GetYear() 
{
	return year;
}

double car::GetPrice() 
{
	return price;
}

string car::GetComplect() {
	return complect;
}

double car::GetKoef() {
	return koef;
}

void car::read_car(ifstream& file) {

	getline(file, brand);
	getline(file, model);
	getline(file, complect);
	getline(file, segment);
	getline(file, body);
	file >> volume;
	file >> power;
	file >> year;
	file >> price;
	file.get();

	koef = power / price;
}

void car::display_car() {
	cout << "����� ����������: " << brand << endl
		<< "�������� ������: " << model << endl
		<< "�������� ������������: " << complect << endl
		<< "�������� �������: " << segment << endl
		<< "��� �������������� ������: " << body << endl
		<< "����� ��������� � ������: " << volume << endl
		<< "�������� ��������� � �.�. : " << power << endl
		<< "��� �������: " << year << endl
		<< "��������� � ������: " << int(price) << endl << "��������� �������� ��������� � ���������: " << koef << endl << "----------------------" << endl;
}

int arrayUnique(string* ar, int size) // �������, ������������ �������� ������� � ������������ ����������
{
	for (int counter1 = 0; counter1 < size; counter1++)
	{
		for (int counter2 = counter1 + 1; counter2 < size; counter2++)
		{
			if (ar[counter1] == ar[counter2]) // ���� ������ ���������� �������
			{
				for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
				{
					// ��������� ����� ���� ��������� ��������� ������� �� -1, ������� �� ���������� ��������, ����� ���������� �����
					ar[counter_shift] = ar[counter_shift + 1];
				}
				size -= 1; // ��������� ������ ������� �� 1

				if (ar[counter1] == ar[counter2]) // ���� ��������� ������� - �����
				{
					counter2--; // ��������� ������� �� ���������� �������     
				}
			}
		}
	}
	return size;
}

void authorization() {
	cout << "������������ �����������, ������� ������� � ���: " << endl;

	cout << "������� ���: ";
	string name;
	cin >> name;
	cout << "������� �������: ";
	string surname;
	cin >> surname;

	ofstream users_file;
	users_file.open("info_users.txt", ofstream::app);
	users_file << endl << name << " " << surname;
	users_file.close();
}