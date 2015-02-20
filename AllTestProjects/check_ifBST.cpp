#include<iostream>
using namespace std;

class node{
public:
	int val;
	node * left;
	node * right;
};

node * head;

node * createNode(int val){
	node * temp = new node;
	temp->val = val; 
	temp->left = temp->right = nullptr;
	return temp;
}

bool checkBST(node *nd){
	if (nd == nullptr)
		return true;
	if (nd->left == nullptr){
		if (nd->right == nullptr){
			return true;
		}
		else{
			if (nd->val > nd->right->val)
				return false;
			else
				return checkBST(nd->right);
		}
	} 
	else if (nd->right == nullptr){
		if (nd->left == nullptr){
			return true;
		}
		else{
			if (nd->left->val > nd->val)
				return false;
			else 
				return checkBST(nd->left);
		}
	}
	else{
		if (nd->val < nd->left->val || nd->right->val < nd->val)
			return false;
		else
			return (checkBST(nd->left) && checkBST(nd->right));
	}
}


int main(){
	head = createNode(15);
	head->left = createNode(10);
	head->right = createNode(20);
	head->left->right = createNode(12);
	head->right->right = createNode(24);
	head->right->right->left = createNode(26);
	cout << checkBST(head) << endl;

}