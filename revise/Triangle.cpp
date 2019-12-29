//
//  Triangle.cpp
//  revise
//
//  Created by Vũ hoàng Quân on 29/12/19.
//  Copyright © 2019 Vũ hoàng Quân. All rights reserved.
//

//#include "Triangle.hpp"

// Triangle.cpp

#include "Triangle.h"

//-------------------------------------------------------------------

void Triangle::Draw () const // does the actual drawing. what does const mean in this context?
{
    for (int row = 0; row < m_height; row++)
    {
        for (int col = 0; col < row+1; col++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;
}

//-------------------------------------------------------------------
