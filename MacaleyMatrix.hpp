//
//  MacaleyMatrix.hpp
//  Cursach
//
//  Created by Danil Zalomov on 11/13/21.
//  Copyright � 2021 Danil Zalomov. All rights reserved.
//

#ifndef MacaleyMatrix_hpp
#define MacaleyMatrix_hpp

#include <stdio.h>
#include "Reader.hpp"
#include "InfInt.h"
class MacaleyMatrix
{
public:
	MacaleyMatrix(long _numOfVar, long _numOfEquat, bool** matrix);
	MacaleyMatrix(Reader* reader);
	MacaleyMatrix(string way);
	void PrintMatr();
    void Diagonalaise();
	//void RegMatr(bool *mas);
    void NewMatr(long newNumOfPol);
	long Sum();
	void AddSomeRows();
	long numOfPol;
	long size;
	long numOfVar;
	bool** macMatr;
};

#endif /* MacaleyMatrix_hpp */
