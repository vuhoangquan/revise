//
//  Rectangle.hpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//
/*
#ifndef Rectangle_h
#define Rectangle_h

#include <stdio.h>
*/

// Rectangle.h

// Version
// 01 - Nicola Ritter
//-------------------------------------------------------------------

#ifndef RECTANGLE_h
#define RECTANGLE_h

//-------------------------------------------------------------------

#include <iostream> //is this needed here?

#include "Shape.h"

using namespace std; // does the std namespace need to be exposed?

//-------------------------------------------------------------------

class Rectangle : public Shape
{
public:
    Rectangle();
    virtual ~Rectangle () {};

    virtual void Draw () const; // for documentation only. Parent has declared this virtual already.
    virtual void Input (); // "virtual" for documentation only. Parent has declared this virtual already.


private:
    int m_width;
};

#endif


//#endif /* Rectangle_hpp */
