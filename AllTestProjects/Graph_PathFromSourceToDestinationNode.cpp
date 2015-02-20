#include<iostream>
#include<list>
using namespace std;

#define nNodes 4
#define p(c) cout<<c<<endl;

class Graph{
	int V;
	list<int> * pAList;
public:
	list<int> * getpAList(){ return pAList; }
	Graph(int n) :V{ n }, pAList{ new list<int>[n] }{}
	bool isPath(int s, int d);
	int retPath(int s, int d);
	int dfs(int s, int d, bool[]);
};

bool Graph::isPath(int s, int d) {
	//initialized visited array
	bool visited[nNodes];
	for (auto &a : visited)
		a = false;

	//init queue 
	list<int> q;
	visited[s] = true;
	q.push_back(s);

	while (!q.empty()){
		int temp = q.front();//get first q element
		q.pop_front();//pop first element

		if (temp == d)//if destination node
			return true;

		//else push all connected nodes
		list<int>::iterator i;
		//for (i = (getpAList())[temp]->begin(); i != ;)
		for (i = pAList[temp].begin(); i != pAList[temp].end(); i++){
			if (*i == d)
				return true;
			//else push in queue
			if (!visited[*i]){
				visited[*i] = true;
				q.push_back(*i);
			}
		}
	}
	return false;
}

int Graph::dfs(int s, int d, bool visited[nNodes]){
	if (s == d){
		//p(s);
		return 1;
	}
	list<int>::iterator i;
	visited[s] = true;
	for (i = pAList[s].begin(); i != pAList[s].end(); i++){
		if (!visited[*i]){
			//visited[*i] = true;
			if (dfs(*i, d, visited) == true){
				p(*i);
				return 1;
			}
		}
	}
	
}

int Graph::retPath(int s, int d){
	if (s == d){
		p(s);
		return 1;
	}
	else{
		bool visited[nNodes];
		for (auto &a : visited)
			a = false;
		if (dfs(s, d, visited)){
			p(s);
			return 1;
		}
	}
}

int main(){
	Graph g{ 4 };
	
	//edges 0->3, 0->1
	
	(g.getpAList())[0].push_back(3);
	g.getpAList()[0].push_back(1);

	//edge 3->1
	g.getpAList()[3].push_back(1);
	
	//edge 1->2 
	g.getpAList()[1].push_back(2);

	//check if there is a path from 0 to 2
	//cout << g.isPath(3, 2) << endl;
	if (g.isPath(0, 2)){
		g.retPath(0, 2);
	}
}