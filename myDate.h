#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
#include <string>
using namespace std;

class myDate{
  private:
    int month;
    int day;
    int year;
  public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void increaseDate(int N);
    void decreaseDate(int N);
    int getMonth();
    string getMonthName();
    int getDay();
    int getYear();
    int daysBetween(myDate D);
    int dayOfYear();
    string dayName();
    bool isLeap();
    string toString();
    int Greg2Julian(int month, int day, int year);
    void Julian2Greg(int JD, int& month, int& day, int& year);
};
#endif