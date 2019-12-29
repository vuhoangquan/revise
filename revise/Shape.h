//
//  Shape.hpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#ifndef Shape_h
//#define Shape_h

//#include <stdio.h>

//#endif /* Shape_h */

// Shape.h
// An abstract base class for drawing shapes.
// Version
// 01 - Nicola Ritter
// modified smr - to demonstrate dynamic polymorphism in C++
// Examine what is needed for this dynamic polymorphism to occur
//-------------------------------------------------------------------

#ifndef SHAPE
#define SHAPE

#include <string>

//#include <iostream> // is iostream needed here on in shape.cpp?



using std::string; // exposing only what is needed.

//-------------------------------------------------------------------
const float ASPECT_RATIO = 12.0/8.0;

//-------------------------------------------------------------------

class Shape // abstract because of pure virtual methods
{
public:
    Shape() {m_height = 0;}
    virtual ~Shape () {};

    //For illustration only. Input is not normal behaviour for a Shape class, so having Input as a method stuffs up the OO design.
    // Set methods should be there instead.
    // Input method only to illustrate two virtual methods, one that is pure (=0) and the other that is not pure.
    // for polymorphism to occur, method needs to be virtual and the method needs to be accessed via a pointer ->
    // Input does not have =0 (not pure) so code body for Input is provided.
    virtual void Input ();

    //pure virtual. Pure (=0) means you can't create an object of Shape. There is no Shape::Draw() defined.
    //Virtual means that Draw can be polymorphic but needs to be accessed via the parent pointer, just like Input() above.
    virtual void Draw () const = 0;

protected:
    int m_height;
    string m_description;

};

//-------------------------------------------------------------------

#endif

