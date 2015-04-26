#include<iostream>
#include<random>
#include<time.h>
using namespace std;

void PrintMatrix(int**a, int nr, int nc){
	for (auto i = 0; i < nr; i++){
		for (auto j = 0; j < nc; j++){
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}

void PopulateMatrix(int **a, int nr, int nc){
	srand(time(nullptr));
	for (auto i = 0; i < nr; i++){
		for (auto j = 0; j < nc; j++){
			a[i][j] = (rand() % 2) == 0 ? 0 : 1;
		}
	}
}

int** RandomMatrix(int nr, int nc){
	int **a = new int*[nr];
	for (auto i = 0; i < nr; i++){
		a[i] = new int[nc];
	}
	PopulateMatrix(a, nr, nc);
	return a;
}

void FreeMatrix(int **a, int nr, int nc){
	for (auto i = 0; i < nr; i++){
		delete(a[i]); 
	}
	delete(a);
}

int CheckBound(int nr, int nc, int x, int y){
	return (x < 0 || x >= nr || y < 0 || y >= nc) ? 0 : 1;
}

void Paintfill(int **a, int nr, int nc, int x, int y, int c){
	if (!CheckBound(nr, nc, x, y) || a[x][y]==c)
		return;
	a[x][y] = c;
	Paintfill(a, nr, nc, x - 1, y, c);
	Paintfill(a, nr, nc, x + 1, y, c);
	Paintfill(a, nr, nc, x , y - 1, c);
	Paintfill(a, nr, nc, x , y + 1, c);
	return;
}


void main(){
	int **a, nr = 8, nc = 8;
	cout << "Hi this is visual studio 2013! excited!\n";
	a=RandomMatrix(nr, nc);
	PrintMatrix(a, nr, nc);
	Paintfill(a, nr, nc, 1, 1, 4);
	cout << "Matrix after PaintFill() is:\n";
	PrintMatrix(a, nr, nc);
	FreeMatrix(a, nr, nc);
	cout << "IT's done!!\n";
}