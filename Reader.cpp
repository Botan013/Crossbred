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

void Reader::ReadParams(string way){
    ifstream in(way);
    in >> this->numOfVar >> this->numOfPol;
}

void Reader::ReadMatr(string way){
    ifstream in(way);
    u_long combinations = this->numOfVar * this->numOfVar / 2 + this->numOfVar + 1;
    
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

void Reader::RegMatr(){
    u_long combinations = this->numOfVar * this->numOfVar / 2 + this->numOfVar + 1;
    this->mas = new bool *[this->numOfPol];
          for (int i = 0; i < this->numOfPol; ++i)
              this->mas[i] = new bool [combinations];
}

Reader::Reader(string way)
{
    ReadParams(way);
    RegMatr();
    ReadMatr(way);

}
