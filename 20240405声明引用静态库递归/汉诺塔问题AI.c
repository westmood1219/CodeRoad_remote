#include <stdio.h>

void move(int n, char from, char to) {
	printf("Move disk %d from %c to %c\n", n, from, to);
}

void hanoi(int n, char A, char B, char C) {
	if (n == 1) {
		move(n, A, C);
	} else {
		hanoi(n-1, A, C, B); // 将n-1个盘子从A移动到B，借助C
		move(n, A, C);       // 将剩下的盘子从A移动到C
		hanoi(n-1, B, A, C); // 将n-1个盘子从B移动到C，借助A
	}
}

int main() {
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

