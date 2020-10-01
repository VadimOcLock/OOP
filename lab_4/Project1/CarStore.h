#ifndef CARSTORE_H
#define CARSTORE_H
#include <string> 
#include <fstream>
#include "car.h"

class carstore // ������� �����.
{
public:
	carstore(unsigned int);			// ����������� ������ carstore.
	~carstore();					// ���������� ������ carstore.
	void add_car(car);				// ���������� ��������� � ���������.
	void read_from_file(string);	// ���������� ���� � ������� � �����.
	void display_all();				// ����������� ���� �����.
	void optimal_car();				// ���������� ����������� ������ �� �������� �����������.
	void find_car();				// �������, ������������ ������������ ����.
	void example_car();				// ����������� ���� � ������-����������.
	void enter_car();				// ���� ���� � ����� ����������.

private:
	int max_num_cars;		// ������������ ���������� ����� � ��������.
	int num_cars;			// ������� ���������� ����� � ��������.   
	car* cars;				// ������ �� ������ ����������� ��������� �����.
};


#endif // !CARSTORE
