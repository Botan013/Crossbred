//
//  Reader.cpp
//  Cursach
//
//  Created by Danil Zalomov on 11/15/21.
//  Copyright © 2021 Danil Zalomov. All rights reserved.
//
#include "Reader.hpp"
#include "InfInt.h"
#include <limits>
#include <iostream>
#include <string>
#include<fstream>

using namespace std;

Reader::Reader(string way)
{
    ifstream in(way);
    if(!in)
        throw std::invalid_argument("No such File");
    
    in >> this->numOfVar >> this->numOfPol;
    u_long combinations = this->numOfVar * this->numOfVar / 2 + this->numOfVar + 1;
    
    this->mas = new bool *[this->numOfPol];
    for (int i = 0; i < this->numOfPol; ++i)
        this->mas[i] = new bool [combinations];
    
    for (int i = 0; i < this->numOfPol; ++i)
    {
        string a;
        for(int j=0;j < combinations; ++j)
        {
            in >> this-> mas[i][j] ;
        }
        in >> a;
    }
    
        
}
