#include<assert.h>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
#include<unordered_map>
#include<map>
#include<chrono>
#include"countMovesSwap.h"
#include"countMovesMSetSorted.h"
#include"countMovesIterate.h"
#include"countMovesLocalMap.h"
#include"countMovesGlobalMap.h"
#include"countMovesIterateLinked.h"

using namespace std;

void testCountMoves();
void testInput();
void testPerformance();


int main() {
	//testInput2();
	testCountMoves();
	testPerformance();

	//testInput();
	getchar();
}

void fillVector(vector<size_t> & vec, const size_t size) {
	vec.clear();
	for (size_t i = size; i > 0; i--) {
		vec.push_back(i);
		vec.push_back(i);
	}
}


void testPerformance() {
	vector<size_t> vec;
	size_t vecSize = 100;
	fillVector(vec, vecSize);
	size_t moves = 0, expected;
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff;
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesSwap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesSwap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesMSetSorted(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesMSetSorted, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	expected = countMovesSwap(vec);
	assert(moves == expected);

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesLocalMap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesLocalMap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterate(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterate, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	expected = countMovesSwap(vec);
	assert(moves == expected);

	vecSize = 200;
	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesSwap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesSwap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesMSetSorted(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesMSetSorted, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesLocalMap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesLocalMap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterate(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterate, vecSize: " << vecSize << ", " << diff.count() << endl;

	vecSize = 400;
	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesSwap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesSwap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesMSetSorted(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesMSetSorted, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesLocalMap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesLocalMap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterate(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterate, vecSize: " << vecSize << ", " << diff.count() << endl;

	vecSize = 800;
	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesSwap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesSwap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesMSetSorted(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesMSetSorted, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesLocalMap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesLocalMap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterate(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterate, vecSize: " << vecSize << ", " << diff.count() << endl;

	vecSize = 1600;
	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesSwap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesSwap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesMSetSorted(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesMSetSorted, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesLocalMap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesLocalMap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterate(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterate, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterateLinked(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterateLinked, vecSize: " << vecSize << ", " << diff.count() << endl;
	//countMovesIterateLinked

	vecSize = 3200;
	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesSwap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesSwap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesMSetSorted(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesMSetSorted, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesLocalMap(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesLocalMap, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterate(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterate, vecSize: " << vecSize << ", " << diff.count() << endl;

	fillVector(vec, vecSize);
	start = std::chrono::high_resolution_clock::now();
	moves = countMovesIterateLinked(vec);
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	cout << "countMovesIterateLinked, vecSize: " << vecSize << ", " << diff.count() << endl;

	cout << __FUNCTION__ << " os ok" << endl;
}

void testInput() {
	int tc, size;
	vector<size_t> vec;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		vec.clear();
		cin >> size;
		for (int j = 0; j < size; j++) {
			int d;
			cin >> d;
			vec.push_back(d);
		}
		cout << countMovesSwap(vec) << endl;
	}
	cout << __FUNCTION__ << " os ok" << endl;
}


void testCountMoves() {
	vector<size_t> vec = { 4,3,2,1 };
	size_t moves = countMovesSwap(vec);
	size_t expected = 6;
	assert(moves == expected);

	vec = { 4,3,2,1 };
	moves = countMovesMSetSorted(vec);
	expected = 6;
	assert(moves == expected);

	vec = { 4,3,2,1 };
	moves = countMovesLocalMap(vec);
	expected = 6;
	assert(moves == expected);

	vec = { 4,3,2,1 };
	moves = countMovesIterate(vec);
	expected = 6;
	assert(moves == expected);

	vec = { 4,3,2,1 };
	//moves = countMovesGlobalMap(vec);
	expected = 6;
	assert(moves == expected);

	vec = { 1,1,1,2,2 };
	moves = countMovesSwap(vec);
	expected = 0;
	assert(moves == expected);

	vec = { 1,1,1,2,2 };
	moves = countMovesMSetSorted(vec);
	expected = 0;
	assert(moves == expected);

	vec = { 1,1,1,2,2 };
	moves = countMovesLocalMap(vec);
	expected = 0;
	assert(moves == expected);

	vec = { 1,1,1,2,2 };
	moves = countMovesIterate(vec);
	expected = 0;
	assert(moves == expected);

	vec = { 1,1,1,2,2 };
	//moves = countMovesGlobalMap(vec);
	expected = 0;
	assert(moves == expected);

	vec = { 2,1,3,1,2 };
	moves = countMovesSwap(vec);
	expected = 4;
	assert(moves == expected);

	vec = { 2,1,3,1,2 };
	moves = countMovesMSetSorted(vec);
	expected = 4;
	assert(moves == expected);

	vec = { 2,1,3,1,2 };
	moves = countMovesLocalMap(vec);
	expected = 4;
	assert(moves == expected);

	vec = { 2,1,3,1,2 };
	moves = countMovesIterate(vec);
	expected = 4;
	assert(moves == expected);

	vec = { 2,1,3,1,2 };
	//moves = countMovesGlobalMap(vec);
	expected = 4;
	assert(moves == expected);

	vec = { 7,4,6,2,1,1 };
	moves = countMovesSwap(vec);
	expected = 13;
	assert(moves == expected);

	vec = { 7,4,6,2,1,1 };
	moves = countMovesIterate(vec);
	expected = 13;
	assert(moves == expected);

	vec = { 7,4,6,2,1,1 };
	moves = countMovesLocalMap(vec);
	expected = 13;
	assert(moves == expected);

	vec = { 7,4,6,2,1,1 };
	moves = countMovesMSetSorted(vec);
	expected = 13;
	assert(moves == expected);

	vec = { 24,13,14,22,10,9,7,8,6,25 };
	moves = countMovesSwap(vec);
	expected = 32;
	assert(moves == expected);

	vec = vec = { 24,13,14,22,10,9,7,8,6,25 };
	moves = countMovesMSetSorted(vec);
	expected = 32;
	assert(moves == expected);

	vec = vec = { 24,13,14,22,10,9,7,8,6,25 };
	moves = countMovesIterate(vec);
	expected = 32;
	assert(moves == expected);

	vec = vec = { 24,13,14,22,10,9,7,8,6,25 };
	//moves = countMovesGlobalMap(vec);
	expected = 32;
	assert(moves == expected);

	vec = { 4,3,2,1,1 };
	moves = countMovesSwap(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,2,1,1 };
	moves = countMovesMSetSorted(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,2,1,1 };
	moves = countMovesIterate(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,2,1,1 };
	moves = countMovesLocalMap(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,2,1,1 };
	moves = countMovesIterate(vec);
	expected = 9;
	assert(moves == expected);

	vec = { 4,3,2,1,1 };
	moves = countMovesSwap(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,3,2,1 };
	moves = countMovesMSetSorted(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,3,2,1 };
	moves = countMovesIterate(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,3,2,1 };
	moves = countMovesLocalMap(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,3,2,1 };
	moves = countMovesIterate(vec);
	expected = 9;
	assert(moves == expected);

	vec = vec = { 4,3,3,2,1 };
	moves = countMovesIterateLinked(vec);
	expected = 9;
	assert(moves == expected);

	cout << __FUNCTION__ << " os ok" << endl;
}