#include<iostream>
#include<map>
using namespace std;

int ** create_mat(int n){
	int **mat = new int *[n];
	if (mat == nullptr)
		return nullptr;
	for (int i = 0; i<n; i++){
		mat[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = i + j;
	return mat;
}

int** set_row_zero(int **mat, int n, int i){
	for (int j = 0; j<n; j++)
		mat[i][j] = 0;
	return mat;
}

int **set_col_zero(int **mat, int n, int j){
	for (int i = 0; i<n; i++)
		mat[i][j] = 0;
	return mat;
}

void print_mat(int **mat, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int ** convert_mat(int **mat, int n){
	map<int, int>r_map;
	map<int, int>c_map;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (r_map.find(i) == r_map.end() && r_map.find(j) == r_map.end()){//if row or column is not zero
		if (mat[i][j] == 0){
			r_map.insert(pair<int, int>(i, 1));
			c_map.insert(pair<int, int>(j, 1));
			mat = set_row_zero(mat, n, i);
			mat = set_col_zero(mat, n, j);
		}
	}
	return mat;
}

void free_mat(int **mat, int n){
	for (int i = 0; i<n; i++)
		delete mat[i];

	delete mat;
}

int main(){
	int n = 4;
	int **mat = create_mat(n);//considering square matrix only
	print_mat(mat, n);
	convert_mat(mat, n);
	print_mat(mat, n);
	free_mat(mat, n);
}