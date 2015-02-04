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
	int i;
	for(i = 0; i < N; ++i)
		money[i] = 0;
	money[S] = V;

	for(i = 0; i < 2 * N; ++i) {
		int j;
		for(j = 0; j < N; ++j) {
			size_t t = nodes[j].edges.size();
			size_t en;
			for(en = 0; en < t; ++en) {
				Edge e = nodes[j].edges[en];
				if(money[e.t] != 0) {
					double rc = (money[e.s] - e.commission) * e.rate;
					if(rc >= money[e.t]) {
						money[e.t] = rc;
						if(e.t == S)
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
		int i = 0;
		for(; i < M; ++i) {
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
