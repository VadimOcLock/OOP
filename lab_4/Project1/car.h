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

	string GetBrand();
	string GetModel();
	string GetComplect();
	string GetSegment();
	string GetBody();
	double GetVolume();
	double GetPower();
	unsigned int GetYear();
	double GetPrice();
	double GetKoef();
};

void authorization();
int arrayUnique(string* ar, int size);
#endif // !CAR#pragma once