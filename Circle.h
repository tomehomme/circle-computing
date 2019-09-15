#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include <string>
#include <iostream>
using namespace std;

struct person{
	string name;
	person* next;
	person(): name(""), next(0) {}
	person(string a): name(a), next(0) {}
	string GetPersonName() const {return name;}
};

class circle{
	private:
		person* head;
		person* tail; //tail->next should always be head for circle
		int numPeople;
		void changeHead(const string& );
		void addThruFile(string pName);
	public:
		circle();
		void removePerson(string);
		void changePosition();
		void addPerson();
		int numPeopleLeft() const;
		string survivor (string, int);
		void printCircle() const;
		void addPerson(string);
};

#endif