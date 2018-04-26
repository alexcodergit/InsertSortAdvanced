#pragma once

#include<vector>
#include<algorithm>
#include<set>

size_t countMovesMSetSorted(const std::vector<size_t> & vec) {
	size_t moves = 0;
	std::multiset<size_t> sorted;
	auto pos = sorted.insert(vec[0]);
	for (size_t i = 1; i < vec.size(); i++) {
		pos = sorted.insert(vec[i]);
		moves += (std::distance(pos, sorted.end()) - 1);
	}
	return moves;
}