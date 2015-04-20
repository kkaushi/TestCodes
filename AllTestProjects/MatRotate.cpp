//Rotate an nXn matrix by 90degree clockwise
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int ** create_mat(int n){
	int **mat = new int *[n];
	if (mat == nullptr)
		return nullptr;
	for(int i=0;i<n;i++){
		mat[i] = new int[n];		
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = i + j;
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

int ** rotate_mat(int **mat,int n){
	int mid = n / 2, lvl = 0;
	while (lvl<mid){
		int start = 0 + lvl, end = n - 1-lvl;
		for (int i = start ; i < end ; i++){
		//for (int i = start; i <=mid; i++){
			int saved_topleft = mat[start][i];
			mat[start][i] = mat[end - i + start][start];
			mat[end - i + start][start] = mat[end][end - i + start];
			mat[end][end - i + start] = mat[i][end];
			mat[i][end] = saved_topleft;
		}
		lvl++;
	}
	return mat;
}

int main(){
	int n;
	cout << "Enter n:";
	cin >> n;

	int **mat = create_mat(n);
	print_mat(mat, n);
	cout << endl;
	mat=rotate_mat(mat,n);
	print_mat(mat, n);
}