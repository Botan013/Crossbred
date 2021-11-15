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
   
MacaleyMatrix::MacaleyMatrix(Reader reader)
{
    this -> numOfVar = reader.numOfVar;
    this -> numOfPol = reader.numOfPol;
    
}

u_long MacaleyMatrix::Sum()
{
    return (numOfVar + numOfPol);
}
