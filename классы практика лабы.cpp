#include <iostream>
#include <vector>

using namespace std;

class Atribut
{
private:
	double one, two, five, ten, fift;
	double oneh, fiveh, oneth, fiveth;
	double onek, fivek, tenk, fiftk, sum;
	friend class Money;
	friend double sum(Atribut);
	friend ostream& operator << (ostream&, const Atribut&);
	friend istream& operator >> (istream&, Atribut&);
public:
	Atribut(){}
	Atribut(double one, double two, double five,
		double ten, double fift, double oneh, double fiveh,
		double oneth, double fiveth, double onek,
		double fivek, double tenk, double fiftk) : one(one), two(two), five(five), ten(ten),
		fift(fift), oneh(oneh), fiveh(fiveh),
		oneth(oneth), fiveth(fiveth), onek(onek),
		fivek(fivek), tenk(tenk), fiftk(fiftk)
	{}
};

class Money
{
private:
	Atribut money;
public:
	Money()
	{
		cin >> money;
	}
	Money(double one, double two, double five,
		double ten, double fift, double oneh, double fiveh,
		double oneth, double fiveth, double onek=0,
		double fivek=0, double tenk=0, double fiftk =0): 
		money(Atribut(one, two,five,
			ten,fift, oneh, fiveh,
		    oneth, fiveth, onek,
			fivek, tenk, fiftk)) 
	{}
	void output()
	{
		cout << money;
	}
	double operator - (Money money2)
	{
		cout << endl << endl << sum(money) - sum(money2.money) << endl;
		return sum(money) - sum(money2.money);
	}
	double operator / (double value)
	{
		cout << sum(money) / value << endl;
		return sum(money) / value;
	}
	void status()
	{
		cout << money;
	}
};
istream& operator >> (istream& cin, Atribut& money)
{
	cout << endl;
	cout << "-------------------РУБЛИ--------------------" << endl;
	cout << "Введите количество купюр номиналом 1 рубль: "; cin >> money.one;
	cout << "Введите количество купюр номиналом 2 рубля: "; cin >> money.two;
	cout << "Введите количество купюр номиналом 5 рублей: "; cin >> money.five;
	cout << "Введите количество купюр номиналом 10 рублей: "; cin >> money.ten;
	cout << "Введите количество купюр номиналом 50 рублей: "; cin >> money.fift;
	cout << "Введите количество купюр номиналом 100 рублей: "; cin >> money.oneh;
	cout << "Введите количество купюр номиналом 500 рублей: "; cin >> money.fiveh;
	cout << "Введите количество купюр номиналом 1000 рублей: "; cin >> money.oneth;
	cout << "Введите количество купюр номиналом 5000 рублей: "; cin >> money.fiveth;
	cout << "------------------КОПЕЙКИ--------------------" << endl;
	cout << "Введите количество копеек номиналом 1: "; cin >> money.onek;
	cout << "Введите количесвто копеек номиналом 5: "; cin >> money.fivek;
	cout << "Введите количесвто копеек номиналом 10: "; cin >> money.tenk;
	cout << "Введите количество копеек номиналом 50: "; cin >> money.fiftk;
	cout << endl;
	cout << "Сумма = " << sum(money);
	return cin;
}
double sum(Atribut mon)
{
	return (mon.one * 1 + mon.two * 2 + mon.five * 5
		+ mon.ten * 10 + mon.fift * 50 + mon.oneh * 100
		+ mon.fiveh * 500 + mon.oneth * 1000 + mon.fiveth * 5000
		+ mon.onek / 100 + mon.fivek * 5 / 100
		+ mon.tenk * 10 / 100 + mon.fiftk * 50 / 100);
}
ostream& operator << (ostream& cout, const Atribut& mon)
{
	cout << endl;
	cout << "-------------------------------" << endl;
	cout << "Сумма купюр номиналом 1 рубль: " << mon.one << endl;
	cout << "Сумма купюр номиналом 2 рублей: " << mon.two * 2 << endl;
	cout << "Сумма купюр номиналом 5 рублей: " << mon.five * 5 << endl;
	cout << "Сумма купюр номиналом 10 рублей: " << mon.ten * 10 << endl;
	cout << "Сумма купюр номиналом 50 рублей: " << mon.fift * 50 << endl;
	cout << "Сумма купюр номиналом 100 рублей: " << mon.oneh * 100 << endl;
	cout << "Сумма купюр номиналом 500 рублей: " << mon.fiveh * 500 << endl;
	cout << "Сумма купюр номиналом 1000 рублей: " << mon.oneth * 1000 << endl;
	cout << "Сумма купюр номиналом 5000 рублей: " << mon.fiveh * 5000 << endl;
	cout << "Сумма копеек номиналом 1: " << mon.onek / 100 << endl;
	cout << "Сумма копеек номиналом 5: " << mon.fivek * 5 / 100 << endl;
	cout << "Сумма копеек номиналом 10: " << mon.tenk * 10 / 100 << endl;
	cout << "Сумма копеек номиналом 50: " << mon.fiftk * 50 / 100 << endl;
	cout << "---------------------------------" << endl;
	cout << "Сумма = " << sum(mon);
	return cout;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Money money_1;
	Money money_2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
	double a,b,c;
	double value = 5; //Значение для деления
	money_1.status();
	money_2.status();
	a = money_1 - money_2;
	b = money_1 / value;
	c = money_2 / value;
}