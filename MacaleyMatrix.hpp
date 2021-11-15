//
//  MacaleyMatrix.hpp
//  Cursach
//
//  Created by Danil Zalomov on 11/13/21.
//  Copyright © 2021 Danil Zalomov. All rights reserved.
//

#ifndef MacaleyMatrix_hpp
#define MacaleyMatrix_hpp

#include "InfInt.h"
#include <stdio.h>
#include "Reader.hpp"

class MacaleyMatrix
{
public:
    MacaleyMatrix(u_long _numOfVar, u_long _numOfEquat, bool** matrix);
    MacaleyMatrix(Reader reader);
    u_long Sum();
    
private:
    u_long numOfPol;
    u_long combinations;
    u_long numOfVar;
};

#endif /* MacaleyMatrix_hpp */
