#include "Circle.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

circle::circle(){
	head = nullptr;
	tail = nullptr;
	numPeople = 0;
}

void circle::addPerson(){
	cout << "Adding a Person to the Circle" << endl;
	cout << "Enter name of person you are adding: " << endl;
	string pName;
	getline(cin,pName);
	cout << endl;
	numPeople++;
	if (head == nullptr){
		head = new person(pName);
		tail = head;
		return;
	}
	if (head->next==nullptr){
		head->next = new person(pName);
		tail = head->next;
		tail->next = head;
		return;
	}
	tail->next = new person(pName);
	tail = tail->next;
	tail->next = head;
}

void circle::addThruFile(string pName){
	numPeople++;
	if (head == nullptr){
		head = new person(pName);
		tail = head;
		return;
	}
	if (head->next==nullptr){
		head->next = new person(pName);
		tail = head->next;
		tail->next = head;
		return;
	}
	tail->next = new person(pName);
	tail = tail->next;
	tail->next = head;
}


void circle::addPerson(string streamname){
    ifstream inputs;
    inputs.open(streamname);
    if (!inputs.is_open()){
        cout << "failed to open file with names." <<endl;
        return;
    }
    cout << "Enter the number of people in the initial circle: " << endl;
    int initPeople;
    cin >> initPeople;
    cin.ignore();
    cout << endl;
	string pName;
    for (int i=0; i<initPeople;i++){
	getline(inputs,pName);
	addThruFile(pName);
}
}


int circle::numPeopleLeft() const{
  return numPeople;
}

void circle::printCircle() const {
    cout << "People in circle: " << endl;
    person* temp = head;
    if (numPeople==1){
        cout << head->name << endl;
        return;
    }
    if (head){
        for(int i = 0; i<numPeople; i++){
            cout << temp->name << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

void circle::removePerson(string names){
    if (numPeople==0){
        cout << "No people in list." << endl;
        return;
    }
  numPeople--;
  if (names==head->name) { //remove head node
//    
      if (numPeople == 1) {
        //   cout << head->name << " is dead. " << endl;
          delete head;
          head = nullptr;
          tail = nullptr;
          return;
      }
       if (numPeople==2){
            // cout << head->name << " is dead. " << endl;
            delete head;
            head = tail;
            head->next = nullptr;
            return;
        }
//      
          person* temp = head->next;
        //   cout << head->name << " is dead. " << endl;
          delete head;
          tail->next = temp;
          head = temp;
          return;
      }
//      

  if (names == tail->name){ //remove last node
      if (numPeople == 1){
          delete head;
          tail == nullptr;
          head == nullptr;
      }
        if (numPeople==2){
            //  cout << tail->name << " is dead. " << endl;
            delete tail;
            tail = head;
            head->next = nullptr;
            return;
        }
      person* temp = head->next;
      person* prev = head;
      while (temp != tail){
          prev = temp;
          temp = temp->next;
      }
      tail = prev;
      prev->next = head;
    //   cout << temp->name << " is dead." << endl;
      delete temp;
      return;
  }
  else { 
      person *temp = head->next;
      person *prev = head;
      while (temp->name != names) {
          prev = temp;
          temp = temp->next;
      }
      prev->next = temp->next;
    //   cout << temp->name << " is dead." << endl;
      delete temp;
      return;
  }
}
void circle::changeHead(const string& newHead){
    if (newHead == head->name){
        return;
    }
    if (newHead == tail->name){
        person* oldHead = head;
        person* temp = head->next;
        person* prev = head;
        while (temp!= tail){
            prev = temp;
            temp = temp->next;
        }
        head = temp;
        tail = prev;
        head->next = oldHead;
        tail->next = head;
    }
    tail->next = head;
    person* beforeChange = tail;
    person* curr = head->next;
    person* prev = head;
    while (curr->name != newHead){
        prev = curr;
        curr = curr->next;
    }
    tail = prev;
    tail->next = curr;
    while (beforeChange!=prev){
        beforeChange = beforeChange->next;
    }
    beforeChange->next = prev->next;

    head = curr;
}
string circle::survivor(string start, int skip){
    changeHead(start);
    cout << head->name << endl;
    printCircle();
    person* curr = head->next;
    person* prev = head;
    // cout << "starting execution" << endl;
    while (numPeople > 2){
        for (int i = 1; i<skip; i++){
            prev = curr;
            curr = prev->next;
        }
        removePerson(prev->name);
        // cout << "the number of people left: " << numPeople << endl;
        prev = curr;
        curr = prev->next;
        // printCircle();
        // cout << endl;
    }
    if (skip%2 == 0){ //if even, so don't need to go through the skips
        return prev->name;
    }
    return prev->next->name;
}

