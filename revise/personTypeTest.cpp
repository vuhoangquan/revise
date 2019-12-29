//  personTypeTest.cpp
//  cpp1
//
//  Created by Vũ hoàng Quân on 4/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#include <stdio.h>
#include <iostream>
#include <string>
#include "personTypeTest.h"
using namespace std;

personTypeTest::personTypeTest(string first, string last)
{
    firstname = first;
    lastname = last;
}

personTypeTest::personTypeTest() {
    
}

personTypeTest& personTypeTest::setFirstname(string first)
{
    firstname = first;
    return *this;
}

string personTypeTest::getFirstname() const
{
    return firstname;
}

