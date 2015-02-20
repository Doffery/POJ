#include<cstdio>
#include<vector>

//Floyd-Warshall algorithm

#define INFIN 0x7fffffff
struct Edge {
	int s, t;//start and terminal
	int time;//time it costs to pass the message
	Edge() {}
	Edge(int si, int ti, int timei) {
		s = si; t = ti; time = timei;
	}
};//pairs that pass message

std::vector<Edge> nodes[110];

int dist[110][110];

int N;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(scanf("%d", &N) && N) {
		//make the map
		int i, j, k;
		for(i = 1; i < N + 1; ++i) { 
			nodes[i].clear();
			for(j = 1; j < N + 1; ++j)
				dist[i][j] = INFIN;
		}
		for(i = 1; i < N + 1; ++i) {
			dist[i][i] = 0;
			int n;
			scanf("%d", &n);
			while(n--) {
				int t, time;
				scanf("%d %d", &t, &time);
				nodes[i].push_back(Edge(i, t, time));
				dist[i][t] = time;
			}
		}

		//floyd algo
		for(k = 1; k <= N; ++k)
			for(i = 1; i <= N; ++i)
				for(j = 1; j <= N; ++j) {
					int d;
					if(dist[i][k] != INFIN && dist[k][j] != INFIN) {
						d =  dist[i][k] + dist[k][j];
						if(dist[i][j] > d)
							dist[i][j] = d;
					}
				}

		//search the smallest greatest num in each line
		int gre = INFIN, lin;
		for(i = 1; i <= N; ++i) {
			int grel = 0;
			for(j = 1; j <= N; ++j)
				if(dist[i][j] > grel)
					grel = dist[i][j];
			if(grel < gre) {
				gre = grel;
				lin = i;
			}
		}
		printf("%d %d\n", lin, gre);
	}
}
