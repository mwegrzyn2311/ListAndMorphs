#ifndef INTERNHIPEXERCISES_SELFORGANIZINGLIST_HPP
#define INTERNHIPEXERCISES_SELFORGANIZINGLIST_HPP

#include <memory>
#include <utility>

// Template to enable the list to keep any type
template<typename T>
class SelfOrganizingList {
	struct Node {
		T val;
		int usageCount = 0;
		std::shared_ptr<Node> next = nullptr;
	public:
		explicit Node(T val) : val(val) {}
	};
	// I keep tail to decrease add() method complexity from O(n) to (1)
	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;
public:
	SelfOrganizingList(): head(nullptr), tail(nullptr) {}
	void add(T val);
	T get(T val);
	void print();

	// Iterator for the list for std algorithms to work
	/** Iterator */
	struct Iterator {
		typedef Iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
	public:
		Node* node;
		explicit Iterator(Node* node): node(node) {
		}

		reference operator*() const { return node->val; }
		pointer operator->() const { return &(node->val); }
		self_type& operator++() {
			node = node->next.get();
			return *this;
		}
		self_type operator++(int) {
			auto res = *this;
			node = node->next.get();
			return res;
		}
		bool operator==(const Iterator& other) const { return this->node == other.node; }
		bool operator!=(const Iterator& other) const { return this->node != other.node; }

		friend class SelfOrganizingList;
	};

	Iterator begin() { return Iterator(head.get()); }
	Iterator end() { return Iterator(nullptr); }
};

// Creates a new node and appends it to the back of the list
template<typename T>
void SelfOrganizingList<T>::add(T val) {
	auto newNode = std::make_shared<Node>(val);
	if(!head) {
		head = std::move(newNode);
		tail = head;
	} else {
		tail->next = std::move(newNode);
		tail = tail->next;
	}
}
template<typename T>
void SelfOrganizingList<T>::print() {
	for(const auto& it : *this) {
		std::cout<<it<<" - ";
	}
	std::cout<<std::endl<<"-------------------------------------"<<std::endl;
}

// Returns first element with value equal to function argument
template<typename T>
T SelfOrganizingList<T>::get(T val) {
	// Find element we want to return
	auto ret = std::find_if(begin(), end(), [val](T curr) {
		return val == curr;
	});

	// Find first element with same usage as it had before get() was called. In this way we swap first and last element of the block of nodes with same usage count
	int& usage = (ret.node->usageCount);
	auto prev = begin();
	for(; prev != end() && prev.node->usageCount > usage; ++prev);

	// Swap, increment and return (we return prev instead of ret because we used std::iter_swap)
	std::iter_swap(ret, prev);
	++usage;
	return *prev;
}

#endif //INTERNHIPEXERCISES_SELFORGANIZINGLIST_HPP
