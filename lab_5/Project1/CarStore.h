#ifndef CARSTORE_H
#define CARSTORE_H
#include "car.h"

class carstore // ������� �����.
{
public:
	carstore(unsigned int);			// ����������� ������ carstore.
	~carstore();					// ���������� ������ carstore.
	void optimal_car();				// ���������� ����������� ������ �� �������� �����������.
	void find_car();				// �������, ������������ ������������ ����.
	void example_car();				// ����������� ���� � ������-����������.
	void enter_car();				// ���� ���� � ����� ����������.

	void ReadFromFile(ifstream& filepath);
	void ReadFromPotok();
	void WriteInFile(ofstream& file);

	void WriteToTable();

	int GetMax_num_cars() const { return max_num_cars; }
	int GetNum_cars() const { return num_cars; }

	bool Add(car*); // �������� ���������.
	car* Remove(car*);
	car* Remove(int index);
	void DeleteAll();

	// ��������������� ����������.
	carstore& operator +=(car* ncar) { Add(ncar); return *this; }
	carstore& operator -=(car* participant) { Remove(participant); return *this; };

	friend ofstream& operator<<(ofstream& file, carstore& participant);
	friend ifstream& operator>>(ifstream& file, carstore& participant);
	friend istream& operator>>(istream& stream, carstore& participant);

	void SortByMaxRelationParticipants();
	void SearchForComplectByBrand() const;

private:
	int max_num_cars;		// ������������ ���������� ����� � ��������.
	int num_cars;			// ������� ���������� ����� � ��������.   
	car** cars;				// ������ �� ������ ����������� ��������� �����.
};
#endif // !CARSTORE
