//
//  personTypeTest.h
//  revise
//
//  Created by Vũ hoàng Quân on 21/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

#ifndef personTypeTest_h

#define personTypeTest_h

//  personTypeTest.h
//  cpp1
//
//  Created by Vũ hoàng Quân on 4/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//
//#ifndef H_personTypeTest
//#define H_personTypeTest
#include<iostream>
#include <string>
using namespace std;
class personTypeTest {
public:
    personTypeTest(string first = "", string last = "");
    personTypeTest();
    //contructor
    personTypeTest& setFirstname(string first);//this will return address that store firstname (object? as in book?)
    
    string getFirstname() const;
private:
    string firstname;
    string lastname;
};
#endif // !H_personTypeTest /* personTypeTest_h */


