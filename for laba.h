#pragma once
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
	Atribut() {}
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
		double oneth, double fiveth, double onek = 0,
		double fivek = 0, double tenk = 0, double fiftk = 0) :
		money(Atribut(one, two, five,
			ten, fift, oneh, fiveh,
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
	cout << "-------------------�����--------------------" << endl;
	cout << "������� ���������� ����� ��������� 1 �����: "; cin >> money.one;
	cout << "������� ���������� ����� ��������� 2 �����: "; cin >> money.two;
	cout << "������� ���������� ����� ��������� 5 ������: "; cin >> money.five;
	cout << "������� ���������� ����� ��������� 10 ������: "; cin >> money.ten;
	cout << "������� ���������� ����� ��������� 50 ������: "; cin >> money.fift;
	cout << "������� ���������� ����� ��������� 100 ������: "; cin >> money.oneh;
	cout << "������� ���������� ����� ��������� 500 ������: "; cin >> money.fiveh;
	cout << "������� ���������� ����� ��������� 1000 ������: "; cin >> money.oneth;
	cout << "������� ���������� ����� ��������� 5000 ������: "; cin >> money.fiveth;
	cout << "------------------�������--------------------" << endl;
	cout << "������� ���������� ������ ��������� 1: "; cin >> money.onek;
	cout << "������� ���������� ������ ��������� 5: "; cin >> money.fivek;
	cout << "������� ���������� ������ ��������� 10: "; cin >> money.tenk;
	cout << "������� ���������� ������ ��������� 50: "; cin >> money.fiftk;
	cout << endl;
	cout << "����� = " << sum(money);
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
	cout << "����� ����� ��������� 1 �����: " << mon.one << endl;
	cout << "����� ����� ��������� 2 ������: " << mon.two * 2 << endl;
	cout << "����� ����� ��������� 5 ������: " << mon.five * 5 << endl;
	cout << "����� ����� ��������� 10 ������: " << mon.ten * 10 << endl;
	cout << "����� ����� ��������� 50 ������: " << mon.fift * 50 << endl;
	cout << "����� ����� ��������� 100 ������: " << mon.oneh * 100 << endl;
	cout << "����� ����� ��������� 500 ������: " << mon.fiveh * 500 << endl;
	cout << "����� ����� ��������� 1000 ������: " << mon.oneth * 1000 << endl;
	cout << "����� ����� ��������� 5000 ������: " << mon.fiveh * 5000 << endl;
	cout << "����� ������ ��������� 1: " << mon.onek / 100 << endl;
	cout << "����� ������ ��������� 5: " << mon.fivek * 5 / 100 << endl;
	cout << "����� ������ ��������� 10: " << mon.tenk * 10 / 100 << endl;
	cout << "����� ������ ��������� 50: " << mon.fiftk * 50 / 100 << endl;
	cout << "---------------------------------" << endl;
	cout << "����� = " << sum(mon);
	return cout;
}
