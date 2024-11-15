/******************************************************

COMSC 210 | Lab 32 | Skylar Robinson | IDE Used: Eclipse

*******************************************************/

#include <iostream>
#include <deque>
#include <ctime>
#include <array>
#include "Car.h"
using namespace std;

const int PY_PR = 55, ICARS = 2, LANES = 4;

void carJoin(deque<Car>&);
void carPay(deque<Car>&);
void carSwitch(array<deque<Car>, LANES>&, int);
void dispQueue(deque<Car>);
int prob();


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

	return 0;
}

void carJoin(deque<Car> &q) {
	cout << "Operation: Joined lane: ";
	Car temp;
	temp.print();
	q.push_back(temp);

}

void carPay(deque<Car> &q) {
	cout << "Operation: Car paid: ";
	q.front().print();
	q.pop_front();
}

void carSwitch(array<deque<Car>, LANES> &a, int i) {

}

void dispQueue(deque<Car> q) {
	cout << "Queue:";
	if (q.empty())
		cout << " empty";
	else {
		cout << endl;
	    for (Car c : q) {
		    cout << "\t";
		    c.print();
	    }
	}
}

int prob() {
	return (rand() % 100) + 1;
}