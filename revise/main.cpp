//  main.cpp
//  revise
//
//  Created by Vũ hoàng Quân on 21/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

/*
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
*/

//  main.cpp
//  cpp1
//
//  Created by Vũ hoàng Quân on 4/9/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//
#include <map>
#include <iostream>
//#include <fstream>
//#include <string>
//#include "personTypeTest.h"//use for addresspointer_test_1()
//#include "Person.hpp"
#include "date.h"
//#include <cmath>
//#include "Realisations.cpp"
//#include"ioTest.h"

//8 jan 2020
#include "Track.h"
using namespace std;

int main(){
    //test shallow copy of date ptr
    //shallow copy is having both ptr point to a same variable address
    
    /*
    date *ptr1 = new date();//create a date ptr point to default
    int number = 10;//create primitive int type
    cout<<&number<<endl;//show int address
    ptr1->setTime(number, number, number);//obj point to int location
    date *ptr2 = ptr1;//shallow copy? OR? ptr2 = ??
    
    //cout<<ptr2<<endl;//this print the address
    //delete ptr2;
    //delete ptr1;
    //if both ptr is deleted -> revise(1220,0x1000f3dc0) malloc: *** error for object 0x1006900f0: pointer being freed was not allocated
    //because date destructor is empty
    //ptr2 =nullptr;
    //ptr1 =nullptr;
    cout<<ptr1<<endl;
    ptr1->print();
    cout<<ptr2<<endl;//address point to 0x0 - nullptr - if ptr is delete and point to nullptr
    ptr2->print();//this do not work if any ptr is deleted
    
    ///HOW DO U GET ADDRESS OF PTR TO A CLASS FUNC? - OBJECT ORIENTED VIOLATION?
    //cout<<&(ptr2->getYear())<<endl;
    
    //>>>no matter what, shallow copy end up bad, delete any of these ptr and compiler err
     */
    
    //test shallow copy on int ptr
    int *intp = new int;//create a ptr of type int
    int a = 100;//create a int of value 100
    *intp = a;//ptr point to a address with value 100
    int *intp2 = new int;
    
    cout<<&a<<endl;//show int a address
    cout<<intp<<endl;//show intp address
    cout<<intp2<<endl;//show intp address
    
    //*intp2 = a;//2 ptr point to a same location - THIS IS DEEP COPY
    intp2 = intp; //shallow copy (cascade, linked outcome)
    //*intp2 = *intp;//this wont cause shallow cpy
    //intp2 = intp; //is the same as above
    //delete intp;intp =nullptr;
    //cout<<&a<<endl;//show int a address
    //cout<<intp<<endl;//show intp address: 0x0
    //cout<<intp2<<endl;//show intp address
    
    *intp2 = 200;//ptr to change value (or ptr2 same outcome)
   
    cout<<&a<<endl;//show int a address
    cout<<intp<<endl;//show intp address
    cout<<intp2<<endl;//show intp address
    
    cout<<a<<endl;//show int a address
    cout<<*intp<<endl;//show intp address
    cout<<&intp<<endl;//show intp address
    cout<<*intp2<<endl;//
    cout<<&intp2<<endl;//show intp address
    
    //>>cout ptr* ptr &ptr confusion
    //try 2ptr to 1 int that cout ptr1, ptr1 without new int call
    return 0;
    
    //buffer overflow
    
    //mem leak - check as 2 to 
}

