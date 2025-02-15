#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;
double determinant(double mat[50][50], int n)
{
	double det = 0;
	double submat[50][50];
	if (n == 2)
		return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
	else
	{
		for (int k = 0; k < n; k++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == k)
						continue;
					submat[subi][subj] = mat[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, k) * mat[0][k] * determinant(submat, n -
				1));
		}
	}
	return det;
}
// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(double mat[50][50], double cofac[50][50], int x, int y, int n)
{
	int i = 0, j = 0;
	// Looping for each element of the matrix
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			// Copying into temporary matrix only those element
			// which are not in given row and column
			if (row != x && col != y)
			{
				cofac[i][j++] = mat[row][col];
				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(double mat[50][50], double adj[50][50], int n)
{
	if (n == 1)
	{
		adj[0][0] = 1;
		return;
	}
	// temp is used to store cofactors of A[][]
	int sign = 1;
	double temp[50][50];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Get cofactor of A[i][j]
			getCofactor(mat, temp, i, j, n);
			// sign of adj[j][i] positive if sum of row
			// and column indexes is even.
			sign = ((i + j) % 2 == 0) ? 1 : -1;
			// Interchanging rows and columns to get the
			// transpose of the cofactor matrix
			adj[j][i] = (sign) * (determinant(temp, n - 1));
		}
	}
}
// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(double adj[50][50], double det, double inv[50][50], int n)
{
	if (det == 0)
	{
		cout << "Singular matrix, no inverse";
		return false;
	}
	// Find Inverse using formula "inverse(A) = adj(A)/det(A)"
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inv[i][j] = adj[i][j] / double(det);
	return true;
}
int main() {
	int n, i, j;
	double matrixA[50][50];
	double matrixB[50][1];
	cout << "Enter the size of the matrix: ";
	cin >> n;
	//srand(time(0));
	cout << "matrix A is: " << endl;
	// storing and printing values of matrix A
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrixA[i][j] = rand() % 100;
			cout << matrixA[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "matrix B is : " << endl;
	// storing and printing values of matrix B
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 1; j++)
		{
			matrixB[i][j] = rand() % 100;
			cout << matrixB[i][j] << "\t";
		}
		cout << endl;
	}
	double det = determinant(matrixA, n);
	cout << "Determinant of the matrix A is: " << det << endl;
	double adj[50][50];
	adjoint(matrixA, adj, n);
	double inv[50][50] = { 0 };
	if (inverse(adj, det, inv, n))
		cout << "The is an Inverse matrix" << endl;
	// print matrix
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << inv[i][j] << "\t";
		cout << endl;
	}
	// Multiplying matrix a and b and storing in array mult.
	double multmat[50][50];
	multmat[i][j] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 1; ++j)
		{
			multmat[i][j] = 0;
			for (int k = 0; k < n; ++k)
			{
				multmat[i][j] += inv[i][k] * matrixB[k][j];
			}
		}
	// Displaying the multiplication of two matrix.
	cout << endl << "Output Matrix: " << endl;
	for (i = 0; i < n; ++i)
		for (j = 0; j < 1; ++j)
		{
			cout << " " << multmat[i][j];
			if (j == 0)
				cout << endl;
		}
	system("pause");
	return 0;
}