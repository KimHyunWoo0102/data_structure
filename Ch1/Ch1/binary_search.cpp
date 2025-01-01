#include<stdio.h>

int binary_search(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}

	return -1;
}

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int idx;

	idx = binary_search(arr, sizeof(arr) / sizeof(int), 5);

	if (idx == -1) {
		printf("target is not in the arr");
	}
	else
		printf("target is in %d", idx);
	return 0;
}