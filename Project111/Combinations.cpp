#include "Combinations.hpp"
#include <cmath>

using namespace std;

Combinations::Combinations(long a)
{
	this -> x = a * (a - 1) / 2 + a + 1;
}

Combinations::Combinations()
{
	
}

void Combinations::FillMatrix(long *mass, long a) {

	int counter = 0;
	for (int i = 0;i < a - 2; ++i) {
		for (int j = i + 1; j < a - 1; ++j) {
			for (int z = j + 1; z < a; ++z) {
				mass[counter] = static_cast<long>( pow(2, i+1) + pow(2, j + 1) + pow(2, z + 1));
				counter++;
			}
		}
	}

	for (int i = 0;i < a - 1; ++i) {
		for (int j = i + 1;j < a; ++j) {
			mass[counter] = pow(2, i + 1) + pow(2, j + 1);
			counter++;
		}
	}

	for (int i = 0;i < a;++i) {
		mass[counter] = pow(2, i + 1);
		counter++;
	}
	mass[counter] = 1;
	counter++;

	//this->mas = new long[a];
	//for (int i = 0; i < a; ++i) {
	//	this->mas[i] = pow(2, i + 1);
	//}
}

long Combinations::CalculateCombinations(long size, long numOfVar)
{
	long answer = 1;
	long slag = 1;
	for (int i = 1; i < size + 1; ++i) {
		for (int j = 1; j < i; ++j)
			slag *= (x - j + 1);
		slag /= tgamma(i + 1);
		answer += slag;
		answer = 1;
	}

	return answer;
}

long Combinations::GetCurrentSize()
{
	return 2;
}

long Combinations::GetX()
{
	return this->x;
}
