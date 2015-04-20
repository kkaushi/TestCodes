#include<iostream>
#include<vector>
using namespace std;

int mat[5][5] = { { 1, 2, 2, 3, 5 }, { 3, 2, 3, 4, 4 }, { 2, 4, 5, 3, 1, }, { 6, 7, 1, 4, 5 }, { 5, 1, 1, 2, 4 } };

bool path_to_topLeft(int i, int j){
	bool flag_l, flag_t;
	if (i == 0 || j == 0)
		return true;
	if (i - 1 >= 0 && mat[i - 1][j] <= mat[i][j])
		flag_l = path_to_topLeft(i - 1, j);
	else
		flag_l = false;

	if (j - 1 >= 0 && mat[i][j - 1] <= mat[i][j])
		flag_t = path_to_topLeft(i, j - 1);
	else
		flag_t = false;

	return (flag_t || flag_l);

}

bool path_to_bottomRight(int i, int j){
	bool flag_r, flag_b;
	if (i == 4 || j == 4)
		return true;
	if (i + 1 <= 4 && mat[i + 1][j] <= mat[i][j])
		flag_r = path_to_bottomRight(i + 1, j);
	else
		flag_r = false;

	if (j + 1 <= 4 && mat[i][j + 1] <= mat[i][j])
		flag_b = path_to_bottomRight(i, j + 1);
	else
		flag_b = false;

	return (flag_r || flag_b);

}

vector<pair<int, int>> find_continentDivide(int mat[5][5], int nr, int nc){
	vector<pair<int, int>> vec;
	for (int i = 0; i<nr; i++){
		for (int j = 0; j<nc; j++){
			if(path_to_topLeft(i,j) && path_to_bottomRight(i,j)){
			//if (path_to_topLeft(i, j)){
				vec.push_back(pair<int, int>(i, j));
			}
		}
	}
	return vec;
}

int main(){
	vector<pair<int, int>> pts = find_continentDivide(mat, 5, 5);
	for (auto &a : pts)
		cout << a.first << "," << a.second << endl;
}