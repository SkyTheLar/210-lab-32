/******************************************************

COMSC 210 | Lab 32 | Skylar Robinson | IDE Used: Eclipse

*******************************************************/

#include <iostream>
#include <deque>
#include <ctime>
#include "Car.h"
using namespace std;

void carJoin(deque<Car>&);
void carPay(deque<Car>&);
void dispQueue(deque<Car>);
int prob();

const int PY_PR = 55, ICARS = 2;

int main(){
	srand(time(0));
	deque<Car> line;

	//add initial cars
	for (int i = 0; i < ICARS; i++) {
		Car temp;
		line.push_back(temp);
	}

	//display initial queue
	cout << "Initial queue:\n";
	for (Car c : line) {
		cout << "\t";
		c.print();
	}
	cout << endl;

	int count = 1;
	while (!line.empty()) {
		cout << "Time: " << count << " ";
		if (prob() <= PY_PR)
			carPay(line);
		else
			carJoin(line);
		dispQueue(line);
		cout << endl;
		count++;
	}

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

void dispQueue(deque<Car> q) {
	cout << "Queue:\n";
	if (q.empty())
		cout << "\tEmpty";
	else
	    for (Car c : q) {
		    cout << "\t";
		    c.print();
	    }
}

int prob() {
	return (rand() % 100) + 1;
}
