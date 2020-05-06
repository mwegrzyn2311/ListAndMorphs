#ifndef INTERNHIPEXERCISES_MORPHS_HPP
#define INTERNHIPEXERCISES_MORPHS_HPP

#include <vector>
#include <array>

namespace morphs {
	void inline swap(int& a, int& b);
	void inline insertMinFront(std::array<int, 4>& indices, const std::vector<float>& weights);
	std::array<int, 4> pickMorphs(const std::vector<float>& weights);
}

#endif //INTERNHIPEXERCISES_MORPHS_HPP
