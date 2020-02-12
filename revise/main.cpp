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
    date *ptr1 = new date();
    date *ptr2 = ptr1;
    
    //ptr2=nullptr;
    delete ptr2;
    cout<<ptr1<<endl;
    ptr1->print();
    cout<<ptr2<<endl;
    ptr2->print();//this wont work
    return 0;
    //remove this and replace with pointer class
    // point 2 ptr to the same primitive data
    // check if the compiler accept
}

