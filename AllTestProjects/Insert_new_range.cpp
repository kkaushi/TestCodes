/*
Given a class Range

class Range {
    public int begin;
    public int end;
    public Range(int begin, int end) {
        this.begin = begin;
        this.end = end;
    }
}
The problem: 
Intput: 
1) list of Ranges that don't overlap (not sorted) 
2) newRange that might overlap. 
Output: 
list of merged Ranges 

For example: 
Input: [1..5] [9..13] [17..22] 
newRange: [4..10] 
Output: [1..13] [17..22]

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class range{
    public:
        int begin;
        int end;
        range(int b, int e){
            begin=b;
            end=e;
        }
};

void sort_them(vector<range>&sorted, range new_r){
	vector<range>newvector;
	if (sorted.size() == 0){
		sorted.push_back(new_r);
		return;
	}

    for(int i=0;i<sorted.size();i++){
        //if new_r is within an existing range
        if(new_r.begin>=sorted[i].begin && new_r.end<=sorted[i].end)
            return;//already inside an existing range. Don't do anything here

        //if some range in vector is within new_r
        if(sorted[i].begin>=new_r.begin && sorted[i].end<=new_r.end){
            sorted.erase(sorted.begin()+i);//remove from original vector as this range is within new range
            i--;//reset vector traversal index for loop to account for removed item
        }

        //if partially overlap : only begin is overlapping
        if(new_r.begin>=sorted[i].begin && new_r.begin<=sorted[i].end && new_r.end>sorted[i].end){
            new_r.begin=sorted[i].begin;//change begin of new range
			new_r.end = max(new_r.end, sorted[i].end);
            sorted.erase(sorted.begin()+i);
            newvector.push_back(new_r);
			i--;
        }
        //else if partially overlap : only end part is overlapping
        else if(new_r.begin<sorted[i].begin && new_r.end>=sorted[i].begin && new_r.end<=sorted[i].end){
            new_r.end=sorted[i].end;
			new_r.begin = min(new_r.begin, sorted[i].begin);
            sorted.erase(sorted.begin()+i);
            newvector.push_back(new_r);
			i--;
        }
    }

	int min=INT_MAX, max=INT_MIN;
	for (auto &b : newvector){
		if (min>b.begin)
			min = b.begin;
		if (max < b.end)
			max = b.end;
	}
	if (newvector.size()!=0)
		sorted.push_back({ min, max });    
}

int main(){
	vector<range> r{ { 1, 4 }, { 7, 9 }, { 10, 15 } };
	//test cases 
	// 1. no overlap
	sort_them(r, { 5, 6 });
	//2. complete overlap (within 1 range in vector)
	sort_them(r, { 11, 13 });
	//2. b complete overlap (within 2 ranges in vector)
	sort_them(r, { 8, 11 });
	//3. Partial overlap (begin)
	sort_them(r, { 3, 5 });
	//4. Partial overlap(end)
	sort_them(r, { 6, 12 });
	//5. empty ranges (vector or new range)
	vector<range>empty_vec;
	sort_them(empty_vec, { 1, 4 });	
	
}