#include<cstdio>
#include<vector>

typedef struct {
	int s,  t;//start, terminal index
	double rate;
	double commission;
}Edge;//Exchange points, one point two edges

struct Node {
	std::vector<Edge> edges;
}nodes[110];//Currencies

double money[110];

int N, M, S;
double V;
bool Bellman() {
	int i, j;
	for(i = 1; i < N+1; ++i)
		money[i] = 0;
	money[S] = V;

	for(i = 0; i < N + 1; ++i) {
		for(j = 1; j < N+1; ++j) {
			size_t t = nodes[j].edges.size();
			size_t en;
			for(en = 0; en < t; ++en) {
				Edge e = nodes[j].edges[en];
				if(money[e.s] != 0) {
					double rc = (money[e.s] - e.commission) * e.rate;
					if(rc > money[e.t]) {
						money[e.t] = rc;
						//if(e.t == S)
						if(i == N)
							return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	while(scanf("%d %d %d %lf", &N, &M, &S, &V) != EOF) {
		int i;
		for(i = 1; i < N+1; ++i) {
			nodes[i].edges.clear();
		}
		for(i = 0; i < M; ++i) {
			int s, t;
			scanf("%d %d", &s, &t);
			Edge e, er;
			e.s = s; e.t = t;
			er.s = t; er.t = s;
			scanf("%lf %lf", &e.rate, &e.commission);
			scanf("%lf %lf", &er.rate, &er.commission);
			nodes[s].edges.push_back(e);
			nodes[t].edges.push_back(er);
		}

		if(Bellman())
			printf("YES\n");
		else printf("NO\n");
	}

}
