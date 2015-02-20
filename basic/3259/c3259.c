#include<cstdio>
#include<vector>
#include<memory>

//It's about find a negative cycle with Bellman-Ford Algorithm

#define INFIN 0x7fffffff
struct Edge{
	int value;
	int s, t;//start node and terminal
	Edge(){}
	Edge(int si, int ti, int valuei) {
		s = si; t = ti; value = valuei;
	}
};

struct Node {
	std::vector<Edge> edges;
} nodes[510];//fields

int dist[510];

int N, M, W;

bool Check() {
	//std::memset(dist, 0, N, sizeof(int));
	int i;
	for(i = 1; i < N+1; ++i) 
		dist[i] = INFIN;
	dist[1] = 0;
	int j;
	for(i = 0; i < N; ++i) {
		for(j = 1; j < N + 1; ++j) {
			int en = nodes[j].edges.size();
			for(; en > 0; --en) {
				Edge e = nodes[j].edges[en - 1];
				if(dist[e.s] != INFIN) {
					if(dist[e.s] + e.value < dist[e.t])
						dist[e.t] = dist[e.s] + e.value;
				}
			}
		}
	}
	for(j = 1; j < N + 1; ++j) {
		int en = nodes[j].edges.size();
		for(; en > 0; --en) {
			Edge e = nodes[j].edges[en - 1];
			if(dist[e.s] != INFIN) {
				if(dist[e.s] + e.value < dist[e.t])
					return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int f;
	scanf("%d", &f);
	while(f--) {
		scanf("%d %d %d", &N, &M, &W);
		int i;
		for(i = 1; i < N + 1; ++i) {
			nodes[i].edges.clear();
		}
		for(i = 0; i < M; ++i) {
			int s, t, value;
			scanf("%d %d %d", &s, &t, &value);
			nodes[s].edges.push_back(Edge(s, t, value));
			nodes[t].edges.push_back(Edge(t, s, value));
		}
		for(i = 0; i < W; ++i) {
			int s, t, value;
			scanf("%d %d %d", &s, &t, &value);
			nodes[s].edges.push_back(Edge(s, t, 0 - value));
		}

		if(Check())
			printf("YES\n");
		else printf("NO\n");

	}
}
