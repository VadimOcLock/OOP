#ifndef CARSTORE_H
#define CARSTORE_H
#include <string> 
#include <fstream>
#include "car.h"

class carstore // Магазин машин.
{
public:
	carstore(unsigned int);			// Конструктор класса carstore.
	~carstore();					// Деструктор класса carstore.
	void add_car(car);				// Добавление экземляра в коллекцию.
	void read_from_file(string);	// Считывание инфо о машинах с файла.
	void display_all();				// Отображение всех машин.
	void optimal_car();				// Нахождение оптимальной машины по критерию коэфициента.
	void find_car();				// Функция, показывающая комплектации авто.
	void example_car();				// Отображение инфо о машине-экземпляре.
	void enter_car();				// Ввод инфо о новом обьявлении.

private:
	int max_num_cars;		// Максимальное количество машин в магазине.
	int num_cars;			// Текущее количество машин в магазине.   
	car* cars;				// Ссылка на массив экземпляров коллекции машин.
};


#endif // !CARSTORE
