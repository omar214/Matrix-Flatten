#include<iostream>
#include <vector>
using namespace std;
typedef vector<vector<vector<int>>> Mat3d; 
typedef vector<int>  Vec1d;

int getIdx(int i, int j, int k, Mat3d& mat) {
	if(mat.empty()) return;
	int n = mat.size(),
		m = mat[0].size(),
		p = mat[0][0].size();
	return i * m * p + j * p + k;
}

void flattenMatrix(Mat3d & mat , Vec1d & vec) {
	if(mat.empty()) return;
	int n = mat.size(),
		m = mat[0].size(),
		p = mat[0][0].size();
	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < m; j++){
			for (size_t k = 0; k < p; k++){
				int idx = getIdx(i, j, k, mat);
				vec[idx] = mat[i][j][k];
			}
		}
	}
}

void readMatrix(Mat3d& mat) {
	int n = mat.size(),
		m = mat[0].size(),
		p = mat[0][0].size();
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < p; k++) {
				cout << "\nenter element at pos " << i + 1 << " " << j + 1 << " " << k + 1 << "\t";
				cin >> mat[i][j][k];
			}
		}
	}
}

void main(void) {
	Mat3d mat;
	Vec1d vec;
	int n, m, p;

	cout << "enter the dimensions of matrix ";
	cin >> n >> m >> p;
	mat.resize(n, vector<vector<int>>(m, vector<int>(p)));
	vec.resize(n * m * p);

	readMatrix(mat);		
	flattenMatrix(mat, vec);		

	cout << "\nthe flattend matrix --> ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\t";
	}
}