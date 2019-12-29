//
//  Rectangle.cpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#include "Rectangle.hpp"
// Rectangle.cpp
//imported from ict283 

#include "Rectangle.h"

//-------------------------------------------------------------------

Rectangle::Rectangle ()
{
    m_width = 0;
    m_description = "rectangle";
}

//-------------------------------------------------------------------

void Rectangle::Draw () const
{
    for (int row = 0; row < m_height; row++)
    {
        for (int col = 0; col < m_width * ASPECT_RATIO; col++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;
}

//-------------------------------------------------------------------

void Rectangle::Input ()
{
    Shape::Input (); // Calls the parent's Input
    cout << "Enter rectangle width: ";
    cin >> m_width;
}

//-------------------------------------------------------------------

