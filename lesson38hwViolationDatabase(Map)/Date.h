#pragma once 
#include<iostream>
#include<ctime>
using namespace std;

class Date {
    int year;
    int month;
    int day;

    bool isLeapYear();
    int monthDays(); 
    void nextDate();  
    void prevDate();  



public:

    

    Date(); 

    Date(int year, int month, int day);  

    Date(const Date& obj); 

    ~Date();

    void showDate();


   

    void setYear(int year);

    int getYear() const&;

    void setMonth(int month);

    int getMonth() const&;

    void setDay(int day);

    int getDay() const&;



    bool valid();  



   

    bool operator == (const Date& obj) const&;

    bool operator != (const Date& obj) const&;

    bool operator > (const Date& obj) const&;

    bool operator < (const Date& obj) const&;

    bool operator >= (const Date& obj) const&;

    bool operator <= (const Date& obj) const&;


    Date& operator = (const Date& obj);

    Date& operator += (int n);

    Date& operator -= (int n);


    Date operator + (int n);

    Date operator - (int n);

    Date& operator -- ();
    Date operator --(int n);
    Date& operator ++ ();
    Date operator ++(int n);

    friend ostream& operator << (ostream& os, const Date& t);
    friend istream& operator >> (istream& is, Date& t);


};




