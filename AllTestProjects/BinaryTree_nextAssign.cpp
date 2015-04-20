#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

struct node{
    int val;
    node *l,*r,*next;
};

struct qnode{
    node * n;
    int lvl;
};

node * createNode(int val){
    node * n = new node();
	if (n != NULL){
        n->val=val;
        n->l=NULL;
        n->r=NULL;
        n->next=NULL;
        return n;            
     }
     else{
         return NULL;
     }
}

void assignNext(node * root){
    vector<qnode> l;
    l.push_back({root,0});
    while(!l.empty()){
        //auto &a = l.pop_front();
		auto a = l.front();
		if (l.size()>1){
			if(a.lvl==l.at(1).lvl)
				a.n->next=l.at(1).n;
		}
		if (a.n->l!=NULL)
			l.push_back({a.n->l,a.lvl+1});
		if (a.n->r!=NULL)
			l.push_back({a.n->r,a.lvl+1});  
		l.erase(l.begin());//see how you delete from front in vector
    }
}

int main(){

    //creating reference tree
    node * root= createNode(1);
    root->l=createNode(2);
    root->r=createNode(3);
    root->l->l=createNode(4);
    root->r->l=createNode(5);
    root->r->r=createNode(6);
    
    //assign next values
    assignNext(root);
	cout << "Done!" << endl;
    
}