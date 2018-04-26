#pragma once
#include<vector>
#include<map>
#include<set>

size_t countMovesLocalMap(const std::vector<size_t> & vec) {
	std::multimap<size_t, std::multiset<size_t>> mmap;
	for (size_t i = 0; i < vec.size(); i++) {
		auto pos = mmap.find(vec[i]);
		if (pos == mmap.end())
			mmap.insert(std::pair<size_t, std::multiset<size_t>>(vec[i], { i }));
		else
			pos->second.insert(i);
	}
	size_t moves = 0;
	for (size_t i = 1; i < vec.size(); i++) {
		auto pos = std::next(mmap.find(vec[i]));
		while (pos != mmap.end()) {
			auto pos2 = pos->second.lower_bound(i);
			moves += std::distance(pos->second.begin(), pos2);
			pos = std::next(pos);
		}
	}
	return moves;
}

/*
size_t countMovesLocalMap(std::vector<size_t> & vec) {
	std::multimap<size_t, std::vector<size_t>> mmap;
	for (size_t i = 0; i < vec.size(); i++) {
		auto pos = mmap.find(vec[i]);
		if (pos == mmap.end())
			mmap.insert(std::pair<size_t, std::vector<size_t>>(vec[i], { i }));
		else
			pos->second.push_back(i);
	}
	size_t moves = 0;
	for (size_t i = 1; i < vec.size(); i++) {
		auto pos = std::next(mmap.find(vec[i]));
		while (pos != mmap.end()) {
			for (size_t j : pos->second) {
				if (j < i)
					moves++;
				else
					break;
			}
			pos = std::next(pos);
		}
	}
	return moves;
}
*/