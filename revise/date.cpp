//  date.cpp
//  cpp1
//
//  Created by Vũ hoàng Quân on 5/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//implemenetation
#include <iostream>
#include <string>
#include "date.h"
using namespace std;
date::date() // hearer file name ::header file location
{
    Date = 13; Month = 10; Year = 1999;
    cout<<"date constructor called"<<endl;
}
date::~date() {
    //Date=-1;Month=-1;Year=-1;
}
date::date(int dd, int mm, int yyyy) {
    cout<<"constructor that set date called"<<endl;
    Date = dd; Month = mm; Year = yyyy;
}
//setter
void date::setDate(int dd) {
    Date = dd;
}
void date::setMonth(int mm) {
    Month = mm;
}
void date::setYear(int yyyy) {
    Year = yyyy;
}
void date::setTime(int dd, int mm, int yyyy) {
    Date = dd; Month = mm; Year = yyyy;
}
//getter
int date::getDate() const {
    return Date;
}
int date::getMonth() const {
    return Month;
}
int date::getYear() const {
    return Year;
}
//printf
void date::print() const {
    cout << "date " << Date << "month " << Month << "year " << Year << endl;
}
ostream& operator <<(ostream& osObject, const date& date1)
{
    osObject << date1.Date << " " << date1.Month << " " << date1.Year;
    return osObject;
}
istream& operator >>(istream& isObject, date& date1)
{
    isObject >> date1.Date >> date1.Month >> date1.Year;
    return isObject;
}
