#pragma once
#include<map>
#include<vector>

struct compPair {
	inline bool operator()(const std::pair<size_t, size_t> & p1, const std::pair<size_t, size_t> & p2) const {
		return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
	}
};


std::map<std::pair<size_t, size_t>, size_t, compPair> pairMap;

size_t countMovesGlobalMap(std::vector<size_t> & vec) {
	size_t moves = 0;
	for (size_t i = 1; i < vec.size(); i++) {
		moves += pairMap[{vec[i], i}];
	}
	return moves;
}