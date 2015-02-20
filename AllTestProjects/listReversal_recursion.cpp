#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct node{
	int val;
	node * next;
};

void traverse_list(list<node> l){
	for (auto &a : l)
		cout << a.val << "\t";
	cout << endl;
}

node * recurse_reverse(node ** hd,  node *n, node *nc){
	if (nc->next != nullptr){
		recurse_reverse(hd, nc, nc->next);
		nc->next = n;

	}
	else{
		nc->next = n;
		(*hd)->next = nullptr;
		*hd = nc;
	}		
	return n; 
}

void reverse(node ** ptr){
	if (*ptr == nullptr)
		return;
	else if ((*ptr)->next == nullptr)
		return;
	else
		recurse_reverse(ptr, *ptr, (*ptr)->next);	
}

void main(){
	list<node> l;
	vector<node>v = { { 1, nullptr }, { 2, nullptr }, { 3, nullptr } };
	for (auto &a : v)
		l.push_back(a);
	traverse_list(l);

	node * head = &l.front();
	
	//error here as head->next wont give next node
	//cout << head->val << "\t"<<head->next->val<<"\t"<<head->next->next->val<<endl;


	// no I am initializing other nodes to create a list
	//ignore the implementation
	//head->next = l.front().next;
	//head->next->next = l.front().next->next;

	node * a = new node;
	node * b = new node;
	node * c = new node;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	a->next = b->next = c->next = nullptr;
	head = a;
	a->next = b;
	b->next = c;

	//calling reverse method
	reverse(&head);


}