#include "Combinations.hpp"

Combinations::Combinations(long a)
{
	this -> x = a * (a - 1) / 2 + a + 1;
}

long Combinations::GetX()
{
	return this->x;
}
