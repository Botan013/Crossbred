#pragma once
class Combinations
{
public:
	long x;
	long* mas;
	Combinations();
	Combinations(long a);
	void FillMatrix(long *mass, long a);
	long GetX();
	long GetCurrentSize();
	long CalculateCombinations(long size, long numOfVar);
};

