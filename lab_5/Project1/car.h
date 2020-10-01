#ifndef CAR
#define CAR
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include <locale>
#include <fstream>
#include <Windows.h>

using namespace std;

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
	// �������.
	string GetBrand() const { return brand; };
	string GetModel() const { return model; };
	string GetComplect() const { return complect; };
	string GetSegment() const { return segment; };
	string GetBody() const { return body; };
	double GetVolume() const { return volume; };
	double GetPower() const { return power; };
	unsigned int GetYear() const { return year; };
	double GetPrice() const { return price; };
	double GetKoef() const { return koef; };

	void ReadFromPotok(istream& stream);
	void WriteInPotok(ostream& stream);
	void WriteInFile(ofstream& file);
	void ReadFromFile(ifstream& file);

	// ���������� ����������.
	// �������� �������� ���������.
	bool operator==(const car& another);
	// �������� ������ � �����.
	friend ostream& operator<<(ostream& stream, const car&);
	// �������� ������ �� ������.
	friend istream& operator>>(istream& stream, car&);
	// �������� ������ � ����.
	friend ofstream& operator<<(ofstream& file, car&);
	// �������� ������ �� ������.
	friend ifstream& operator>>(ifstream& file, car&);

	void display_car();
	static int ReadInt(istream& stream); // ������� ��� ������ int �� ��������� ������ ���������� ������.
	static double ReadDouble(istream& stream); // ������� ��� ������ double �� ��������� ������ ���������� ������.
	static void WriteTableHeader(); // ������� ��� ������ ��������� �������.
};
void authorization();					// ����������� ������������.
int arrayUnique(string* ar, int size);  // ������� ���������� �������, ��������� ��������� ��������.
#endif // !CAR#pragma once