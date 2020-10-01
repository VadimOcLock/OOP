#include "car.h"

void car::display_car()
{
	this->WriteInPotok(cout);
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

//�������� ����� �� ������
istream& operator>>(istream& stream, car& ncar) {
	ncar.ReadFromPotok(stream);
	return stream;
}

void car::ReadFromPotok(istream& stream)
{
	cout << "����� ����������:  ";
		getline(cin, brand);

		cout << "�������� ������: ";
		getline(cin, model);

		cout << "�������� ������������: ";
		getline(cin, complect);

		cout << "�������� �������: ";
		getline(cin, segment);

		cout << "��� �������������� ������: ";
		getline(cin, body);

		cout << "����� ��������� � ������: ";
		volume = ReadInt(cin);

		cout << "�������� ��������� � �.�. : ";
		power = ReadInt(cin);

		cout << "��� �������: ";
		year = ReadInt(cin);

		cout << "��������� � ������: ";
		price = ReadInt(cin);
}

// �������� ������ � �����
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

// �������� ������ � ����.
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

//�������� ������ �� �����
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
	stream.ignore(256, '\n'); // ������� ���� �������� �� �������� �� ����� ������.
	return value;
}

double car::ReadDouble(istream& stream)
{
	double value;
	stream >> value;
	stream.ignore(256, '\n'); // ������� ���� �������� �� �������� �� ����� ������.
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