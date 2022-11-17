#include "elimination.h"


vector <vector <Fraction> > deterToVector(int nums[100][100], int x, int y)
{
	vector <vector <Fraction> > vec;
	vector <Fraction> empty;

	vec.push_back(empty);

	for (int i = 1; i <= x; ++i)
	{
		vec.push_back(empty);
		vec.at(i).push_back(0);
		for (int j = 1; j <= y; ++j)
		{
			vec.at(i).push_back(nums[i][j]);
		}
	}

	return vec;
}

vector <Fraction> gaussianElimination(vector <vector <Fraction> > nums)
{
	const int n = nums.size() - 1;
	vector <Fraction> result;

	for (int i = 1; i <= n; ++i)
	{
		int j = 1, m = i;
		for (j = i + 1; j <= n; ++j)
		{
			if (math::anyAbs(nums[j][i]) > math::anyAbs(nums[j][m]))
			{
				m = j;
			}
		}

		if (nums[m][i] == 0)
		{
			throw "Error: No Solution";
		}

		if (m != i)
		{
			std::swap(nums[i], nums[m]);
		}

		for (int k = 1; k <= n; ++k)
		{
			if (k == i or nums[k][i] == 0)
			{
				continue;
			}

			Fraction div = nums[k][i] / nums[i][i];
			for (int l = 1; l <= n + 1; ++l)
			{
				nums[k][l] = nums[k][l] - div * nums[i][l];
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		result.push_back((-nums[i][n + 1]) / nums[i][i]);
	}

	Fraction finally = 1;
	result.push_back(finally);

	return result;
}
