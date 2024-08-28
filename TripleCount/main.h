#pragma once

#include <vector>

using namespace std;

struct CountTripletsResult {
	long countTriplets;
	long allPereborOperationCount;
	long innerN4PereborOperationCount;
};

CountTripletsResult countTriplets(const vector<long>& sourceArray, long r);
