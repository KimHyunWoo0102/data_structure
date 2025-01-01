#include<stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) {
	//작은것들 B로 옮기고
	//제일 큰거 c로 옮기고
	//남은놈들 c로 이동

	//이중 작은것들 이동을 재귀적으로 처리해서 알아서 하쇼로 넘기기

	if (num == 1) {
		printf("원반 1을 %c에서 %c로 이동시키기\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d을 %c에서 %c로 이동시키기\n",num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main() {
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}