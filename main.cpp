//
//  main.cpp
//  Cursach
//
//  Created by Danil Zalomov on 11/13/21.
//  Copyright © 2021 Danil Zalomov. All rights reserved.
//
#include "InfInt.h"
#include "MacaleyMatrix.hpp"
#include <limits>
#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
//    u_long a = 1;
//    u_long b = 2;
//    //a = numeric_limits<long>::max();
//    //a+=a;
//    bool **mas = new bool *[a];
//    for (int i = 0; i < a; i++)
//        mas[i] = new bool [b];
//    //mas[0][0] = 1;
//    //a++;
    Reader *readFromFile = new Reader("/Users/danilzalomov/Desktop/File.strings");
    MacaleyMatrix *aa = new MacaleyMatrix(readFromFile);
    aa->PrintMatr();
   // cout<<aa->Sum();
    
//    for (int i = 0; i < a; i++)
//        delete[] mas[i];
//    delete [] mas;
    //a++;
    //cout<<a<<endl;
    //u_long *mas = new u_long[a];
    return 0;
}
