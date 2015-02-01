#include<stdio.h>
#include<memory.h>


typedef struct {
	int money;
	int index;
	Edge *next;
}Edge;
typedef struct {
	int money;
	int level;
	Edge *edge;
}TNode;
TNode nodes[110];

int graph[110][110];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	memset(graph, 0, sizeof(graph));

	int m, n;
	scanf("%d %d", &m, &n);

	int i;
	for(i = 1; i < n+1; ++i) {
		int en;
		scanf("%d %d %d", &nodes[i].money, &nodes[i].level, &en);
		if(en == 0)
			nodes[i].edge = NULL;
		else {
			Edge e;
			scanf("%d %d", &e.index, &e.money);
			nodes[i].edge = e; --en;
			Edge *pre = &e;
			int j = 0;
			for(;en > 0; --en) {
				Edge ed;
				scanf("%d %d", &ed.index, &ed.money);
				pre->next = ed;
				pre = &ed;
			}
			pre->next = NULL;
		}
	}



}
