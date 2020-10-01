#include "car.h"

void car::display_car()
{
	this->WriteInPotok(cout);
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

bool car::operator==(const car& another) 
{
	if (brand != another.brand) return false;
	if (model != another.model) return false;
	if (complect != another.complect) return false;
	if (body != another.body) return false;
	if (volume != another.volume) return false;
	if (power != another.power) return false;
	if (year != another.year) return false;
	if (price != another.price) return false;
	return true;
}

//Оператор ввода из потока
istream& operator>>(istream& stream, car& ncar) {
	ncar.ReadFromPotok(stream);
	return stream;
}

void car::ReadFromPotok(istream& stream)
{
	cout << "Марка автомобиля:  ";
		getline(cin, brand);

		cout << "Название модели: ";
		getline(cin, model);

		cout << "Название комплектации: ";
		getline(cin, complect);

		cout << "Рыночный сегмент: ";
		getline(cin, segment);

		cout << "Тип автомобильного кузова: ";
		getline(cin, body);

		cout << "Объем двигателя в литрах: ";
		volume = ReadInt(cin);

		cout << "Мощность двигателя в л.с. : ";
		power = ReadInt(cin);

		cout << "Год выпуска: ";
		year = ReadInt(cin);

		cout << "Стоимость в рублях: ";
		price = ReadInt(cin);
}

// Оператор вывода в поток
ostream& operator<<(ostream& stream, car& ncar) 
{
	ncar.WriteInPotok(stream);
	return stream;
}

void car::WriteInPotok(ostream& stream)
{
	stream
			<< setw(2) << ""
			<< left << setw(20) << brand
			<< left << setw(20) << model
			<< left << setw(20) << complect
			<< left << setw(15) << segment
			<< left << setw(20) << body
			<< left << setw(15) << volume
			<< left << setw(20) << power
			<< left << setw(15) << year
			<< left << setw(15) << int(price)
			<< endl;
}

// Оператор записи в файл.
ofstream& operator<<(ofstream& file, car& ncar)
{
	ncar.WriteInFile(file);
	return file;
}

void car::WriteInFile(ofstream& file)
{
		file
			<< this->brand << endl
			<< this->model << endl
			<< this->complect << endl
			<< this->segment << endl
			<< this->body << endl
			<< this->volume << endl
			<< this->power << endl
			<< this->year << endl
			<< this->price << endl;
}

//Операция чтения из файла
ifstream& operator >> (ifstream& file, car& ncar)
{
	ncar.ReadFromFile(file);
	return file;
}

void car::ReadFromFile(ifstream& file)
{
	getline(file, brand);
	getline(file, model);
	getline(file, complect);
	getline(file, segment);
	getline(file, body);
	volume = ReadDouble(file);
	power = ReadDouble(file);
	year = ReadInt(file);
	price = ReadDouble(file);
	koef = power / price;
}

int car::ReadInt(istream& stream)
{
	int value;
	stream >> value;
	stream.ignore(256, '\n'); // Пропуск всех символов до перехода на новую строку.
	return value;
}

double car::ReadDouble(istream& stream)
{
	double value;
	stream >> value;
	stream.ignore(256, '\n'); // Пропуск всех символов до перехода на новую строку.
	return value;
}

void car::WriteTableHeader() 
{
	cout
		<< setw(2) << ""
		<< left << setw(20) << "brand"
		<< left << setw(20) << "model"
		<< left << setw(20) << "complect"
		<< left << setw(15) << "segment"
		<< left << setw(20) << "body"
		<< left << setw(15) << "volume"
		<< left << setw(20) << "power"
		<< left << setw(15) << "year"
		<< left << setw(10) << "price"
		<< endl;
}