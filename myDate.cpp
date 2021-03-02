//Caitlin Martinez
//CECS 282-03
//Project 2 - myDate
//02/22/2020





#include "myDate.h"
#include <iostream>
#include <string>

using namespace std;

int Greg2Julian(int month, int day, int year); 
void Julian2Greg(int JD, int & month, int & day, int & year); 


void Julian2Greg(int JD, int &month, int &day, int &year) 
{

    int I, J, K, L, N;

    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N-49) + I + L;
    
    year = I;
    month = J;
    day = K;
}



int Greg2Julian(int month, int day, int year) 
{
    int y = year; 
    int m = month; 
    int d = day; 
    
    int jd = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    
    return jd;
}


myDate::myDate() 
{
    month = 5;
    day = 11;
    year = 1959;
}


myDate::myDate(int M, int D, int Y)
{
    int month1, day1, year1, julianDate;
    
    month1 = M;
    day1 = D;
    year1 = Y;
    julianDate = Greg2Julian(M, D, Y);
    Julian2Greg(julianDate, M, D, Y);

    if (M == month1 && D == day1 && Y == year1)
    {
        month = M;
        day = D;
        year = Y;
    }

    else
    {
        month = 5;
        day = 11;
        year = 1959;
    }
}


void myDate::display() 
{
    string months[12] = {"January", "February", "March",
    "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string sMonth;

    sMonth = months[month - 1];
    cout << " " << sMonth << " " << day << ", " << year << " ";
}


void myDate::increaseDate(int N) 
{
    int increase;

    increase = Greg2Julian(month, day, year);
    increase = increase + N;
    Julian2Greg(increase, month, day, year);
}



void myDate::decreaseDate(int N)
{
    int decrease;

    decrease = Greg2Julian(month, day, year);
    decrease = decrease - N;
    Julian2Greg(decrease, month, day, year);
}


int myDate::daysBetween(myDate D)
{
    int julian1, julian2;

    julian1 = Greg2Julian (D.getMonth(),D.getDay(), D.getYear());
    julian2 = Greg2Julian(month, day, year);
    
    return julian1 - julian2;
}


int myDate::getMonth() 
{
    return month;
}


int myDate::getDay() 
{
    return day;
}

int myDate::getYear() 
{
    return year;
}


int myDate::dayOfYear(){

    int dayOfTheYear = Greg2Julian(month, day, year) - Greg2Julian(1, 1, year) + 1;

    return dayOfTheYear;

}


string myDate::dayName() 
{

  string DaysInAWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  int jd = Greg2Julian(month, day, year);
  int day = jd % 7;
   
    
  return DaysInAWeek[day];
}
