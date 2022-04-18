#pragma once
#include <iostream>
#include <string>
#include "Time.h"
#include <sstream>
using namespace std;

class Bill
{
public:
	class Time
	{
	private:
		unsigned int hour;
		unsigned int minute;
		unsigned int second;
	public:
		unsigned int getHour() const { return hour; };
		unsigned int getMinute() const { return minute; };
		unsigned int getSecond() const { return second; };
		void setHour(unsigned int value) { hour = value; }
		void setMinute(unsigned int value) { minute = value; }
		void setSecond(unsigned int value) { second = value; }

		bool init(unsigned int h, unsigned int m, unsigned int s);
		void init(string str);
		void init(int sec);
		void init(Time time);

		void read();
		void display()const;

		int toSec();
		int toMin();

		friend int Total(Time time1, Time time2);
		void Sum(int sec);
		void Dif(int sec);
		friend bool isGreater(Time time1, Time time2);
		friend bool isLower(Time time1, Time time2);
		friend bool Equal(Time time1, Time time2);

	};
private:
	string last_name;
	string phone_number;
	double taruf;
	int discount;
	Time start;
	Time finish;
	double sum;
public:
	string getLast_name() const { return last_name; };
	string getPhone_number() const { return phone_number; };
	double getTaruf() const { return taruf; };
	int getDiscount() const { return discount; };
	Time getStart() const { return start; };
	Time getFinish() const { return finish; };

	void setLast_name(string value) { last_name = value; }
	void setPhone_number(string value) { phone_number = value; }
	void setTaruf(double value) { taruf = value; }
	void setDiscount(int value) { discount = value; }
	void setStart(Time value) { start = value; };
	void setFinish(Time value) { finish = value; };

	string toString();
	void setSum();
	void display();
	bool init(string last_name, string phone_number, double taruf, int discount, Time start, Time finish);
	void read();


};

