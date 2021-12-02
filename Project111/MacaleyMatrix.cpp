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
#include "Combinations.hpp"
using namespace std;

MacaleyMatrix::MacaleyMatrix(long _numOfVar, long _numOfEquat, bool** matrix)
{
	this->numOfVar = _numOfVar;
	this->numOfPol = _numOfEquat;
	//cout<<matrix[0][0];
}

MacaleyMatrix::MacaleyMatrix(Reader* reader)
{
	this->numOfVar = reader->numOfVar;
	this->numOfPol = reader->numOfPol;
	this->macMatr = reader->mas;

}

MacaleyMatrix::MacaleyMatrix(string way)
{
	Reader* readFromFile = new Reader(way);
	MacaleyMatrix* aa = new MacaleyMatrix(readFromFile);
	this->numOfVar = readFromFile->numOfVar;
	this->numOfPol = readFromFile->numOfPol;
	this->macMatr = readFromFile->mas;

}

void MacaleyMatrix::AddSomeRows() {

}

void MacaleyMatrix::PrintMatr() {
	Combinations* combinations = new Combinations(this->numOfVar);
	//long combinations = this->numOfVar * (this->numOfVar - 1) / 2 + this->numOfVar + 1;
	for (int i = 0; i < this->numOfPol; ++i)
	{
		for (int j = 0; j < combinations->GetX(); ++j)
		{
			cout << this->macMatr[i][j]<<' ';
		}
		cout <<';' << endl;
	}
}

long MacaleyMatrix::Sum()
{
	return (numOfVar + numOfPol);
}
