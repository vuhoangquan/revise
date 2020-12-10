//  main.cpp
//  revise
//
//  Created by Vũ hoàng Quân on 21/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "personTypeTest.h"//use for addresspointer_test_1()
#include "Person.hpp"
#include "date.h"

#include "bst.h"
//#include"ioTest.h"
using namespace std;

int main_ftream_read_file() {
    string filename;
    ifstream input;
    string line1;
    string word1, word2;
    
    cout << "enter file name" << endl;
    cin >> filename;//entered file name must have file type (.csv work but not txt,h,)
    input.open(filename);//open file
    while (!input.eof()) {
        getline(input, word1, ',');//read until space .csv HAS end of line "\n"
        getline(input, word2, ',');
        getline(input, line1);
        cout << word1 << "!!!"<<word2<<"!!!"<<line1 ;//print:output until ','and until ',' and    NOTE: until 1 length of a line which is until the next ',' not end of line
    }
    return 0;
}

int stoi_test() {
    string input = "182759";
    int output = stoi(input);//conver string to int
    output = 10000 - output;//calculation
    cout << output;//output
    return 0;
}

int addresspointer_test_1() {// small temp - can delete
    personTypeTest obj1("firstnaem","lasttname");
    obj1.setFirstname("nope");
    return 0;
}

int pointer_arrow_ref_test() {
    //this will show: ref to a object
    //compare obj func call and pointer, ref call
    
    Person* pointerOne = new Person();//create person instance with default constructor
    //"new" in "new Person"can be used for computer to dynamically allocate memory for that class object
    Person p;
    Person& pRef = p;//ref take address of p
    //these 3 below show the same result - call func
    p.sayhello();// other in comment or not metioned are wrong way to call
    pointerOne->sayhello();//pointer type then only this work
    //below are all inappropriate / wrong
    //&pointerOne->sayhello();  //*pRef.sayhello();
    //*pointerOne->sayhello();  //&pRef.sayhello();
    //*pointerOne.sayhello();  //pRef->sayhello();
    //pointerOne.sayhello();  //*pRef->sayhello();
    //&pointerOne.sayhello();  //&pRef->sayhello();
    pRef.sayhello();
    //show value of instance
    p.setAge(0);
    p.getAge();
    pRef.getAge();
    pointerOne->setAge(1);
    pointerOne->getAge();
    *pointerOne = p;//poiner point to p
    pointerOne->getAge();
    return 0;
}

int istream_ignore_test() {
    cout << "enter 3 word with space: " << endl;
    char first, last;
    first = cin.get();
    cin.ignore(256, 'z');//discard from input seq until ' ' (including what in ' ')
    last = cin.get();
    cout << "first " << first << " last " << last << endl;
    return 0;
}

int overloadOperatorTest(){
    //overload function is outside main - usually in implementation or in below main
    // friend operator in header only
    date objtestett;
    date objdate(19,9,1999);
    objdate.setTime(345,1,34547);//change date in objdate
    cout<<objdate<<endl;//cout object invoke operator overload
    return 0;
}

void pointer_alternative_to_return() {//this will use pointer instead of return
    int a, b;
    a = 5 + 5; int& ref1 = a;
    //delete &ref2;
    b = 10 + 10; int& ref2 = b;
    cout << "address of a " << &a << " address of b " << &b << endl;
    cout <<"address of ref1 "<< &ref1 << endl;
    cout <<"address of ref2 "<< &ref2 << endl;
    cout << ref1 << endl;
    cout << ref2 << endl;
    //c++ dont sp return array, must use pointer to an array
}

//this is how pointer can be used alternative to return
int& pass_address(int &numberParam1) {
    int i = 158;
    numberParam1 = numberParam1+ i;//change value inside parameteer
    return numberParam1;
}
int pass_pointer(int* pointerParam1) {
    *pointerParam1 = *pointerParam1 + 100;//this will change value of pointer
    //pointerParam1 = pointerParam1 + 100;//this will point the pointer to new location -> default value =0
    return *pointerParam1;
}

