#pragma once
#include <iostream>
#include <string>
#include "Date.h";
#include "Time_.h"
using namespace std;

class Violation
{
protected:
	string info;
	Date date;
	Time_ time;
	float payment;
public:
	Violation(string info, Date date, Time_ time, float payment) {
		this->info = info;
		this->date = date;
		this->time = time;
		this->payment = payment;
	}
	~Violation() {};

	void setPayment(float payment) { this->payment = payment; }

	string getInfo()const { return info; }
	float getPayment()const { return payment; }

	void show()const {
		cout << "Violation info:" << endl;
		cout << info << endl;
		cout << "Date: " << date << endl;
		cout << "Time: " << time << endl;
		cout << "Payment: " << payment << "usd" << endl;
		cout << endl;
	}
};

