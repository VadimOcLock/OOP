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
	cout << "Марка автомобиля: " << brand << endl
		<< "Название модели: " << model << endl
		<< "Название комплектации: " << complect << endl
		<< "Рыночный сегмент: " << segment << endl
		<< "Тип автомобильного кузова: " << body << endl
		<< "Объем двигателя в литрах: " << volume << endl
		<< "Мощность двигателя в л.с. : " << power << endl
		<< "Год выпуска: " << year << endl
		<< "Стоимость в рублях: " << int(price) << endl << "Отношение Мощности двигателя к Стоимости: " << koef << endl << "----------------------" << endl;
}

int arrayUnique(string* ar, int size) // функция, определяющая элементы массива в единственном экземпляре
{
	for (int counter1 = 0; counter1 < size; counter1++)
	{
		for (int counter2 = counter1 + 1; counter2 < size; counter2++)
		{
			if (ar[counter1] == ar[counter2]) // если найден одинаковый элемент
			{
				for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
				{
					// выполнить сдвиг всех остальных элементов массива на -1, начиная со следующего элемента, после найденного дубля
					ar[counter_shift] = ar[counter_shift + 1];
				}
				size -= 1; // уменьшить размер массива на 1

				if (ar[counter1] == ar[counter2]) // если следующий элемент - дубль
				{
					counter2--; // выполнить переход на предыдущий элемент     
				}
			}
		}
	}
	return size;
}

void authorization() {
	cout << "Обязательная авторизация, введите Фамилию и Имя: " << endl;

	cout << "Введите имя: ";
	string name;
	cin >> name;
	cout << "Введите Фамилию: ";
	string surname;
	cin >> surname;

	ofstream users_file;
	users_file.open("info_users.txt", ofstream::app);
	users_file << endl << name << " " << surname;
	users_file.close();
}