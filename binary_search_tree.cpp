#include <iostream>
using namespace std;

template<typename T>
class binary_tree{
	private:
		struct node{
			T value;
			node *left;
			node *right;
			node *parent;
		};

		node *root;

	public:	
		binary_tree(){
			root = NULL;
		}

		node * make_node(T val){
			node *new_node = new node;
			new_node->value  = val;
			new_node->left   = NULL;
			new_node->right  = NULL;
			new_node->parent = NULL;
			return new_node;
		}

		void insert(T val){
			node *new_node = make_node(val);
			node *head = root;
			node *parent = head;
			int flag = -1;
			if(root == NULL){
				root = new_node;
				return;
			}

			while(head != NULL){
				parent = head;

				if(head->value == val){
					cout << "Item already present" <<endl;
					return;
				}
				else if(head->value < val){
					head = head->right;
					flag = 1;
				}

				else {
					head = head->left;
					flag = 0;
				}
			}

			head = new_node;
			head->parent = parent;

			if(flag == 0){
				parent->left = head;
			}

			if(flag == 1){
				parent->right = head;
			}
		}

		node* search(T search_val){
			node *head = root;
			while(head != NULL){
				if(head->value == search_val){
					std::cout << "Found " << search_val <<endl;
					return head;
				}

				else if(head->value < search_val)
					head = head->right;
				else
					head = head->left;


			}

			std::cout << "Requested item not found" << endl;
			return NULL;
		}
};

int main(void){
	//binary_tree<int> *bt = new binary_tree<int>();


	binary_tree<float> *bt = new binary_tree<float>();


	bt->insert(5.3);
	bt->insert(2.3);
	bt->insert(2.2);

	bt->search(3.5);
	bt->search(2.2);
}