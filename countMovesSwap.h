#pragma once
#include<vector>
#include<algorithm>

size_t countMovesSwap(std::vector<size_t> & vec) {
	size_t moves = 0;
	std::vector<size_t> sorted = vec;
	std::sort(sorted.begin(), sorted.end());
	while (vec != sorted) {
		for (size_t i = 1; i < vec.size(); i++) {
			if (vec[i - 1] > vec[i]) {
				size_t tmp = vec[i];
				vec[i] = vec[i - 1];
				vec[i - 1] = tmp;
				moves++;
			}
		}
	}
	return moves;
}