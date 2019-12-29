//
//  Square.cpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#include "Square.hpp"

// Square.cpp

#include "Square.h"

//-------------------------------------------------------------------

void Square::Draw () const // what does const do?
{
    for (int row = 0; row < m_height; row++)
    {
        for (int col = 0; col < m_height * ASPECT_RATIO; col++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;
}

//-------------------------------------------------------------------

