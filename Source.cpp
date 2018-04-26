#include<assert.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>

using namespace std;

class CanBeSortedCheck {
private:
	vector<int> sorted;
	vector<int> notSorted;
public:
	CanBeSortedCheck(const vector<int> & vec) :sorted(vec), notSorted(vec) {
		sort(sorted.begin(), sorted.end());
	}
	bool isSorted() const {
		return notSorted == sorted;
	}

	bool isSorted(const size_t idx1, const size_t idx2) const {
		if ((idx1 >= notSorted.size()) || (idx2 >= notSorted.size()))
			return false;
		size_t first = std::min(idx1, idx2);
		size_t second = std::max(idx1, idx2);
		for (size_t i = first; i <= second; i++) {
			if (sorted[i] != notSorted[i])
				return false;
		}
		return true;
	}
	void swap(const size_t idx1, const size_t idx2) {
		if ((idx1 >= notSorted.size()) || (idx2 >= notSorted.size()))
			return;
		int tmp = notSorted[idx1];
		notSorted[idx1] = notSorted[idx2];
		notSorted[idx2] = tmp;
	}
	void reverse(const size_t beg, const size_t end) {
		if ((beg >= notSorted.size()) || (end >= notSorted.size()))
			return;
		if (beg <= end)
			std::reverse(notSorted.begin() + beg, notSorted.begin() + end + 1);
		else
			std::reverse(notSorted.begin() + end, notSorted.begin() + beg + 1);
	}
	vector<int> getNotSorted() const {
		return notSorted;
	}

	vector <pair<size_t, size_t>> getNotSortedAreas() const {
		vector<pair<size_t, size_t>> ret;
		pair<size_t, size_t> p(0, 0);
		for (size_t i = 0; i < notSorted.size(); i++) {
			if (notSorted[i] == sorted[i])
				continue;
			p.first = i;
			while ((i < notSorted.size()) && (notSorted[i] != sorted[i]))
				i++;

			p.second = i - 1;
			ret.push_back(p);
		}
		return ret;
	}
public:
	string canBeSorted()  {
		vector<pair<size_t, size_t>> notSortedAreas = getNotSortedAreas();
		if (notSortedAreas.size() == 0)
			return "yes";
		if (notSortedAreas.size() > 2) {
			return "no";
		}
		if (notSortedAreas.size() == 2) {
			if ((notSortedAreas[0].first == notSortedAreas[0].second) &&
				(notSortedAreas[1].first == notSortedAreas[1].second)) {
				return "yes\nswap " + to_string(notSortedAreas[0].first + 1) + " " + to_string(notSortedAreas[1].first + 1);
			}

			reverse(notSortedAreas[0].first, notSortedAreas[1].second);
			if (notSorted == sorted)
				return "yes\nreverse " + to_string(notSortedAreas[0].first + 1) + " " + to_string(notSortedAreas[1].second + 1);

			return "no";
		}
		if ((notSortedAreas[0].first + 1) == notSortedAreas[0].second)
			return "yes\nswap " + to_string(notSortedAreas[0].first + 1) + " " + to_string(notSortedAreas[0].second + 1);
		reverse(notSortedAreas[0].first, notSortedAreas[0].second);
		if (notSorted == sorted)
			return "yes\nreverse " + to_string(notSortedAreas[0].first + 1) + " " + to_string(notSortedAreas[0].second + 1);
		return "no";
	}
};




void testSwap();
void testReverse();
void testIsSorted();
void testGetNotSortedAreas();
void testCanBeSorted();

int main() {
	testSwap();
	testReverse();
	testIsSorted();
	testGetNotSortedAreas();
	testCanBeSorted();
	getchar();
	return 0;
}

void testCanBeSorted() {
	vector<int> vec = { 4,2 };
	CanBeSortedCheck  cbs(vec);
	cout << cbs.canBeSorted() << endl;

	vec = { 3,1,2 };
	cbs = CanBeSortedCheck(vec);
	cout << cbs.canBeSorted() << endl;

	vec = { 1,5,4,3,2,6 };
	cbs = CanBeSortedCheck(vec);
	cout << cbs.canBeSorted() << endl;

	vec = { 1,2,6,5,4,3,7,8 };
	cbs = CanBeSortedCheck(vec);
	cout << cbs.canBeSorted() << endl;

	vec = { 1,2,4,6,5,3,7,8 };
	cbs = CanBeSortedCheck(vec);
	cout << cbs.canBeSorted() << endl;

	vec = { 7, 6, 5, 4, 3, 2, 1 };
	cbs = CanBeSortedCheck(vec);
	cout << cbs.canBeSorted() << endl;

	//1 2 4 6 5 3 7 8

	cout << "testCanBeSorted is ok!" << endl;
}

