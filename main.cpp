#include <iostream>
#include <vector>

#include "Morphs.hpp"
#include "SelfOrganizingList.hpp"

int main() {
	std::vector<float> weights = {0.2f, 0.5f, 0.0f, 1.0f, 0.1f, 0.4f, 0.8f, 0.9f, 1.0f};
	auto res = morphs::pickMorphs(weights);
	for(const auto& ele : res) {
		std::cout<<ele<<std::endl;
	}

	std::cout<<"----------------------------------------"<<std::endl;

	SelfOrganizingList<int> list;
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.print();
	std::cout<<"Got "<<list.get(2)<<std::endl;
	std::cout<<"Got "<<list.get(2)<<std::endl;
	std::cout<<"Got "<<list.get(3)<<std::endl;
	std::cout<<"Got "<<list.get(3)<<std::endl;
	std::cout<<"Got "<<list.get(3)<<std::endl;
	list.print();
	return 0;
}
