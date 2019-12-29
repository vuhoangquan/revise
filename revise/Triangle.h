//
//  Triangle.hpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#ifndef Triangle_hpp
//#define Triangle_hpp

//#include <stdio.h>

//#endif /* Triangle_hpp */


// Triangle.h

// Version
// 01 - Nicola Ritter
//-------------------------------------------------------------------

#ifndef TRIANGLE
#define TRIANGLE

//-------------------------------------------------------------------

#include <iostream>
#include "Shape.h"

using namespace std;

//-------------------------------------------------------------------

class Triangle : public Shape
{
public:
    Triangle() {m_description = "triangle";}; // for illustration only - move to cpp
    virtual ~Triangle () {};

     virtual void Draw () const; // for documentation only. Parent has declared this virtual already.

private:

};

#endif

