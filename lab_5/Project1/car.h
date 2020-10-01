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
	// Геттеры.
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

	// Перегрузка операторов.
	// Оператор проверки равенства.
	bool operator==(const car& another);
	// Оператор записи в поток.
	friend ostream& operator<<(ostream& stream, const car&);
	// Оператор чтения из потока.
	friend istream& operator>>(istream& stream, car&);
	// Оператор записи в файл.
	friend ofstream& operator<<(ofstream& file, car&);
	// Оператор чтения из потока.
	friend ifstream& operator>>(ifstream& file, car&);

	void display_car();
	static int ReadInt(istream& stream); // Функция для чтения int из отдельной строки текстового потока.
	static double ReadDouble(istream& stream); // Функция для чтения double из отдельной строки текстового потока.
	static void WriteTableHeader(); // Функция для вывода заголовка таблицы.
};
void authorization();					// Авторизация пользователя.
int arrayUnique(string* ar, int size);  // Функция сортировки массива, убирающая повторные элементы.
#endif // !CAR#pragma once