#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<time.h>
using namespace std;

map<int,int> create_and_init_map(int nrow){
    map<int, int> m;
    for(int i=0;i<nrow;i++)
        m.insert(pair<int,int>(i,0));//all column index are 0 initially
    return m;
}

vector<int> print_sorted_mat(int **mat, int nrow, int ncol){
    int done=0;
	vector<int> ret_vector;
    map<int,int> m = create_and_init_map(nrow);
    while(!done){
        int min=INT_MAX;
        for(int j=0;j<nrow;j++){
            if(m.find(j)!=m.end() && mat[j][m[j]]<min)
            {
                min=mat[j][m[j]];
            }
        }

        
        //update map
        for(int j=0;j<nrow;j++){
            if(m.find(j)!=m.end() && mat[j][m[j]]==min)
            {
                //int indx=m.find(j);
				int indx = m[j];
                m.erase(j);
				ret_vector.push_back(min);
                if(indx+1<ncol)
                    m.insert(pair<int,int>(j,indx+1));
            }
        }
        
        //check if done
        for(int x=0;x<nrow;x++){
            done =1 ;
            if(m.find(x)!=m.end()){
                done=0;
                break;
            }
        }        
    }
	return ret_vector;
}
//CREATING RANDOM MATRIX
void PopulateMatrix(int **a, int nr, int nc){
	srand(time(nullptr));//TIME - #include<time.h>
	for (auto i = 0; i < nr; i++){
		a[i][0] = rand() % 100;
		for (auto j = 1; j < nc; j++){
			a[i][j] = a[i][j - 1] + 10;
		}
	}
}

void PrintMatrix(int**a, int nr, int nc){
	for (auto i = 0; i < nr; i++){
		for (auto j = 0; j < nc; j++){
			cout << a[i][j] << "\t";
		}
		cout << "\n";
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

int main(){
	int **m, nrow, ncol;
	//creating temp matrix
	nrow = 5;
	ncol = 5;
	m = RandomMatrix(nrow, ncol);
	PrintMatrix(m, nrow, ncol);
	vector<int> v = print_sorted_mat(m, nrow, ncol);
	cout << "Size of vector returned:" << v.size() << endl;
	for (auto &a : v)
		cout << a << " ";
	cout << endl;
}