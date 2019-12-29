//  Person.hpp
//  cpp1
//
//  Created by Vũ hoàng Quân on 4/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

#pragma once
#include <string>
using namespace std;
class Person {
private:
    string firstname;
    string lastname;
    int age;
public:
    Person();
    Person(string fname, string lname);
    Person(string fname, string lname, int age);
    ~Person();
    void setAge(int age);
    int getAge()const;//return age and print age
    void sayhello();
    
}; /* Person_hpp */

