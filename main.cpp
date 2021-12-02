//
//  main.cpp
//  Cursach
//
//  Created by Danil Zalomov on 11/13/21.
//  Copyright © 2021 Danil Zalomov. All rights reserved.
//
#include "MacaleyMatrix.hpp"
#include <limits>
#include <iostream>

using namespace std;
int main(int argc, const char* argv[]) {

	//Reader* readFromFile = new Reader("File.txt");
	MacaleyMatrix* aa = new MacaleyMatrix("File.txt");
	aa->PrintMatr();
	
	return 0;
}
