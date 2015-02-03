#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

typedef struct {
	int index;
	int money;
}Edge;

struct TNode{
	int money;
	int level;
	std::vector<Edge> edges;
}nodes[110];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int m, n, i, j;
	while(scanf("%d %d", &m, &n) == 2) {
		for(i = 1; i <= n; ++i) {
			int en;
			scanf("%d %d %d", &nodes.money, &nodes.level, &en);
			for(j = 0; j < en; ++j) {
				Edge e;
				scanf("%d %d", &e.index, &e.money);
				edges.push_back(e);
			}
		}
	}

	return 0;
}

int dfs

