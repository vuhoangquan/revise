//
//  Track.h
//  revise
//
//  Created by Vũ hoàng Quân on 8/1/20.
//  Copyright © 2020 Vũ hoàng Quân. All rights reserved.
//
#include <iostream>
using namespace std;
#ifndef Track_h
#define Track_h

class Track{
public:
    Track();
    void OutputString() const;
private:
    string m_title;
};

#endif /* Track_h */
