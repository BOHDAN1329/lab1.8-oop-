#include "Bill.h"
#include <string>
#include <iostream>

string Bill::toString()
{
	stringstream sout;
	setSum();
	sout << "To pay: " << sum << endl;
	return sout.str();
}

void Bill::setSum()
{
	int minute = Total(start, finish) / 60;
	taruf = taruf * (1.0 * (100 - discount) / 100);
	sum = minute * taruf;
}

void Bill::display()
{
	cout << toString() << endl;
}

bool Bill::init(string last_name, string phone_number, double taruf, int discount, Time start, Time finish)
{
	start.init(start);
	finish.init(finish);
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->taruf = taruf;
	this->discount = discount;
	return true;
}

void Bill::read()
{
	cout << "Start time :" << endl;
	start.read();
	cout << "Finish time :" << endl;
	finish.read();
	cout << "Enter last name :";
	cin >> last_name;
	cout << "Enter phone number :";
	cin >> phone_number;
	cout << "Enter taruf :";
	cin >> taruf;
	cout << "Enter discount :";
	cin >> discount;
}
bool Bill::Time::init(unsigned int h, unsigned int m, unsigned int s)
{

	if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
		setHour(h);
		setMinute(m);
		setSecond(s);
		return true;

	}
	else
		return false;

}


void Bill::Time::read()
{
	unsigned int h, m, s;

	do {
		cout << "Hour = "; cin >> h;
		cout << "Minute = "; cin >> m;
		cout << "Second = "; cin >> s;
	} while (!init(h, m, s));
}

void Bill::Time::display() const
{
	cout << "Hour = " << hour << endl;
	cout << "Minute = " << minute << endl;
	cout << "Second = " << second << endl;
}

int Bill::Time::toSec()
{
	return this->hour * 3600 + this->minute * 60 + this->second;
}

int Bill::Time::toMin()
{
	return ceil(toSec() / 60);
}

void Bill::Time::init(string str)
{
	hour = atoi(&str[0]);
	minute = atoi(&str[3]);
	second = atoi(&str[6]);
}

void Bill::Time::init(int sec)
{
	hour = (int)sec / 3600;
	sec -= hour * 3600;
	minute = (int)sec / 60;
	sec -= minute * 60;
	second = sec;
}

void Bill::Time::init(Bill::Time time)
{
	*this = time;
}


int Total(Bill::Time time1, Bill::Time time2)
{
	Bill::Time result;
	result.hour = time2.hour - time1.hour;
	result.minute = time2.minute - time1.minute;
	result.second = time2.second - time1.second;
	int res = result.toSec();
	return res;
}


void Bill::Time::Sum(int sec)
{
	this->hour += (int)sec / 3600;
	sec -= ((int)sec / 3600) * 3600;
	this->minute += (int)sec / 60;
	sec -= ((int)sec / 60) * 60;
	this->second += sec;
}

void Bill::Time::Dif(int sec)
{
	this->hour -= (int)sec / 3600;
	sec -= ((int)sec / 3600) * 3600;
	this->minute -= (int)sec / 60;
	sec -= ((int)sec / 60) * 60;
	this->second -= sec;
}

bool isGreater(Bill::Time time1, Bill::Time time2)
{
	return((time1.hour * 3600 + time1.minute * 60 + time1.second) > (time2.hour * 3600 + time2.minute * 60 + time2.second));
}

bool isLower(Bill::Time time1, Bill::Time time2)
{
	return(!(isGreater(time1, time2)));
}

bool Equal(Bill::Time time1, Bill::Time time2)
{
	return((time1.hour * 3600 + time1.minute * 60 + time1.second) == (time2.hour * 3600 + time2.minute * 60 + time2.second));
}

