/*
Write a program that reverses a linked list without using more than O(1) storage.
*/

#include<iostream>
#include<string>
using namespace std;

struct node{
	int val;
	node * next;
}*start;

//passing node and it's parent
node * reverse_list(node * n, node * parent){
    if(n==nullptr){
        return start;
    }
    
    //last node case
	if (n->next == nullptr){
		start = n;
		n->next = parent;
		return n;
	}
    node * ptr=reverse_list(n->next,n);

    //if not original first node
    if(parent!=nullptr){
        n->next=parent;
    }
    else
    //original first node 
    {
        n->next=nullptr;
    }    
    return ptr;//return new start node       
}

	int main(){
		node three{ 3, nullptr };
		node two{ 2, &three };
		node one{ 1, &two };
		start = &one;
		cout << start->val << "," << start->next->val << ","<<start->next->next->val << endl;
		start = reverse_list(start, nullptr);
		cout << start->val << "," << start->next->val << ","<<start->next->next->val << endl;
		return 0;
	}