void floating_point_representation() {
    short short1 = 66;
    char char1 = short1;//convert from number to char as char is actually number but indicate as char
    cout << char1 << endl;//ex: 65=A; 66=B... all symbol in ASCII
    
    short short2 = pow(2,15);// short range: -32768 to 32767 or -2^15 to 2^15-1
    cout << short2 << endl;// 2bytes: 1111 1111 1111 1111 = -32768
    int int1 = short2;// short is negative so computer will fill: 11111... makes int negative
    cout << int1 << endl;
    
    short short3 = pow(2, 16) + 1;//2^16 is out of range for short
    int1 = short3;//only the 1 is pass over to int
    cout << int1 << endl;//=1
    
    float float1 = 7.5;//4 bytes - 7 can be represent as 3.5 * 2^1
    int1 = float1;
    cout << int1 << endl;
    
    //this print float representation in int(decimal) - convert to binary to understand (numbase.exe)
    int faddress = *(int*)& float1;//value of pointer pointing to this address memory
    //ref link https://stackoverflow.com/questions/397692/how-do-i-display-the-binary-representation-of-a-float-or-double
    printf(" %d; 7.5=1000000 11110000 00000000 00000000", faddress);
}//111=7; 1=0.5

void open_multiple_file() {
    ifstream input;
    string filedata[10] = { "","","","","","","","","","" };
    
    input.open("data/textfile1.txt");//open 1 file
    int n = 0;
    while (!input.eof()) {
        getline(input, filedata[0], '\n');
        getline(input, filedata[1], '\n');
        
    }
    for (int i = 0; i < 10; i++) {//output test
        cout << filedata[i] << endl;;
    }
    input.close();
    
    input.open("data/textfile2.txt");
    while (!input.eof()) {
        getline(input, filedata[n], '\n');
        n++;
    }
    for (int i = 0; i < 10; i++) {//output test
        cout << filedata[i] << endl;
    }
}

int recursiveTest(int recursiveInput){
    if (recursiveInput==0){
        return 0;
    }
    else{
        return (10+(recursiveTest(recursiveInput-1)));
    }
}

int fibonacciTest(int fibonaciInput){
    if(fibonaciInput==1 || fibonaciInput==2){
        //cout<<fibonaciInput<<"th cycle passed"<<endl;
        return 1;
    }
    else{
        //cout<<fibonaciInput<<"th cycle "<<endl;
        return (fibonacciTest(fibonaciInput-1) + fibonacciTest(fibonaciInput-2));
    }
}//ineffective -- cycle is equal or atleast bigger than the result
//eg: result = 15 then cycle >= 15

int fibonacciEfficient(int fibonaciInput){
    int x=1,y=1,result=0;
    for (int i =0; i<fibonaciInput-2; i++){
        result=x+y;
        y=x;
        x=result;
    }
    return result;
}//1 1 2 3 5 8

void some_confusion_inloop(){
    bool x=false,y=false;
    cout<<"~x || y"<<endl;
    if (~x || y){
        cout<<"return true"<<endl;//>>this returned
    }else{
        cout<<"return false"<<endl;
    }
    cout<<" x || y"<<endl;
    if(x || y){
        cout<<"return true"<<endl;
    }else{
        cout<<"return false"<<endl;//>>this returned
    }
    
    typedef struct name1{
        int age:8;
        char:0;
    } name1;
    
    void *ptr1 =nullptr;
    
    int cc=10;
    cc=+(-3);
    cc = cc + (-3);
    cout<<cc<<endl;
}

