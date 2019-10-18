#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;

/*
 Caclulates the total number of intersections of two sets of 
  one dimensional intervals. Two intervals are intersecting 
  when they have at least one common point. For example
  [1,3] and [4,8] do NOT intersect, but [2,4] and [4,8] DO intersect.
  The intervals are closed, that means they include both ends.
  In the picture below the ends of intervals are shown as vertical lines.
  Here we have 4 intersections: the first interval shown in lower row intersects
  with first and second interval in upper row, the second interval in lower row 
  intersects with secod interval in upper row, and the last interval in lower row
  intersects (contains) the last interval in upper row.
  |---|  |----|  |-------|
      |---| |-| |---------|
  The intervals are represented as vectors with two elements: the left and the right 
  border of the interval.
  The function calculates the total number of intersections in O(n*log(n)) time, 
  where n is the total number of intervals in iset1 and iset2.

  The method creates an extra copy of one of the first interval array and sorts it 
  based on the interval ends increasing. The original copy of the array based on their 
  begins, increasing. In the final loop the method iterates each element (interval)
  of the second array. In the first (lower_bound) binary search function finds the interval lb 
  that points to the last interval int iarr1 which end is less then the begin of the currentInterval
  in the loop. In second (upper_bound) binary search function finds the first interval in sortedBegins  
  which begin is to the right of the end point of the currentInterval. 
  So, all the intervals from iarr1.begin() to lb  plus all the intervals from up to the sortedBegins.end()
  do not intersect with the current interval currentInterval. All others do intersect.
  Because the sortedBegins is a copy of iarr1,  the total intersections for the  currentInterval 
  is iarr1.size() - (std::distance(iarr1.begin(), lb) + std::distance(ub, sortedBegins.end()));
*/

int  totalIntersections(vector<vector<int>> iarr1, vector<vector<int>> iarr2)
{
	int totalSum = 0;
	vector<vector<int>> sortedBegins = iarr1;

	std::sort(sortedBegins.begin(), sortedBegins.end(), [](const vector<int>& sb1, const vector<int>& sb2) {
		return (sb1[0] < sb2[0]);  });

	std::sort(iarr1.begin(), iarr1.end(), [](const vector<int>& se1, const vector<int>& se2) {
		return (se1[1] < se2[1]);  });
	
	for (auto& currentInterval : iarr2) {

		auto lb = std::lower_bound(iarr1.begin(), iarr1.end(), currentInterval[0],
			[](const vector<int>& is, int x) { return is[1] < x; });

		auto ub = std::upper_bound(sortedBegins.begin(), sortedBegins.end(), currentInterval[1],
			[](int x, const vector<int>& is) { return is[0] > x; });

		totalSum += iarr1.size() - (std::distance(iarr1.begin(), lb) + std::distance(ub, sortedBegins.end()));
	}
	return totalSum;
}

int main()
{
	vector<vector<int>> iarr1 = { {1, 2}, {2,3}, {4,5}, {6,7} };
	vector<vector<int>> iarr2 = { {1,5}, {2,3}, {4,7}, {5,7} };
	int total = totalIntersections(iarr1, iarr2);
	assert(total == 9);
}