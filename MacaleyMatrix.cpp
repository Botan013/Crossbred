//
//  MacaleyMatrix.cpp
//  Cursach
//
//  Created by Danil Zalomov on 11/13/21.
//  Copyright © 2021 Danil Zalomov. All rights reserved.
//

#include "MacaleyMatrix.hpp"
#include "InfInt.h"
#include <limits>
#include <iostream>
#include "Reader.hpp"

using namespace std;

MacaleyMatrix::MacaleyMatrix(u_long _numOfVar, u_long _numOfEquat, bool** matrix)
{
    this -> numOfVar = _numOfVar;
    this -> numOfPol = _numOfEquat;
    //cout<<matrix[0][0];
}
   
MacaleyMatrix::MacaleyMatrix(Reader *reader)
{
    this -> numOfVar = reader->numOfVar;
    this -> numOfPol = reader->numOfPol;
    this->macMatr = reader->mas;
    
}

void MacaleyMatrix::PrintMatr(){
    u_long combinations = this->numOfVar * this->numOfVar / 2 + this->numOfVar + 1;
    for (int i = 0; i < this->numOfPol; ++i)
    {
        for(int j=0; j < combinations; ++j)
        {
            cout<<this->macMatr[i][j];
        }
            cout<<endl;
    }
}

u_long MacaleyMatrix::Sum()
{
    return (numOfVar + numOfPol);
}
