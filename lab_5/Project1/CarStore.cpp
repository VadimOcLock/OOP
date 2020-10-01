#include "CarStore.h"

carstore::carstore(unsigned int number) 
{
	max_num_cars = number;
	cars = new car*[max_num_cars];
	num_cars = 0;
	cout << "Memory was allocated for " << max_num_cars << " cars." << endl;
}

carstore::~carstore() 
{
	max_num_cars = 0;
	delete[] cars;
	num_cars = 0;
	cout << "Memory was freed." << endl;
}

// Добавить участника.
bool carstore::Add(car* ncar)
{
	bool added = num_cars + 1 <= max_num_cars; // true, если есть место для ещё одной машины.
	if (added)
	{
		cars[num_cars] = ncar; // Записать новую машину.
		num_cars++; // Увеличить текущее количество.
	}
	return added;
}

car* carstore::Remove(int index)
{
	car* ncar = nullptr;
	if (index > -1 && index < num_cars) // Проверка корректности индекса.
	{
		ncar = cars[index]; // Сохранение указателя в возвращаемой переменной.
		num_cars--;
		for (int i = index; i < num_cars; i++)
			cars[i] = cars[i + 1]; // Смещение машин, стоящих после удаляемой, на одну позицию назад.
	}
	return ncar;
}

car* carstore::Remove(car* ncar)
{
	int index = -1;
	for (int i = 0; i < num_cars && index == -1; i++) // Поиск индекса удаляемой машины.
		if (*(cars[i]) == *ncar)
			index = i;
	return Remove(index); // Корректность индекса проверяется в методе удаления по индексу.
}

// Удалить, освободив память, всех машин из контейнера.
void carstore::DeleteAll()
{
	for (int i = 0; i < num_cars; i++) // Удаление машин.
		delete cars[i];
}

//Прочитать список участников из файла 
void carstore::ReadFromFile(ifstream& file)
{
	car* ncar;
	int Count = car::ReadInt(file);
	for (int i = 0; i < Count; i++)
	{
		ncar = new car();
		file >> *ncar;
		*this += ncar;
	}
}

void carstore::ReadFromPotok()
{
	string choice;
	car* ncar = new car();
	int Count = 0;
	do
	{
		cin >> *ncar;
		*this += ncar;
		cout << "Do you wanna add one more?yes/no: ";
		Count++;
		getline(cin, choice);
	} while (choice == "yes");
}

void carstore::WriteInFile(ofstream& file)
{
	file << num_cars << endl;
	for (int i = 0; i < num_cars; i++)
	{
		file << *(cars[i]);
	}
}

void carstore::WriteToTable()
{
	car::WriteTableHeader(); // Вывод заголовка таблицы машин.
	for (int i = 0; i < num_cars; i++)
		cars[i]->WriteInPotok(cout); // Вывести машину в строку таблицы.
	if (num_cars == 0)
		cout << "There are no books." << endl;
}

void carstore::optimal_car() {
	double max = cars[0]->GetKoef();
	int indexOptimalCar = 0;
	for (int i = 0; i < num_cars; i++) {
		if (cars[i]->GetKoef() > max) {
			max = cars[i]->GetKoef();
			indexOptimalCar = i;
		}
	}
	cout << "Наибольшее отношение Мощности двигателя к Стоимости имеет автомобиль со следущими характеристиками: " << endl;
	car::WriteTableHeader();
	cars[indexOptimalCar]->display_car();
}

