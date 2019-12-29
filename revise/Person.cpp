//  Person.cpp
//  cpp1
//
//  Created by Vũ hoàng Quân on 4/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

#include "Person.hpp"
#include <iostream>
//#include "stdafx.h"
//#include "Person.hpp"

using namespace std;

Person::Person() {
    
}
Person::Person(string fname, string lname) {
    firstname = fname;
    lastname = lname;
}
Person::Person(string fname, string lname, int age) {
    firstname = fname;
    lastname = lname;
    age = age;
}
Person::~Person() {
    
}
void Person::setAge(int age)
{
    this->age = age;
}
int Person::getAge() const
{
    cout << "age " << age << endl;
    return age;
}
void Person::sayhello() {
    cout << "hello test" << endl;
}