void test_BSTtoIntArray(){
    cout<<"\n----------------------------\n";
    nodeBST<int> inttree;
    inttree.insert(100);
    inttree.insert(237);
    inttree.insert(150);
    inttree.insert(125);
    inttree.insert(50);
    inttree.insert(75);
    inttree.insert(25);
    inttree.insert(175);
    inttree.insert(132);
    inttree.insert(400);
    inttree.insert(115);
    inttree.insert(76);
    inttree.insert(77);
    inttree.insert(78);

    //inttree.preorderTraversal();cout<<endl;
    inttree.inorderTraversal();cout<<endl;
    //inttree.postorderTraversal();
    
    int *intarray;
    intarray=(int*)malloc(30);//alloc arr
    cout<<intarray<<endl;//print arr address
    for(int i=0;i<30;i++){//fill arr with 9 9 9 9...
        intarray[i] = 9;
    }
    for(int i =0; i<20;i++){//print arr init value
        cout<<intarray[i]<<"  ";
    }
    cout<<"before:"<<*intarray<<" "<<intarray<<endl;

    //inttree.addToIntAraay(intarray);
    inttree.BST_to_inOrder(intarray);
    cout<<"\n after:"<<*intarray<<" "<<intarray<<endl;

    for (int i =0;i<15;i++){
        cout<<"value:"<<*intarray<<" "<<intarray<<endl;
        intarray++;
    }
}

void test_sortedArrayToBST(){
    int array1[]= {1,2,3,4,5,6,7,8,9,10,12,20,21,24,55};
    cout<<"size of array 1 is:"<<sizeof(array1)/sizeof(array1[0])<<endl;
    cout<<"size of array 1 is:"<<sizeof(array1)/sizeof(*array1)<<endl;
    
    nodeBST<int> tree2;
    tree2.sortedArrayToBST(array1, sizeof(array1)/sizeof(array1[0]));
    tree2.inorderTraversal();cout<<endl;
    tree2.inOrderIterative();
    //tree2.preorderTraversal();
}

string shiftAlphabet(int shift) {
    int start = 0;
    if (shift < 0) {
        start = (int) 'Z' + shift + 1;
    } else {
        start = 'A' + shift;
    }
    string result = "";
    char currChar = (char) start;
    for(; currChar <= 'Z'; ++currChar) {
        result = result + currChar;
    }
    if(result.length() < 26) {
        for(currChar = 'A'; result.length() < 26; ++currChar) {
            result = result + currChar;
        }
    }
    return result;
}

//==================================================================
int main(int argc, const char * argv[]) {
    //string string1="aaaaaa";
    //string1 = shiftAlphabet(1);
    //cout<<string1<<endl;
    //test_sortedArrayToBST();
    test_BSTtoIntArray();
    

    //Realisation_main_program();
    //ifndef and define use for: header file will only be compiled once
    
    //main_ftream_read_file(); //test using read file (also use file from desktop\lab 5)
    //stoi_test(); //string to int test
    //addresspointer_test_1(); // test return this pointer // not work
    //pointer_arrow_ref_test(); //test pointer ref and -> sign
    //istream_ignore_test(); // ignore in istream in iosream demonstration
    //overloadOperatorTest();// test for operator overloading
    //pointer_alternative_to_return();//wont work -only return array will work
    //floating_point_representation();//char to int and vice versa doesn't require cast (look in this function)
    //open_multiple_file();
    
    /* pass address and pointer diff in main and function comparison:
     int auiget = 425;
     cout << pass_address(auiget) << endl;
     int iagb = 146;
     iagb = pass_pointer(&auiget);
     cout << iagb << endl;
     */
    //define and class name can be different (class filename and class name can be difference?)
    //declaration vs definition: declaration is sth like :int someFunction(double, double); without implementation while definition has function
    //template 3 basic forms: function, class, variable template
    //func template behave like a func with args for diff types: template <typename T> inline T max(T a, T b) {return a > b ? a : b;}
    //class template provides a specification for generating classes based on parameters, generally used to implement parameters such as STL:vector
    //struct can pass parameter by value or by ref
    //array are passed by ref only - array cant be in return - c++ not support
    
    //cout<<"recursive result: "<<recursiveTest(5)<<endl;
    //cout<<"fibonaci seq result: "<<fibonacciTest(8)<<endl;
    //cout<<"fibonaci effcient calc: "<<fibonacciEfficient(8)<<endl;
    
    return 0;
}
