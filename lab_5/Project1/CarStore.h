#ifndef CARSTORE_H
#define CARSTORE_H
#include "car.h"

class carstore // Магазин машин.
{
public:
	carstore(unsigned int);			// Конструктор класса carstore.
	~carstore();					// Деструктор класса carstore.
	void optimal_car();				// Нахождение оптимальной машины по критерию коэфициента.
	void find_car();				// Функция, показывающая комплектации авто.
	void example_car();				// Отображение инфо о машине-экземпляре.
	void enter_car();				// Ввод инфо о новом обьявлении.

	void ReadFromFile(ifstream& filepath);
	void ReadFromPotok();
	void WriteInFile(ofstream& file);

	void WriteToTable();

	int GetMax_num_cars() const { return max_num_cars; }
	int GetNum_cars() const { return num_cars; }

	bool Add(car*); // Добавить участника.
	car* Remove(car*);
	car* Remove(int index);
	void DeleteAll();

	// Переопределение операторов.
	carstore& operator +=(car* ncar) { Add(ncar); return *this; }
	carstore& operator -=(car* participant) { Remove(participant); return *this; };

	friend ofstream& operator<<(ofstream& file, carstore& participant);
	friend ifstream& operator>>(ifstream& file, carstore& participant);
	friend istream& operator>>(istream& stream, carstore& participant);

	void SortByMaxRelationParticipants();
	void SearchForComplectByBrand() const;

private:
	int max_num_cars;		// Максимальное количество машин в магазине.
	int num_cars;			// Текущее количество машин в магазине.   
	car** cars;				// Ссылка на массив экземпляров коллекции машин.
};
#endif // !CARSTORE
