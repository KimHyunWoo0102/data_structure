#include<stdio.h>

int Factorial(int n) {
	if (n == 0)
		return 1;

	return Factorial(n - 1) * n;
}

/*
int main() {
	for (int i = 0; i <= 10; i++) {
		printf("%d! = %d\n", i, Factorial(i));
	}
	return 0;
}
*/