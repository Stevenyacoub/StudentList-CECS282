#include "myDate.h"
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student{
  char name[7];
  int StudentID;
  char grade;
  myDate birthday;
  string hometown;
};

myDate randomBirthday(){
  int year = rand() % 11 + 1995;
  int month = rand() % 12 + 1;
  int day = rand() % 31 + 1;

  return myDate(month, day, year);
}

void populate(Student** sptr){

  string names[10] = {"Red", "Ethan", "Brendan", "Lucas", "Hilbert", "Green", "Lyra", "May", "Dawn", "Hilda"};
  int IDs[10];
  char grades[5] = {'A', 'B', 'C', 'D', 'F'};
  string hometowns[10] = {"Littleroot", "Twinleaf", "Pallet", "New Bark", "Aspertia City", "Nuvema", "Postwick", "Hau'oli Outskirts", "Vaniville", "Petalburg"};
  
	for (int i = 0; i < 10; i++) {
		int x = rand() * 10;
		while (x < 99999) {
			x = rand() * 10;
		}
		IDs[i] = x;
	}

	for (int i = 0; i < 10; i++) {
		sptr[i] = new Student;
		strcpy(sptr[i]->name, names[rand() % 10].c_str());
		sptr[i]->grade = grades[rand() % 5];
		sptr[i]->birthday.increaseDate(rand() % (17036 - 14480) + 14480);
		sptr[i]->StudentID = IDs[i];
		sptr[i]->hometown = hometowns[rand() % 10];
  }

}

void display(Student** sptr){  
    cout << setw(13) << left << "Name"
    << setw(20) << left << "Student ID"
    << setw(10) << left << "Grade"
    << setw(20) << left << "Birthday"
    << setw(20) << left << "Hometown"
    << endl;

    cout << setw(13) << left << "----"
    << setw(20) << left << "----------"
    << setw(10) << left << "-----"
    << setw(20) << left << "--------"
    << setw(20) << left << "--------"
    << endl;

    for (int i=0; i<10; i++){
      cout << setw(13) << left << sptr[i]->name
      << setw(20) << left << sptr[i]->StudentID
      << setw(10) << left << sptr[i]->grade
      << setw(20) << left << sptr[i]->birthday.toString()
      << setw(20) << left << sptr[i]->hometown
      << endl;
    }
    cout << endl;
    cout << endl;

}

void swap(Student** s1, Student** s2){
  Student* temp;
  temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}

void sortByName(Student * sptr[]){
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 9; i++) {
			if ((strcmp(sptr[i]->name, sptr[i + 1]->name)) > 0) {
        swap(sptr[i], sptr[i+1]);
				sorted = false;
			}

		}
	}
}

void sortByID(Student * sptr[]){
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 9; i++) {
			if (sptr[i]->StudentID > sptr[i + 1]->StudentID) {
        swap(sptr[i], sptr[i+1]);
				sorted = false;
			}
		}
	}
}

void sortByGrade(Student * sptr[]){
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 9; i++) {
			if (sptr[i]->grade > sptr[i + 1]->grade) {
				swap(sptr[i], sptr[i+1]);
				sorted = false;
			}
		}
	}
}

void sortByBirthday(Student * sptr[]){
	myDate compare(0,0,0);
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 9; i++) {
			if (sptr[i]->birthday.daysBetween(compare) < sptr[i + 1]->birthday.daysBetween(compare)) {
				swap(sptr[i], sptr[i+1]);
				sorted = false;
			}
		}
	}
}

void sortByHometown(Student * sptr[]){
  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i < 9; i++){
      if(sptr[i]->hometown > sptr[i+1]->hometown){
        swap(sptr[i], sptr[i+1]);
        sorted = false;
      }
    }
  }
}

int main() {
  srand(time(NULL));
  
  Student * sptrArray[10];
  Student ** sptr = sptrArray;
  populate(sptr);

  display(sptr);

  cout << "1.) Display list sorted by Name\n";
  cout << "2.) Display list sorted by Student ID\n";
  cout << "3.) Display list sorted by Grade\n";
  cout << "4.) Display list sorted by Birthday\n";
  cout << "5.) Display list sorted by Home Town\n";
  cout << "6.) Exit.\n";

  int menuChoice;
  

  while(menuChoice != 6){
    cin >> menuChoice;
    switch(menuChoice){
      case(1):{
        //cout << "Call to 1 worked!";
        sortByName(sptr);
        display(sptr);
        break;
      }
      case(2):{
        //cout << "Call to 2 worked!";
        sortByID(sptr);
        display(sptr);
        break;
      }
      case(3):{
        //cout << "Call to 3 worked!";
        sortByGrade(sptr);
        display(sptr);
        break;
      }
      case(4):{
        //cout << "Call to 4 worked!";
        sortByBirthday(sptr);
        display(sptr);
        break;
      }
      case(5):{
        //cout << "Call to 5 worked!";
        sortByHometown(sptr);
        display(sptr);
        break;
      }
      case(6):{
        //cout << "Call to 6 worked!";
        cout << "Bye bye!";
        break;
      }
    }
  }
}