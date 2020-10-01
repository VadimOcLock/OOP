#include "CarStore.h"

#define AdsPath "info_ads.txt" // ����������������: ���� � ����� �� ������� ����������.
#define UsersPath "info_users.txt" // ����������������: ���� � ����� �� ������� �������������.

using namespace std;

int SelectAction() 
{
	cout << "----- ----- ----- -----" << endl;
	cout << "Menu:" << endl;
	cout << setw(2) << 1 << " / " << "Add car." << endl;
	cout << setw(2) << 2 << " / " << "Show ADS." << endl;
	cout << setw(2) << 3 << " / " << "Read cars from file." << endl;
	cout << setw(2) << 4 << " / " << "Write cars to default file." << endl;
	cout << setw(2) << 5 << " / " << "Remove car from carstore." << endl;
	cout << setw(2) << 6 << " / " << "Show the car with the highest rate" << endl;
	cout << setw(2) << 7 << " / " << "Search for complects by brand." << endl;
	cout << setw(2) << 8 << " / " << "Exit." << endl;
	cout << "Enter the number: ";
	return car::ReadInt(cin);
}

int main(void) 
{
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����.
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������.

	carstore my_carstore(30);
	ifstream in(AdsPath);
	in >> my_carstore;
	in.close();
	
	int action;


	do 
	{
		action = SelectAction();
		switch (action)
		{
		case 1:
		{
			car* test = new car;
			test->ReadFromPotok(cin);
			my_carstore += test; // � ������� ���������� ��������� ����� ������.
			break;
		}
		case 2: 
		{
			my_carstore.WriteToTable();
			break;
		}
		case 3:
		{
			string filepath;
			cout << "Enter path: ";
			getline(cin, filepath);
			ifstream in(filepath);
			if (in)
			{
				in >> my_carstore;
				in.close();
			}
			cout << "File read" << endl;
			break;
		}
		case 4:
		{
			string filepath;
			cout << "Enter path: ";
			getline(cin, filepath);
			ofstream inn(filepath);
			if (inn)
			{
				inn << my_carstore;
				inn.close();
				cout << "File recorded" << endl;
			}
			break;
		}
		case 5:
		{
			car xtest;
			xtest.ReadFromPotok(cin);
			my_carstore -= &xtest;
			break;
		}
		case 6: 
		{
			my_carstore.optimal_car();
			break;
		}
		case 7:
		{
			my_carstore.SearchForComplectByBrand();
			break;
		}
		default:
			action = -1;
			break;
		}
	} while (action != -1);

	return 0;
}