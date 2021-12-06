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
#include "Combinations.hpp"

using namespace std;

void Reader::ReadParams(string way) {
	ifstream in(way);
	in >> this->numOfPol >> this->numOfVar;
	in.close();
}

void Reader::ReadMatr(string way) {
	ifstream in(way);
	Combinations* combinations = new Combinations(this->numOfVar);
	//long combinations = this->numOfVar * (this->numOfVar - 1) / 2 + this->numOfVar + 1;
	in >> this->numOfPol >> this->numOfVar;
	for (int i = 0; i < this->numOfPol; ++i)
	{
		string a;
		for (int j = 0; j < combinations->GetX(); ++j)
		{
			in >> this->mas[i][j];
		}
		in >> a;
	}
	in.close();

}

void Reader::RegMatr() {
	Combinations* combinations = new Combinations(numOfVar);
	this->mas = new bool* [this->numOfPol];
	for (int i = 0; i < this->numOfPol; ++i)
		this->mas[i] = new bool[combinations->GetX()];
}

Reader::Reader(string way)
{
	ReadParams(way);
	RegMatr();
	ReadMatr(way);

}
