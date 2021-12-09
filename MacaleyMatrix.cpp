//
//  MacaleyMatrix.cpp
//  Cursach
//
//  Created by Danil Zalomov on 11/13/21.
//  Copyright � 2021 Danil Zalomov. All rights reserved.
//

#include "MacaleyMatrix.hpp"
#include "InfInt.h"
#include <limits>
#include <cmath>
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
    this->size = readFromFile -> size;
	this->macMatr = readFromFile->mas;

}

//void MacaleyMatrix::RegMatr(bool* mas, long numOfPol, long numOfVar) {


//}

void MacaleyMatrix::NewMatr(long newNumOfPol)
{
    Combinations* combinations = new Combinations();
    long newSize = this->size + 1;

    bool** mas = new bool* [newNumOfPol];
    for (long i = 0; i < newNumOfPol; ++i)
        mas[i] = new bool[combinations->CalculateCombinations(newSize, this->numOfVar)];

     for (long i = 0; i < newNumOfPol; ++i)
         for (long j = 0; j < combinations->CalculateCombinations(newSize, this->numOfVar); ++j)
             mas[i][j] = 0;
    
    long* matrHelp = new long[combinations->CalculateCombinations(newSize, this->numOfVar)];
    combinations->FillMatrix(matrHelp, this->numOfVar);
    
    //ПЕРЕСМОТРЕТЬ ЭТУ ЛОГИКУ------------------------------------
    for(long i=0; i < newNumOfPol; ++i){
        if(i % (this->numOfVar + 1) == 0){
            for(long j= combinations->CalculateCombinations(this->size, this->numOfVar) - 1 ; j>=0; --j){
                mas[i][j
                           - combinations->CalculateCombinations(this->size, this->numOfVar)
                           + combinations->CalculateCombinations(newSize, this->numOfVar)]
                = this->macMatr[i/(this->numOfVar+1)][j];
            }
        }
        
        else{
            for (long j=0, flag; j < combinations->CalculateCombinations(this->size, this->numOfVar); ++j){
                if(this->macMatr[i/(this->numOfVar + 1)][j] == 1){
                    
                    flag=(matrHelp[j + combinations->CalculateCombinations(newSize, this->numOfVar)
                                   - combinations->CalculateCombinations(this->size, this->numOfVar)]
                          |static_cast<long>(pow(2,i%(this->numOfVar+1)))) ;
                    for(long z=0;z < combinations->CalculateCombinations(newSize, this->numOfVar); ++z){
                        if(matrHelp[z] == flag){
                            mas[i][z]=1;
                        }
                    }
                }
            }
        }
        
    }
    
    this->macMatr = mas;
    this->numOfPol = newNumOfPol;
    this->size = newSize;
}

void MacaleyMatrix::AddSomeRows() {

    NewMatr((this->numOfPol)*(this->numOfVar + 1));
    

}

void MacaleyMatrix::PrintMatr() {
	Combinations* combinations = new Combinations();
    
	//long combinations = this->numOfVar * (this->numOfVar - 1) / 2 + this->numOfVar + 1;
	for (long i = 0; i < this->numOfPol; ++i)
	{
		for (long j = 0; j < combinations->CalculateCombinations(this->size, this->numOfVar); ++j)
		{
			cout << this->macMatr[i][j]<<' ';
		}
		cout <<';' << endl;
	}
    cout<<endl;
}

void MacaleyMatrix::Diagonalaise(){
    Combinations* comb = new Combinations();
    for(long i=0;i<comb->CalculateCombinations(this->size, this->numOfVar);++i){
        for(long j=i,flag=0;j<this->numOfPol;++j){
            if(this->macMatr[j][i]==1){
                if(flag==0){
                    flag=1;
                    for(long z=i; z < comb->CalculateCombinations(this->size, this->numOfVar);++z){
                        swap(this->macMatr[j][z], this->macMatr[i][z]);
                    }
                }
                else{
                    for(long z=i; z < comb->CalculateCombinations(this->size, this->numOfVar);++z){
                        this->macMatr[j][z]=(this->macMatr[j][z]+this->macMatr[i][z])%2;
                    }
                }
            }
           
        }
    }
    //PrintMatr(this->size);
    for(long i=this->numOfPol - 1; i > 0; --i){
        for(long j=0; j< comb->CalculateCombinations(this->size, this->numOfVar); ++j){
            if(this->macMatr[i][j]==1){
                for(long z=i-1;z>=0;--z){
                    if(this->macMatr[z][j]==1){
                        for(long a=j;a>=0;--a){
                            this->macMatr[z][a]=(this->macMatr[z][a]+macMatr[i][a])%2;
                        }
                    }
                }
                j=0;
                --i;
                if(i<0)
                    break;
            }
        }
    }
}

long MacaleyMatrix::Sum()
{
	return (numOfVar + numOfPol);
}
