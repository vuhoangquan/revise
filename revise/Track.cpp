//
//  Track.cpp
//  revise
//
//  Created by Vũ hoàng Quân on 8/1/20.
//  Copyright © 2020 Vũ hoàng Quân. All rights reserved.
//

#include <iostream>
#include "Track.h"
using namespace std;

Track::Track(){
    m_title="don nod trumpp";
}
void Track::OutputString() const{
    cout << m_title<<"is sth"<<endl;
}

