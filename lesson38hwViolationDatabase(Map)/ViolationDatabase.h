#pragma once
#include "Violation.h"
#include <vector>
#include <map>

class ViolationDatabase
{
protected:
	map<string, vector<Violation>> database; //carNumber + violations
public:
	ViolationDatabase() {};

	void addViolation(string number, Violation violation) {
		database[number].push_back(violation);
	}

	void findCarViolations(string number) {
		for (auto node : database) {
			if (node.first == number) {
				cout << "==============================" << endl;
				cout << "Car number: " << node.first << endl;
				cout << "------------------------------" << endl;
				for (auto i : node.second) {
					i.show();
				}
				cout << "==============================" << endl;
				return;
			}
		}
		cout << "No such car" << endl;
	}

	float findTotalPaymentOfCar(string number) {
		float total = 0;
		for (auto node : database) {
			if (node.first == number) {
				for (auto i : node.second) {
					total += i.getPayment();
				}
				return total;
			}
		}
		cout << "No such car" << endl;
		return -1;
	}

	float payViolation(string number, float& money) {
		for (auto& node : database) {
			if (node.first == number) {
				for (auto i = node.second.begin(); i != node.second.end(); i++) {
					if (money - i->getPayment() >= 0) {
						money -= i->getPayment();
						i->setPayment(0);
					}
					else {
						i->setPayment(i->getPayment()-money);
						money = 0;
					}

					/*if (i->getPayment() == 0) {
						node.second.erase(i);
					}*/
				}

				return money;
			}
			
		}
	}

	void show()const {
		for (auto node : database) {
			cout << "==============================" << endl;
			cout << "Car number: " << node.first << endl;
			cout << "------------------------------" << endl;
			for (auto i : node.second) {
				i.show();
			}
			cout << "==============================" << endl;
		}
	}
};

