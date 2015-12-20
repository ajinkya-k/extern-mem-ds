#define DEGEREE_DEFAULT 3

template <typename K, typename V>
struct item{
	const K key;
	V value;
};

template <typename K>
class B+TreeNode{
private:
	int degree;
public:
	B+TreeNode **B+TreeNode;
	K ** keylist;


};

template <typename K>
class B+TreeInternalNode : B+TreeNode{
public:
	void add(const K& addKey);
};

template <typename K, typename V>
class B+TreeInternalNode : B+TreeNode{
private:
	item ** itemList;
public:
	void add(const item<K,V>&);
};

template <typename K, typename V>
class B+Tree{
private:
	int degree;
	B+TreeNode<K,V> *root;

public:
	B+Tree(): root(nullptr), degree(DEGEREE_DEFAULT) {};
	B+Tree(int deg): root(nullptr), degree(n){};
}