#include<stdio.h>

int myBiSearch(int arr[], int first, int last,int target) {
	if (first > last)
		return -1;// 끝까지 왔음에도 못찾으면 끝
	int mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if (arr[mid] >= target) {
		return myBiSearch(arr, first, mid - 1, target);
	}
	else
		return myBiSearch(arr, mid + 1, last, target);
}
/*
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	int idx = myBiSearch(arr, 0,sizeof(arr) / sizeof(int), 123);

	printf("%d", idx);
	return 0;
}
*/