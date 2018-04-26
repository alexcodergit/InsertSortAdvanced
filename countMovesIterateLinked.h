#pragma once
#include<map>
#include<vector>

size_t countMovesIterateLinked(const std::vector<size_t> & vec) {
	std::map<size_t, size_t> lmap;
	size_t minSoFar = vec[0];
	lmap[0] = minSoFar;
	for (size_t i = 1; i < vec.size(); i++) {
		if (vec[i] < minSoFar) {
			minSoFar = vec[i];
			lmap[i] = minSoFar;
		}
		else {
			lmap[i] = lmap[i - 1];
		}
	}
	size_t moves = 0;
	for (size_t i = 1; i < vec.size(); i++) {
		if (vec[i] < lmap[i]) {
			moves += i + 1;
		}
		else {
			for (size_t j = 0; j < i; j++) {
				if (vec[i] < vec[j])
					moves++;
			}
		}
	}
	return moves;
}