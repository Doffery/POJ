//Hungary Algorithm

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int N, K;
int grid[510][510];
bool find[510];
int paired[510];

bool FindPair(int x) {
	int i;
	for(i = 1; i < N+1; ++i) {
		if(grid[x][i] && !find[i]) {
			find[i] = true;
			if(paired[i] == 0 || FindPair(paired[i])) {
				paired[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int p = 0;
	int i, j;
	scanf("%d %d", &N, &K);
	memset(grid, 0, sizeof(grid));

	memset(paired, 0, sizeof(paired));
	for(i = 0; i < K; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		grid[x][y] = 1;
	}

	for(i = 1; i < N+1; ++i) {
		memset(find, 0, sizeof(find));
		if(FindPair(i))
			++p;
	}
	printf("%d\n", p);
}
