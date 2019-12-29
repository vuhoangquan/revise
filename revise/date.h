//
//  date.h
//  cpp1
//
//  Created by Vũ hoàng Quân on 4/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//
#pragma once
#ifndef H_date //if not define
#define H_date
#include <iostream>
#include <string>
using namespace std;

class date {
    friend ostream& operator << (ostream&, const date&);
    friend istream& operator >> (istream&, date&);//friend to print out private variable without get method (accessor)
public:
    date();
    date(int dd, int mm, int yyyy);
    virtual ~date(); //destructor
    //setters
    void setDate(int dd);
    void setMonth(int mm);
    void setYear(int yyyy);
    void setTime(int fn, int mn, int ln);
    //getter
    int getDate() const;
    int getMonth() const;
    int getYear() const;
    //printf
    void print() const;
private:
    int Date;//data members
    int Month;
    int Year;
};
#endif // H_date /* date_h */
