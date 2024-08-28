
#include "main.h"
#include "Tests.h"

#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

void TestEqualSolutionCount(vector<long> arr, long r, long solutionCount) {
	auto result = countTriplets(arr, r);
	if (result.countTriplets != solutionCount) {
		throw std::logic_error("Ошибка алгоритма. Д.б. " + std::to_string(solutionCount) + " решение");
	}
}

void TestSimleOneSolution(long r) {
	vector<long> arr = { 1, r, r * r };	// одно решение
	TestEqualSolutionCount(arr, r, 1);
}

/// <summary>
/// Проверяю, что лишние числа не влияют на решение
/// </summary>
/// <param name="r"></param>
void Test1SolutionNoAffectOfOtherElements(long r) {
	vector<long> arr = { 70, 1, 3, r, 19, r * r, 23 };	// одно решение
	TestEqualSolutionCount(arr, r, 1);
}

void TestNoSolutionChangedIndex(long r) {
	vector<long> arr = { r, r * r, 1 };	// решения нет - поменяны первый и третий элементы
	TestEqualSolutionCount(arr, r, 0);
}

void TestDoubleFirstElement(long r) {
	vector<long> arr = { 1, 1, r, r * r };		// задвоили первый элемент
	TestEqualSolutionCount(arr, r, 2);
}

void TestDouble2Element(long r) {
	vector<long> arr = { 1, r, r, r * r };		// задвоили второй элемент
	auto result = countTriplets(arr, r);
	TestEqualSolutionCount(arr, r, 2);
}

void Test2Secuence(long r) {
	vector<long> arr = { 1, r, r * r, r * r *r };		// задвоили второй элемент
			// 1, r, r*r
			// r, r*r, r*r*r
	auto result = countTriplets(arr, r);
	TestEqualSolutionCount(arr, r, 2);
}

void Test2SecuenceIndependant(long r) {
	vector<long> arr = { 1, r, r * r, 3, 6, 12 };		// задвоили второй элемент
	// 1, r, r*r
	// r, r*r, r*r*r
	auto result = countTriplets(arr, r);
	TestEqualSolutionCount(arr, r, 2);
}


void TestDoubleThirdElement(long r) {
	vector<long> arr = { 1, r, r * r, r * r };		// задвоили третий элемент
	TestEqualSolutionCount(arr, r, 2);
}

void Test2Solutions_8(long r) {
	vector<long> arr = { 1, 1, r, r, r * r, r * r };		// задвоили все элементы
	auto result = countTriplets(arr, r);
	TestEqualSolutionCount(arr, r, 8);

}

void CheckAllTests() {
	TestSimleOneSolution(2);
	Test1SolutionNoAffectOfOtherElements(2);
	TestNoSolutionChangedIndex(2);
	TestDoubleFirstElement(2);
	TestDouble2Element(2);
	Test2Secuence(2);
	Test2SecuenceIndependant(2);
	TestDoubleThirdElement(2);
	Test2Solutions_8(2);
}