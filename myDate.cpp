#include "myDate.h"

int myDate::Greg2Julian(int month, int day, int year) {
  int K = day;
  int J = month;
  int I = year;
  return K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
} 

void myDate::Julian2Greg(int JD, int& month, int& day, int& year){
   int L = JD + 68569;
   int N = 4 * L / 146097;
   L = L - (146097 * N + 3) / 4;
   int I = 4000 * (L + 1) / 1461001;
   L = L - 1461 * I / 4 + 31;
   int J = 80 * L / 2447;
   int K = L - 2447 * J / 80;
   L = J / 11;
   J = J + 2 - 12 * L;
   I = 100 * (N - 49) + I + L;
   year = I;
   month = J;
   day = K;
}


myDate::myDate(){
  month = 5;
  day = 11;
  year = 1959;
}

myDate::myDate(int M, int D, int Y){
  int JD = Greg2Julian(M, D, Y);
  
  //if(Julian2Greg(JD, &M, &D, &Y) == myDate(M,D,Y)){
  if((month < 12 || month > 1) && (day < 31 || day > 1)){
    month = M;
    day = D;
    year = Y;
  }else{
    month = 5;
    day = 11;
    year = 1959;
  }

  //this was added to block main from generating February 30th/31st
  if(M == 2 && D > 28){
    if(isLeap()){
      month = M;
      day = 29;
      year = Y;
    }else{
      month = M;
      day = 28;
      year = Y;
    }
  }

}

void myDate::display(){
  cout << getMonthName() <<  " " << day << ", " << year;
}

void myDate::increaseDate(int N){
  int JD = Greg2Julian(month, day, year);
  JD += N;
  Julian2Greg(JD, month, day, year);
}

void myDate::decreaseDate(int N){
  int JD = Greg2Julian(month, day, year);
  JD -= N;
  Julian2Greg(JD, month, day, year);  
}

int myDate::getMonth(){
  return month;
}

string myDate::getMonthName(){
  switch(month){
    case(1):
      return "January";
      break;
    case(2):
      return "February";      
      break;
    case(3):
      return "March";
      break;
    case(4):
      return "April";
      break;
    case(5):
      return "May";
      break;
    case(6):
      return "June";
      break;
    case(7):
      return "July";
      break;
    case(8):
      return "August";
      break;
    case(9):
      return "September";
      break;
    case(10):
      return "October";
      break;
    case(11):
      return "November";
      break;
    case(12):
      return "December";
      break;
  }
  return "";
}

int myDate::getDay(){
  return day;
}

int myDate::getYear(){
  return year;
}

int myDate::daysBetween(myDate D){
  int d1 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
  int d2 = Greg2Julian(month, day, year); 
  return abs(d1 - d2);
}

int myDate::dayOfYear(){
  myDate D(1, 1, year);

  return (daysBetween(D)) + 1;  
}

string myDate::dayName(){
  int JD = Greg2Julian(month, day, year);
  switch(JD%7){
    case(0):
      return "Monday";
    break;
    case(1):
      return "Tuesday";
    break;
    case(2):
      return "Wednesday";
    break;
    case(3):
      return "Thursday";
    break;
    case(4):
      return "Friday";
    break;
    case(5):
      return "Saturday";
    break;
    case(6):
      return "Sunday";
    break;
  }
  return "";
}

bool myDate::isLeap(){
  if(year % 400 == 0){
    return true;
  }else if(year % 100 == 0){
    return false;
  }else if(year % 4 == 0){
    return true;
  }else{
    return false;
  }
}

string myDate::toString(){
  string date = getMonthName() + " " + to_string(getDay()) + ", " + to_string(getYear());
  return date;  
}
