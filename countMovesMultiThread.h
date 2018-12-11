#pragma once
#include<thread>
#include<vector>
#include<future>

size_t countMovesWithIdx(const std::vector<size_t> & vec, const size_t idx1, const size_t idx2) {
	size_t moves = 0;
	for (size_t i = idx1; i < idx2; i++) {
		for (size_t j = 0; j < i; j++) {
			if (vec[i] < vec[j])
				moves++;
		}
	}
	return moves;
}


size_t countMovesMultiThread(const std::vector<size_t> & vec) {
	size_t moves1 = 0, moves2 = 0;
	size_t idx1 = 0, idx2 = (vec.size() / 3) * 2, idx3 = vec.size();
	auto fut1 = std::async(countMovesWithIdx, vec, idx1, idx2);
	auto fut2 = std::async(countMovesWithIdx, vec, idx2, idx3);
	moves1 = fut1.get();
	moves2 = fut2.get();
	return moves1 + moves2;
}