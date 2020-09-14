#include "car.h"
#include <iostream>
using namespace std;

string car::GetBrand() {
	return brand;
}

double car::GetPrice() {
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
void car::display_car(string pointer) {
	if (pointer == "show") {
		cout << "����� ����������: " << brand << endl
			<< "�������� ������: " << model << endl
			<< "�������� ������������: " << complect << endl
			<< "�������� �������: " << segment << endl
			<< "��� �������������� ������: " << body << endl
			<< "����� ��������� � ������: " << volume << endl
			<< "�������� ��������� � �.�. : " << power << endl
			<< "��� �������: " << year << endl
			<< "��������� � ������: " << int(price) << endl << "----------------------" << endl;
	}
}

void optimal_car(car acollection[], int n) {
	double max = acollection[0].GetKoef();
	int indexOptimalCar = 0;
	for (int i = 0; i < n; i++) {
		if (acollection[i].GetKoef() > max) {
			max = acollection[i].GetKoef();
			indexOptimalCar = i;
		}
	}
	cout << "���������� ��������� �������� ��������� � ��������� ����� ���������� �� ��������� ����������������: " << endl;
	acollection[indexOptimalCar].display_car();
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

string* branded;
void find_car(car acollection[], int n) {

	//���� ������ � ����������
	int size = n;
	branded = new string[size];

	for (int i = 0; i < size; i++) {
		branded[i] = acollection[i].GetBrand();
	}

	cout << "������ � ������������:" << endl;
	for (int counter1 = 0; counter1 < arrayUnique(branded, n)/*����� ������� ������ ��������*/; counter1++)
	{
		cout << branded[counter1] << endl; // ������ ��������� �������
	}

	delete[] branded;

	cout << "������� �������� ������: ";
	string search;
	cin >> search;

	//����� ���������� �� ������

	int p = 0;
	for (int i = 0; i < n; i++) {
		if (search == acollection[i].GetBrand()) {
			p++;
		}
	}

	if (p == 0) {
		cout << "����������� �� ������� ������� �� �������, ������� ������� ����� ����������, ���������� ��� ���" << endl;
		return;
	}

	car* price_array = new car[p];
	int p1 = 0;
	for (int i = 0; i < n; i++) {
		if (search == acollection[i].GetBrand()) {
			price_array[p1] = acollection[i];
			p1++;
		}
	}

	for (int startIndex = 0; startIndex < p1 - 1; startIndex++) {
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < p1; currentIndex++) {
			if ((price_array[currentIndex]).GetPrice() < (price_array[smallestIndex]).GetPrice())
				smallestIndex = currentIndex;
		}

		std::swap(price_array[startIndex], price_array[smallestIndex]);
	}

	cout << "��������� ������������ ������ ������: " << endl;

	for (int i = 0; i < p1; i++) {
		cout << "(*) " << price_array[i].GetComplect() << endl;
		cout << "���� ������ �����������: " << int(price_array[i].GetPrice()) << endl << "-----------------" << endl;
	}

	delete[] price_array;
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

void enter_car() {
	ofstream outfile;
	outfile.open("info_ads.txt", ofstream::app);

	string brand_n;
	string model_n;
	string complect_n;
	string segment_n;
	string body_n;
	double volume_n;
	double power_n;
	unsigned int year_n;
	double price_n;

	cout << "������� ���������� � ������: " << endl
		<< "����� ����������: ";
	cin >> brand_n;
	cout << "�������� ������: ";
	cin >> model_n;
	cout << "�������� ������������: ";
	cin >> complect_n;
	cout << "�������� �������: ";
	cin >> segment_n;
	cout << "��� �������������� ������: ";
	cin >> body_n;
	cout << "����� ��������� � ������: ";
	cin >> volume_n;
	cout << "�������� ��������� � �.�.: ";
	cin >> power_n;
	cout << "��� �������: ";
	cin >> year_n;
	cout << "��������� � ������: ";
	cin >> price_n;

	outfile << endl
		<< brand_n << endl
		<< model_n << endl
		<< complect_n << endl
		<< segment_n << endl
		<< body_n << endl
		<< volume_n << endl
		<< power_n << endl
		<< year_n << endl
		<< price_n;

	outfile.close();
}