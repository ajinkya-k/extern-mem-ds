#include <iostream>
#include <cstddef>
#include <functional>
using namespace std;

template <typename K, typename V>
struct node<K,V>{
	K key;
	V value;
	node<K,V> *left;
	node<K,V> *right;
	node<K,V> *parent;
};

template<typename K, typename V>
class binary_search_tree{
private:



	node<K,V> *root;

public:	
	binary_search_tree(){
		root = nullptr;
	}

	node<K,V> * make_node<K,V>(T val);
	void insert(const K& key, const V& val);
	node<K,V>* search(const K& search_key);
	node<K,V>* remove(const K& key);

};


template <typename K, typename V>
node<K,V> * binary_search_tree<K, V>::make_node<K,V>(const K& key, const V& val){
	node<K,V> *new_node<K,V> = new node<K,V>;
	new_node<K,V>->key = key;
	new_node<K,V>->value  = val;
	new_node<K,V>->left   = nullptr;
	new_node<K,V>->right  = nullptr;
	new_node<K,V>->parent = nullptr;
	return new_node<K,V>;
}


template <typename K, typename V>
void binary_search_tree<K,V>::insert(const& K key, V val){
	node<K,V> *new_node<K,V> = make_node<K,V>(val);
	node<K,V> *head = root;
	node<K,V> *parent = head;
	int flag = -1;
	if(root == nullptr){
		root = new_node<K,V>;
		return;
	}

	while(head != nullptr){
		parent = head;

		if(head->key == key){
			cout << "Item already present" <<endl;
			return;
		}
		else if(head->key < key){
			head = head->right;
			flag = 1;
		}

		else {
			head = head->left;
			flag = 0;
		}
	}

	head = new_node<K,V>;
	head->parent = parent;

	if(flag == 0){
		parent->left = head;
	}

	if(flag == 1){
		parent->right = head;
	}
}


template <typename K, typename V>
node<K,V>* binary_search_tree<K,V>::search(const &K search_key){
	node<K,V> *head = root;
	while(head != nullptr){
		if(head->key == search_key){
			std::cout << "Found " << search_key <<endl;
			return head;
		}

		else if(head->key < search_key)
			head = head->right;
		else
			head = head->left;
	}

	std::cout << "Requested item not found" << endl;
	return nullptr;
}


template <typename K, typename V>
node<K,V> * binary_search_tree<K,V>::remove(const K& remove_key){
	node<K,V> * head =  root;
	node<K,V> * parent, leftc, rightc;
	node<K,V>* to_remove = search(const	K& remove_key);

	if(to_remove == nullptr){
		return nullptr;
	}

	parent = to_remove->parent;
	leftc  = to_remove->left;
	rightc = to_remove->right;

	if(leftc == nullptr){
		if(to_remove==parent->left)
			parent->left  = rightc;
		else
			parent->right = rightc;
	}
	else if(rightc == nullptr){
		if(to_remove==parent->left)
			parent->left  = leftc;
		else
			parent->right = leftc;
	}
}


int main(void){
	//binary_search_tree<int> *bt = new binary_search_tree<int>();
	binary_search_tree<float> *bt = new binary_search_tree<float>();

	bt->insert(5.3);
	bt->insert(2.3);
	bt->insert(2.2);

	bt->search(3.5);
	bt->search(2.2);
}