#ifndef CAR
#define CAR
#include <string>
#include <fstream>
using std::string;
using std::ifstream;

class car {
private:
	string brand;
	string model;
	string complect;
	string segment;
	string body;
	double volume;
	double power;
	unsigned int year;
	double price;
	double koef;

public:
	void read_car(ifstream& file);
	void display_car();
	void display_car(string);

	string GetBrand();
	double GetPrice();
	string GetComplect();
	double GetKoef();
};

void authorization();
void optimal_car(car acollection[], int n);
int arrayUnique(string* ar, int size);
void find_car(car acollection[], int n);
void enter_car();
#endif // !CAR#pragma once
