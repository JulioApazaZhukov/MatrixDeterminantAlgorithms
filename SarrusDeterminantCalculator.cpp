#include <iostream>

//using std::cin;
using std::cout;
using std::endl;

void printMatrix(int matrix[3][3]){
    for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] < 10) {
				cout << "0" << matrix[i][j] << " ";
			} else { cout << matrix[i][j] << " "; }
		}
		cout << endl;
	}
}

void calculateDeterminant(int matrix[3][3]){
	int product = 0, i = 0, j = 0;
	product = matrix[i][j];
    for (i = 0; i < 3; i++){
		product *= matrix[i][j];
		j++;
	}
	cout << product;
}

int main(){
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    
	printMatrix(matrix);
	calculateDeterminant(matrix);

    return 0;
}