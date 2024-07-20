#include <iostream>

using std::cout;
using std::endl;

// Function to increase the number of columns of the matrix to be able to apply the Sarrus algorithm
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
	return extendedMatrix[I][J];
}

// Function to print the 3 x 3 matrix on the console
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

// Function to print the 3 x 5 matrix on the console
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

// Function to calculate the determinant by Sarrus algorithm
int sarrusAlgorithm(int matrix[3][5]){
	int determinant = 0;
	for (int n = 0; n < 3; n++){
		int i = 0;
		int j = n;
		int positiveDiagonalProduct = 1;
		cout << i << " " << j << " | ";
		for (i = 0; i < 3; i++){
			positiveDiagonalProduct = positiveDiagonalProduct * matrix[i][j];
			cout << i << " " << j << " | ";
			j++;
		}
		cout << endl << positiveDiagonalProduct << endl;	
		determinant += positiveDiagonalProduct;
	}
	cout << endl << endl;
	for (int n = 0; n < 3; n++){
		int i = 0;
		int j = 2 + n;
		int negativeDiagonalProduct = 1;
		cout << i << " " << j << " | ";
		for (i = 0; i < 3; i++){
			cout << i << " " << j << " | ";
			negativeDiagonalProduct = negativeDiagonalProduct * matrix[i][j];
			j--;
		}
		cout << endl << negativeDiagonalProduct << endl;
		determinant -= negativeDiagonalProduct;
	}
	cout << endl;
	return determinant;
}

int main(){
    int matrix[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << "Enter: " << i << " " << j << ":	";
			std::cin >> matrix[i][j];
		}
	}
    
	cout << endl;
	printMatrix(matrix);
	cout << endl;

	int ExtendedMatrix[3][5];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++) {
			ExtendedMatrix[i][j] = extendMatrix(matrix, i, j);
		}
	}

	printExtendedMatrix(ExtendedMatrix);
	cout << "The determinant is: " << sarrusAlgorithm(ExtendedMatrix);

	int exit;
	std::cin >> exit;
    return 0;
}