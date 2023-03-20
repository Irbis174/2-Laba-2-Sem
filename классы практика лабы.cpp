#include <iostream>
#include "for laba.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Money money_1;
	Money money_2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13); //ввод кол-ва купюр разного номинала
	double a, b, c, d;
	double value = 5; //Значение для деления
	money_1.status();
	money_2.status();
	a = money_1 - money_2; 
	b = money_2 - money_1;
	c = money_1 / value;
	d = money_2 / value;
}