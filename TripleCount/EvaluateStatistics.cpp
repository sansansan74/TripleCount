#include <random>

#include "main.h"
#include <iostream>

/// <summary>
/// return random value minimalValue <= real value <= maximumValue
/// </summary>
/// <param name="low"></param>
/// <param name="high"></param>
/// <returns></returns>
long getRandomLong(long low, long high) {
	std::random_device rd;
	std::mt19937_64 gen(rd());

	std::uniform_int_distribution<long> distrib(low, high);

	return distrib(gen);
}

/// <summary>
/// Fill vector random values between minimalValue <= real value <= maximumValue
/// </summary>
/// <param name="vect"></param>
/// <param name="minimalValue"></param>
/// <param name="maximumValue"></param>
void FillVectorRandomNumbers(vector<long>& vect, long minimalValue, long maximumValue) {
	for (size_t i = 0; i < vect.size(); i++)
	{
		vect[i] = getRandomLong(minimalValue, maximumValue);
	}
}



void PrintStatistics(size_t start, size_t finish, size_t stepCount) {
	cout << "arraySize" << "\t"
		<< "countTriplets" << "\t"
		<< "innerN4PereborOperationCount" << "\t"
		<< "allPereborOperationCount" << endl;

	for (size_t arraySize = start; arraySize < finish; arraySize += stepCount)
	{
		vector<long> arr(arraySize);
		FillVectorRandomNumbers(arr, 1, 100);
		auto result = countTriplets(arr, 2);	// i use koefficient = 2, because many nubers divided on 2^1 and 2^2

		cout << arraySize << "\t"
			<< result.countTriplets << "\t"
			<< result.innerN4PereborOperationCount << "\t"
			<< result.allPereborOperationCount << endl;
	}

	cout << "arraySize - array soze" << endl
		<< "countTriplets - unuque triples count" << endl
		<< "innerN4PereborOperationCount - internal operations count" << endl
		<< "allPereborOperationCount - all operations count." << endl;
}
