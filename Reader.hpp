//
//  Reader.hpp
//  Cursach
//
//  Created by Danil Zalomov on 11/15/21.
//  Copyright © 2021 Danil Zalomov. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include <string>
#include "InfInt.h"
#include <stdio.h>

using namespace std;

class Reader
{
public:
    Reader(string way);
    bool **mas;
    u_long numOfVar;
    u_long numOfPol;
};

#endif /* Reader_hpp */
