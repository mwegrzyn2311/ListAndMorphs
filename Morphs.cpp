#include "Morphs.hpp"

void inline morphs::swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void inline morphs::insertMinFront(std::array<int, 4>& indices, const std::vector<float>& weights) {
	int min = 0;
	for(size_t i = 1; i < 4; ++i) {
		if(weights[indices[i]] < weights[indices[min]]) {
			min = i;
		}
	}
	if(indices[min] != indices[0]) {
		swap(indices[min], indices[0]);
	}
}

// My concept is: keep the smallest of the biggest at the front, so that comparing is O(1), and if a greater value is found,
// it can be pushed front, and then instead of sorting the array (O(n*log(n)) I only push the smallest of the greatest towards the front with is only O(n)
std::array<int, 4> morphs::pickMorphs(const std::vector<float>& weights) {
	// Fill array with starting values: 1, 2, 3, 4 for each existing element and -1 to each non-existing element
	std::array<int, 4> res{};
	std::fill(res.begin(), res.end(), -1);
	size_t i = 0;
	for(; i < weights.size() && i < 4; ++i) {
		res[i] = i;
	}
	if(i != 4) {
		for(; i < 4; ++i) {
			res[i] = -1;
		}
		return res;
	}

	insertMinFront(res, weights);
	for(; i < weights.size(); ++i) {
		if(weights[i] > weights[res[0]]) {
			res[0] = i;
			insertMinFront(res, weights);
		}
	}
	return res;
}