void carstore::find_car() 
{

	string* branded = new string[num_cars];

	for (int i = 0; i < num_cars; i++) {
		branded[i] = cars[i]->GetBrand();
	}

	cout << "Модели в ассортименте:" << endl;
	for (int counter1 = 0; counter1 < arrayUnique(branded, num_cars)/*вызов функции отбора значений*/; counter1++)
	{
		cout << branded[counter1] << endl; // печать элементов массива
	}

	delete[] branded;

	cout << "Введите название модели: ";
	string search;
	cin >> search;

	//Поиск совпадений по бренду

	int p = 0;
	for (int i = 0; i < num_cars; i++) {
		if (search == cars[i]->GetBrand()) {
			p++;
		}
	}

	if (p == 0) {
		cout << "Автомобилей по данному запросу не найдено, неверно введена марка автомобиля, попробуйте ещё раз" << endl;
		return;
	}

	car** price_array = new car*[p];
	int p1 = 0;
	for (int i = 0; i < num_cars; i++) {
		if (search == cars[i]->GetBrand()) {
			price_array[p1] = cars[i];
			p1++;
		}
	}

	for (int startIndex = 0; startIndex < p1 - 1; startIndex++) {
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < p1; currentIndex++) {
				if ((price_array[currentIndex])->GetPrice() < (price_array[smallestIndex])->GetPrice())
				smallestIndex = currentIndex;
		}

		std::swap(price_array[startIndex], price_array[smallestIndex]);
	}

	cout << "Доступные комплектации данной модели: " << endl;

	for (int i = 0; i < p1; i++) {
		cout << "(*) " << price_array[i]->GetComplect() << endl;
		cout << "Цена данной комлектации: " << int(price_array[i]->GetPrice()) << endl << "-----------------" << endl;
	}

	delete[] price_array;
}
void carstore::example_car() 
{
	cout << "Марка автомобиля: " << cars[0]->GetBrand() << endl
			<< "Название модели: " << cars[0]->GetModel() << endl
			<< "Название комплектации: " << cars[0]->GetComplect() << endl
			<< "Рыночный сегмент: " << cars[0]->GetSegment() << endl
			<< "Тип автомобильного кузова: " << cars[0]->GetBody() << endl
			<< "Объем двигателя в литрах: " << cars[0]->GetVolume() << endl
			<< "Мощность двигателя в л.с. : " << cars[0]->GetPower() << endl
			<< "Год выпуска: " << cars[0]->GetYear() << endl
			<< "Стоимость в рублях: " << int(cars[0]->GetPrice()) << endl << "----------------------" << endl;
}
void carstore::enter_car() {
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

ofstream& operator<< (ofstream& file, carstore& store)
{
	store.WriteInFile(file);
	return file;
}

ifstream& operator>>(ifstream& file, carstore& store)
{
	store.ReadFromFile(file);
	return file;
}

istream& operator>>(istream& stream, carstore& store)
{
	store.ReadFromPotok();
	return stream;
}

void carstore::SortByMaxRelationParticipants() 
{
	for (int i = 1; i < num_cars - 1; i++)
	{
		for (int j = 1; j < num_cars - 1; j++) {
			if (cars[j]->GetKoef() > cars[j - 1]->GetKoef())
			{
				// меняем элементы местами
				car* t = cars[j];
				cars[j] = cars[j - 1];
				cars[j - 1] = t;
			}
		}
	}
}

void carstore::SearchForComplectByBrand() const
{
	string* branded = new string[num_cars];

	for (int i = 0; i < num_cars; i++) {
		branded[i] = cars[i]->GetBrand();
	}

	cout << "Модели в ассортименте:" << endl;
	for (int counter1 = 0; counter1 < arrayUnique(branded, num_cars)/*вызов функции отбора значений*/; counter1++)
	{
		cout << branded[counter1] << endl; // печать элементов массива
	}

	delete[] branded;

	cout << "Введите название модели: ";
	string search;
	cin >> search;

	//Поиск совпадений по бренду

	int p = 0;
	for (int i = 0; i < num_cars; i++) {
		if (search == cars[i]->GetBrand()) {
			p++;
		}
	}

	if (p == 0) {
		cout << "Автомобилей по данному запросу не найдено, неверно введена марка автомобиля, попробуйте ещё раз" << endl;
		return;
	}

	car** price_array = new car * [p];
	int p1 = 0;
	for (int i = 0; i < num_cars; i++) {
		if (search == cars[i]->GetBrand()) {
			price_array[p1] = cars[i];
			p1++;
		}
	}

	for (int startIndex = 0; startIndex < p1 - 1; startIndex++) {
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < p1; currentIndex++) {
			if ((price_array[currentIndex])->GetPrice() < (price_array[smallestIndex])->GetPrice())
				smallestIndex = currentIndex;
		}

		std::swap(price_array[startIndex], price_array[smallestIndex]);
	}

	cout << "Доступные комплектации данной модели: " << endl;

	for (int i = 0; i < p1; i++) {
		cout << "(*) " << price_array[i]->GetComplect() << endl;
		cout << "Цена данной комлектации: " << int(price_array[i]->GetPrice()) << endl << "-----------------" << endl;
	}

	delete[] price_array;
}