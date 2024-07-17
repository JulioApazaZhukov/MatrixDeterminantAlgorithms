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
int extendMatrix(int matrix[3][3]){
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
	printExtendedMatrix(extendedMatrix);
	return extendedMatrix[3][5];
}

void sarrusAlgorithm(int matrix[3][5]){
	int positiveDiagonalProducts = 1;
	int j = 0;
    for (int i = 0; i < 3; i++){
		positiveDiagonalProducts *= matrix[i][j];
		j++;
	}
	cout << endl << positiveDiagonalProducts << endl;
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
	//extendMatrix(matrix);
	int ExtendedMatrix[3][5] {extendMatrix(matrix)};
	sarrusAlgorithm(ExtendedMatrix);

    return 0;
}