#include<cstdio>
#include<vector>

using std::vector;

enum NoteType {Power, Consumer, Dispatcher};

struct Edge {
	int s, t;
	int value;
	Edge(int is, int it, int iv) {
		s = is; t = it; value = iv;
	}
};

struct Node{
	NoteType type;//power 1, consumer 2, dispatcher 3
	int capicity;
	vector<Edge> edges;
} nodes[110];

int main() {
	freopen("in.txt", "r", stdin);

	int n, np, nc, m;
	int i, j;
	while(scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF) {
		for(i = 0; i < m; ++i) {
			char e[20]; int s, t, v;
			scanf("%s", e);
			sscanf(e, "(%d,%d)%d", &s, &t, &v);
			nodes[s].edges.push_back(Edge(s, t, v));
		}
		for(i = 0; i < np; ++i) {
			char e[20]; int u, z;
			scanf("%s", e);
			sscanf(e, "(%d)%d", &u, &z);
			nodes[u].capicity = z;
			nodes[u].type = NoteType.Power;
		}
		for(i = 0; i < nc; ++i) {
			char e[20]; int u, z;
			scanf("%s", e);
			sscanf(e, "(%d)%d", &u, &z);
			nodes[u].capicity = z;
			nodes[u].type = NoteType.Consumer;
		}

		//compute the maximum flow


	}
}
