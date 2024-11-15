/******************************************************

COMSC 210 | Lab 32 | Skylar Robinson | IDE Used: Eclipse

*******************************************************/

#include <iostream>
#include <deque>
#include <ctime>
#include <array>
#include "Car.h"
using namespace std;

const int PY_PR = 46, JN_PR = 39, JNEM_PR = 50, ICARS = 2, LANES = 4, TIMES = 20;

void carJoin(deque<Car>&);
void carPay(deque<Car>&);
void carSwitch(array<deque<Car>, LANES>&, int);
void dispQueue(deque<Car>);
void dispPlaza(array<deque<Car>, LANES>);
int prob();
int laneNot(int);

int main(){
	srand(time(0));
	array<deque<Car>, LANES> plaza;

	//add initial cars
	for (int c = 0; c < LANES; c++) {
		for (int i = 0; i < ICARS; i++) {
			Car temp;
			plaza[c].push_back(temp);
		}
	}

	//display initial queue
	cout << "Initial queue:\n";
	for (int i = 0; i < LANES; i++) {
		cout << "Lane " << i + 1 << ":\n";
		for (Car c : plaza[i]) {
			cout << "\t";
			c.print();
		}
	}
	cout << endl;

	//simulation
	for (int c = 0; c < TIMES; c++) {
		cout << "Time: " << c + 1 << endl;
		for (int i = 0; i < LANES && !plaza[i].empty(); i++) {
			cout << "Lane: " << i + 1 << " ";
			int pr = prob();
			if (pr <= PY_PR)
				carPay(plaza[i]);
			else if (pr <= PY_PR + JN_PR)
				carJoin(plaza[i]);
			else
				carSwitch(plaza, i);
		}
		dispPlaza(plaza);
		cout << endl;
	}

	return 0;
}

void carJoin(deque<Car> &q) {
	cout << "Operation: Joined: ";
	Car temp;
	temp.print();
	q.push_back(temp);

}

void carPay(deque<Car> &q) {
	cout << "Operation: Paid: ";
	q.front().print();
	q.pop_front();
}

void carSwitch(array<deque<Car>, LANES> &a, int i) {
	cout << "Operation: Switched: ";
	a[i].back().print();
	a[laneNot(i)].push_back(a[i].back());
	a[i].pop_back();
}

void dispQueue(deque<Car> q) {
	if (q.empty())
		cout << " empty\n";
	else {
		cout << endl;
	    for (Car c : q) {
		    cout << "\t";
		    c.print();
	    }
	}
}

void dispPlaza(array<deque<Car>, LANES> a) {
	for (int i = 0; i < LANES; i++) {
		cout << "Lane " << i + 1 << " Queue:";
		dispQueue(a[i]);
	}
}

int prob() {
	return (rand() % 100) + 1;
}

int laneNot(int l) {
	int temp = (rand() % LANES);
	while (temp == l)
		temp = (rand() % LANES);
	return temp;
}
