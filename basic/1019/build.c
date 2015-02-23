#include<stdio.h>

int main() {
	freopen("in.txt", "w", stdout);
	int i;
	printf("2147483647\n");
	for(i = 1; i <= 2147483647; ++i) {
		printf("%d\n", i);
	}
}