void testGetNotSortedAreas() {
	vector<int> vec = { 1, 2, 3, 5, 4, 8, 9, 10, 7 };
	CanBeSortedCheck  cbs(vec);
	vector<pair<size_t, size_t>> result = cbs.getNotSortedAreas();
	vector<pair<size_t, size_t>> expectedVec = { {3,8} };
	assert(result == expectedVec);

	vec = { 1, 2, 3, 4, 5, 7, 8, 9, 10 };
	cbs = CanBeSortedCheck(vec);
	result = cbs.getNotSortedAreas();
	expectedVec = { };
	assert(result == expectedVec);

	vec = { 1, 2, 3, 7, 5, 4, 8, 9 };
	cbs = CanBeSortedCheck(vec);
	result = cbs.getNotSortedAreas();
	expectedVec = { {3,3}, {5,5} };
	assert(result == expectedVec);

	vec = { 9, 7, 3, 4, 5, 2,8,1 };
	cbs = CanBeSortedCheck(vec);
	result = cbs.getNotSortedAreas();
	expectedVec = { { 0,1 },{ 5,5 }, {7,7} };
	assert(result == expectedVec);

	vec = { 9, 2, 3, 4, 5, 7, 8, 1 };
	cbs = CanBeSortedCheck(vec);
	result = cbs.getNotSortedAreas();
	expectedVec = { { 0,0 },{ 7,7 } };
	assert(result == expectedVec);

	vec = { 7, 6, 5, 4, 3, 2, 1 };
	cbs = CanBeSortedCheck(vec);
	result = cbs.getNotSortedAreas();
	expectedVec = { { 0,2 }, {4,6} };
	assert(result == expectedVec);

	cout << "test GetNotSortedAreas ok!" << endl;
}

void testSwap() {
	vector<int> vec = { 1,2,3 };
	size_t idx1 = 0, idx2 = 1;
	CanBeSortedCheck  cbs(vec);
	vector<int> expected = { 2,1,3 };
	cbs.swap(idx1, idx2);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3 };
	idx1 = 1, idx2 = 2;
	cbs = CanBeSortedCheck(vec);
	expected = { 1,3,2 };
	cbs.swap(idx1, idx2);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3, 4 };
	idx1 = 1, idx2 = 4;
	expected = { 1,2,3, 4 };
	cbs = CanBeSortedCheck(vec);
	cbs.swap(idx1, idx2);
	assert(cbs.getNotSorted() == expected);

	cout << "test swap ok!" << endl;
}
void testReverse() {
	vector<int > vec = { 1,2,3,4 };
	size_t beg = 0, end = 3;
	vector<int> expected = { 4,3,2,1 };
	CanBeSortedCheck  cbs(vec);
	cbs.reverse(beg, end);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3,4,5,6,7 };
	cbs = CanBeSortedCheck(vec);
	beg = 2, end = 5;
	expected = { 1,2,6,5,4,3,7 };
	cbs.reverse(beg, end);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3,4,5,6,7 };
	cbs = CanBeSortedCheck(vec);
	beg = 2, end = 6;
	expected = { 1,2,7,6,5,4,3 };
	cbs.reverse(beg, end);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3,4,5,6,7 };
	cbs = CanBeSortedCheck(vec);
	beg = 6, end = 2;
	expected = { 1,2,7,6,5,4,3 };
	cbs.reverse(beg, end);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3,4,5,6,7 };
	cbs = CanBeSortedCheck(vec);
	beg = 2, end = 7;
	expected = { 1,2,3,4,5,6,7 };
	cbs.reverse(beg, end);
	assert(cbs.getNotSorted() == expected);

	vec = { 1,2,3,4,5,6,7 };
	cbs = CanBeSortedCheck(vec);
	beg = 3, end = 3;
	expected = { 1,2,3,4,5,6,7 };
	cbs.reverse(beg, end);
	assert(cbs.getNotSorted() == expected);

	cout << "test reverse ok!" << endl;
}

void testIsSorted() {
	vector<int> vec = { 1,2,5,6,8 };
	CanBeSortedCheck  cbs(vec);
	size_t idx1 = 0, idx2 = 4;
	bool actual = cbs.isSorted(idx1, idx2);
	bool expected = true;
	assert(actual == expected);

	vec = { 1,2,5,8,6 };
	cbs = CanBeSortedCheck(vec);
	idx1 = 0, idx2 = 4;
	actual = cbs.isSorted(idx1, idx2);
	expected = false;
	assert(actual == expected);

	vec = { 1,2,5,8,6 };
	cbs = CanBeSortedCheck(vec);
	idx1 = 0, idx2 = 3;
	actual = cbs.isSorted(idx1, idx2);
	expected = false;
	assert(actual == expected);


	vec = { 1,2,5,8,6 };
	cbs = CanBeSortedCheck(vec);
	idx1 = 3, idx2 = 0;
	actual = cbs.isSorted(idx1, idx2);
	expected = false;
	assert(actual == expected);

	vec = { 1,5,2,6,8 };
	cbs = CanBeSortedCheck(vec);
	idx1 = 2, idx2 = 0;
	actual = cbs.isSorted(idx1, idx2);
	expected = false;
	assert(actual == expected);

	cout << "test isSorted ok!" << endl;
}