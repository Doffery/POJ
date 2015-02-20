//use this program to practice the Kurskal Algorithm

#include<stdio.h>

typedef struct {
	int s, t; //start and terminal
	int value;
} Edge;

Edge edges[125000];

int dist[510][510];

int dset[125000];

int Find(int x) {
	if(dset[x] != x)
		dset[x] = Find(dset[x]);
	return dset[x];
}

void Union(int x, int y) {
	int rx = Find(x);
	int ry = Find(y);
	if(rx == ry)
		return;
	dset[rx] = ry;
}

int cmp(const void *a, const void *b) {
	return ((Edge *)a)->value - ((Edge *)b)->value;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int nn;
	scanf("%d", &nn);
	while(nn--) {
		int n, i, j, c = 0;
		scanf("%d", &n);
		for(i = 0; i < n; ++i) 
			for(j = 0; j < n; ++j) {
				//scanf("%d", &dist[i][j]);
				int d;
				scanf("%d", &d);
				if(i < j) {
					edges[c].s = i;
					edges[c].t = j;
					edges[c].value = d;
					++c;
				}
			}
		qsort(edges, c, sizeof(Edge), cmp);

		//makeset
		for(i = 0; i < n; ++i)
			dset[i] = i;

		int maxEdge = 0;
		for(i = 0; i < c; ++i) {
			int s = edges[i].s;
			int t = edges[i].t;
			if(Find(s) == Find(t))
				continue;
			else {
				Union(s, t);
				if(maxEdge < edges[i].value)
					maxEdge = edges[i].value;
			}
		}
		printf("%d\n", maxEdge);
	}
}

