//
//  Square.hpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#ifndef Square_hpp
//#define Square_hpp

//#include <stdio.h>

//#endif /* Square_hpp */


// Square.h

// Version
// 01 - Nicola Ritter
//-------------------------------------------------------------------

#ifndef SQUARE
#define SQUARE

//-------------------------------------------------------------------

#include <iostream> // needed here?
#include "Shape.h"

using namespace std; // needed here or in the .cpp?

//-------------------------------------------------------------------

class Square : public Shape
{
public:
    Square() {m_description = "square";} // for illustration only - move body to cpp
    virtual ~Square () {};

    virtual void Draw () const; // for documentation only. Parent has declared this virtual already. one of the requirements for dynamic polymorphism

private:

};

#endif

