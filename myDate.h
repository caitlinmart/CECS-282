//Caitlin Martinez
//CECS 282-03
//Project 2 - myDate
//02/22/2020

#ifndef myDate_h
#define myDate_h

#include <stdio.h>
#include <string>
using namespace std;

class myDate
{
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
    int daysBetween(myDate D); 
    int getMonth();
    int getDay(); 
    int getYear();
    int dayOfYear();
    string dayName(); 
  

};
#endif