#include <iostream>
using namespace std;
//Syed Asad Raza Zaidi-464239

//Code to fine inverse of 3x3 matrix

// Function to calculate the determinant of a 2x2 matrix
double determinantOf2x2(double mat[2][2]) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

// Function to calculate the adjoint of a 3x3 matrix
void adjoint(double A[3][3], double adj[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            double cofactorMat[2][2];
            int sign = ((i + j) % 2 == 0) ? 1 : -1;

            // Calculate the cofactor for A[i][j]
            int r = 0, c = 0;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    if (row != i && col != j) {
                        cofactorMat[r][c++] = A[row][col];

                        if (c == 2) {
                            c = 0;
                            ++r;
                        }
                    }
                }
            }
            // Calculate the determinant of the 2x2 matrix
            adj[j][i] = sign * determinantOf2x2(cofactorMat);
        }
    }
}

// Function to calculate the inverse of a 3x3 matrix
void inverse(double A[3][3], double inverseMat[3][3]) {
    double det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                 A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                 A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    if (det == 0) {
        cout << "Inverse does not exist as determinant is zero!" << endl;
        return;
    }

    double adj[3][3];
    adjoint(A, adj);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            inverseMat[i][j] = adj[i][j] / det;
        }
    }
}

// Function to display a matrix
void displayMatrix(double mat[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double matrix[3][3] ;
    cout<<"Enter Elements in the Matrix :";
    for(int i=0; i<3; i++){
    	for(int j=0; j<3; j++){
    		cin>>matrix[i][j];
		}
	}
    
    double invMatrix[3][3];

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix);

    inverse(matrix, invMatrix);

    cout << "\nInverse Matrix:" << endl;
    displayMatrix(invMatrix);

    return 0;
}

