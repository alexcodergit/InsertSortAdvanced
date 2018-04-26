#pragma once
#include<vector>

size_t countMovesIterate(const std::vector<size_t> & vec) {
	size_t moves = 0;
	for (size_t i = 1; i < vec.size(); i++) {
		for (size_t j = 0; j < i; j++) {
			if (vec[i] < vec[j])
				moves++;
		}
	}
	return moves;
}
