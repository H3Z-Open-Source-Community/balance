#pragma once

#include <vector>

#include "fraction.h"

using std::vector;

vector <vector <Fraction> > deterToVector(int nums[100][100], int x, int y);
vector <Fraction> gaussianElimination(vector <vector <Fraction> > nums);
