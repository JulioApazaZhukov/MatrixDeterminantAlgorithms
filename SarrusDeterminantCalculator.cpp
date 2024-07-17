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

void printExtendedMatrix(int matrix[3][5]){
    for (int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] < 10) {
				cout << "0" << matrix[i][j] << " ";
			} else { cout << matrix[i][j] << " "; }
		}
		cout << endl;
	}
}

// function to increase the number of columns of the matrix to be able to apply the Sarrus algorithm
int extendMatrix(int matrix[3][3], int I, int J){
	int extendedMatrix[3][5];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			extendedMatrix[i][j] = matrix[i][j];
		}
	}
	extendedMatrix[0][3] = matrix[0][0];
	extendedMatrix[1][3] = matrix[1][0];
	extendedMatrix[2][3] = matrix[2][0];
	extendedMatrix[0][4] = matrix[0][1];
	extendedMatrix[1][4] = matrix[1][1];
	extendedMatrix[2][4] = matrix[2][1];
	//printExtendedMatrix(extendedMatrix);
	/*for (int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++) {
			return extendedMatrix[i][j];
		}
	}*/
	return extendedMatrix[I][J];
}

int sarrusAlgorithm(int matrix[3][5]){
	int determinant = 0;
	for (int n = 0; n < 3; n++){
		int i = 0;
		int j = n;
		int positiveDiagonalProduct = 1;
		//cout << endl << positiveDiagonalProduct << endl;
		cout << i << " " << j << " | ";
		for (i = 0; i < 3; i++){
			positiveDiagonalProduct = positiveDiagonalProduct * matrix[i][j];
			cout << i << " " << j << " | ";
			j++;
		}
		cout << endl << positiveDiagonalProduct << endl;
		cout << endl;
		determinant += positiveDiagonalProduct;
	}
	for (int n = 0; n < 3; n++){
		int i = 0;
		int j = 2 + n;
		int negativeDiagonalProduct = 1;
		//cout << endl << negativeDiagonalProduct << endl;
		cout << i << " " << j << " | ";
		for (i = 0; i < 3; i++){
			//i = 0;
			cout << i << " " << j << " | ";
			negativeDiagonalProduct = negativeDiagonalProduct * matrix[i][j];
			j--;
		}
		cout << endl << negativeDiagonalProduct << endl;
		determinant -= negativeDiagonalProduct;
	}
	return determinant;
}

int main(){
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
	int a = 0, b = 0;
	//cout << matrix[0][2]; == 3
	//cout << matrix[2][0]; == 7
    
	printMatrix(matrix);
	cout << endl;

	int ExtendedMatrix[3][5];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++) {
			ExtendedMatrix[i][j] = extendMatrix(matrix, i, j);
		}
	}

	printExtendedMatrix(ExtendedMatrix);
	//cout << endl << ExtendedMatrix[0][0] << endl;
	cout << sarrusAlgorithm(ExtendedMatrix);

    return 0;
}