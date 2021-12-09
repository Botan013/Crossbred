//
//  Reader.hpp
//  Cursach
//
//  Created by Danil Zalomov on 11/15/21.
//  Copyright � 2021 Danil Zalomov. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp
#include "InfInt.h"
#include<fstream>
#include <string>
#include <stdio.h>

using namespace std;

class Reader
{
public:
	Reader(string way);
	void ReadParams(string way);
	void ReadMatr(string way);
	void RegMatr();
	bool** mas;
	long numOfVar;
	long numOfPol;
    long size;
};

#endif /* Reader_hpp */
