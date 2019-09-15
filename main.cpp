#include "Circle.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
	cout << "Josephus Problem" << endl;
	cout << "Enter names from file? yes/no" << endl;
	string fileans;
	cin>> fileans;
	cin.ignore();
	circle Josephus;
	if (fileans=="yes"){
		Josephus.addPerson("peeps.txt");
		cout << "The number of people in the circle is: " << Josephus.numPeopleLeft() << endl;
		Josephus.printCircle();
		cout << "Who would you like to start with?" << endl;
		string name;
		getline(cin, name);
		cout << "Number skipped?" << endl;
		int skip = 0;
		cin >> skip;
		cin.ignore();

	string surv = Josephus.survivor(name, skip);
	cout << "The Survivor of the Josephus circle: " << surv << endl;
		return 0;
	}

	cout << "Enter the number of people in the initial circle: " << endl;
	int initPeople;
	cin >> initPeople;
    cin.ignore();
	cout << endl;
	for (int i=0; i<initPeople;i++){
		Josephus.addPerson();
	}
	cout << "The number of people in the circle is: " << Josephus.numPeopleLeft() << endl;
	Josephus.printCircle();
    cout << "Who would you like to start with?" << endl;
    string name;
    getline(cin, name);
    cout << "Number skipped?" << endl;
    int skip = 0;
    cin >> skip;
    cin.ignore();
	cout << endl;

	string surv = Josephus.survivor(name, skip);
	cout << "The Survivor of the Josephus circle: " << surv << endl;
	return 0;
}