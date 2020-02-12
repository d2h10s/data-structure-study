#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define n 10


int main() {
	srand(time(NULL));
	double matrix[n][n], b[n], x[n];
	printf("A|B:\n");
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < n; j++) {
			matrix[i][j] = rand() % 21 - 10;
			printf("%3.0lf ", matrix[i][j]);
		}
		b[i] = rand() % 21 - 10;
		printf("%3.0lf\n", b[i]);
	}
	if (matrix[0][0] == 0) {
		for (int i = 0; i < n; i++) {
			matrix[0][i] += matrix[2][i];
		}
		b[0] += b[2];
	}
	int i, count, j;
	double ratio, temp;

	if (matrix[0][0] == 0)
		printf("\nafter 1row=1row + 3row\n\n", n, n); // zero divider error 规瘤
	printf("\nA:\n");
	for (i = 0; i < n; i += 1) {
		for (j = 0; j < n; j += 1) {
			printf("%3.0lf ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n                                       B:\n");
	for (i = 0; i < n; i += 1) {
		printf("%43.0lf\n", b[i]);
	}
	printf("\n\n");
	// 啊快胶 家芭过
	for (i = 0; i < n - 1; i += 1) {
		for (j = i + 1; j < n; j += 1) {
			ratio = matrix[j][i] / matrix[i][i];
			for (count = i; count < n; count += 1) {
				matrix[j][count] -= (ratio * matrix[i][count]);
			}
			b[j] -= (ratio * b[i]);
		}
	}
	/* Back substitution */
	x[n - 1] = b[n - 1] / matrix[n - 1][n - 1];
	for (i = n - 2; i >= 0; i -= 1) {
		temp = b[i];
		for (j = i + 1; j < n; j += 1) {
			temp -= (matrix[i][j] * x[j]);
		}
		x[i] = temp / matrix[i][i];
	}
	printf("\n\nafter gauss operation A:\n");
	for (i = 0; i < n; i += 1) {
		for (j = 0; j < n; j += 1) {
			printf("%3.0lf ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\nreduced-row echelon matrix is:\n");
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			matrix[k][j] = 0;
			if (k == j) matrix[k][k] = 1;
			printf("%3.0lf ", matrix[k][j]);
		}
		printf("%11lf\n", x[k]);
	}

	printf("Answer:\n");
	for (i = 0; i < n; i += 1) {
		printf("   x%2d = %11lf\n", i + 1, x[i]);
	}

	_getch();
	return 0;
}
