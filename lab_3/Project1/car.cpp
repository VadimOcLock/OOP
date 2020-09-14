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
void car::display_car(string pointer) {
	if (pointer == "show") {
		cout << "Марка автомобиля: " << brand << endl
			<< "Название модели: " << model << endl
			<< "Название комплектации: " << complect << endl
			<< "Рыночный сегмент: " << segment << endl
			<< "Тип автомобильного кузова: " << body << endl
			<< "Объем двигателя в литрах: " << volume << endl
			<< "Мощность двигателя в л.с. : " << power << endl
			<< "Год выпуска: " << year << endl
			<< "Стоимость в рублях: " << int(price) << endl << "----------------------" << endl;
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
	cout << "Наибольшее отношение Мощности двигателя к Стоимости имеет автомобиль со следущими характеристиками: " << endl;
	acollection[indexOptimalCar].display_car();
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

string* branded;
void find_car(car acollection[], int n) {

	//Ввод модели с клавиатуры
	int size = n;
	branded = new string[size];

	for (int i = 0; i < size; i++) {
		branded[i] = acollection[i].GetBrand();
	}

	cout << "Модели в ассортименте:" << endl;
	for (int counter1 = 0; counter1 < arrayUnique(branded, n)/*вызов функции отбора значений*/; counter1++)
	{
		cout << branded[counter1] << endl; // печать элементов массива
	}

	delete[] branded;

	cout << "Введите название модели: ";
	string search;
	cin >> search;

	//Поиск совпадений по бренду

	int p = 0;
	for (int i = 0; i < n; i++) {
		if (search == acollection[i].GetBrand()) {
			p++;
		}
	}

	if (p == 0) {
		cout << "Автомобилей по данному запросу не найдено, неверно введена марка автомобиля, попробуйте ещё раз" << endl;
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

	cout << "Доступные комплектации данной модели: " << endl;

	for (int i = 0; i < p1; i++) {
		cout << "(*) " << price_array[i].GetComplect() << endl;
		cout << "Цена данной комлектации: " << int(price_array[i].GetPrice()) << endl << "-----------------" << endl;
	}

	delete[] price_array;
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

	cout << "Введите информацию о машине: " << endl
		<< "Марка автомобиля: ";
	cin >> brand_n;
	cout << "Название модели: ";
	cin >> model_n;
	cout << "Название комплектации: ";
	cin >> complect_n;
	cout << "Рыночный сегмент: ";
	cin >> segment_n;
	cout << "Тип автомобильного кузова: ";
	cin >> body_n;
	cout << "Объем двигателя в литрах: ";
	cin >> volume_n;
	cout << "Мощность двигателя в л.с.: ";
	cin >> power_n;
	cout << "Год выпуска: ";
	cin >> year_n;
	cout << "Стоимость в рублях: ";
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