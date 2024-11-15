/******************************************************

COMSC 210 | Lab 32 | Skylar Robinson | IDE Used: Eclipse

*******************************************************/

#include <iostream>
#include <deque>
#include <ctime>
#include "Car.h"
using namespace std;

void carJoin(deque<Car>);
void carPay(deque<Car>);
void dispQueue(deque<Car>);

const int PY_PR = 55, JN_PR = 45, ICARS = 2;

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
	for (Car c : line)
		c.print();

	return 0;
}
