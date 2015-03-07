#include<cstdio>
#include<cstring>
#include<vector>

using std::vector;

struct Node {
	int pre;
	vector<int> sons;
	Node() {
		pre = 0;
	}
	vector<int> Q;
} nodes[910];

int sets[910];
int rank[910];

bool visited[910];
int vtimes[910];

int ancestor[910];

void MakeSet(int x) {
	sets[x] = x;
	rank[x] = 0;
}

int FindSet(int x) {
	if(x != sets[x]) sets[x] = FindSet(sets[x]);
	return sets[x];
}

void UnionSet(int x, int y) {
	int r1 = FindSet(x);
	int r2 = FindSet(y);
	if(r1 == r2)
		return;
	if(rank[r1] < rank[r2])
		sets[r1] = r2;
	else {
		sets[r2] = r1;
		if(rank[r1] == rank[r2])
			rank[r1] ++;
	}
}

void LCA(int u) {
	MakeSet(u);
	ancestor[FindSet(u)] = u;
	std::vector<int>::iterator it;
	for(it = nodes[u].sons.begin(); it != nodes[u].sons.end(); ++it) {
		LCA(*it);
		UnionSet(u, *it);
		ancestor[FindSet(u)] = u;
	}
	visited[u] = true;
	
	for(it = nodes[u].Q.begin(); it != nodes[u].Q.end(); ++it) {
		if(visited[*it])
			vtimes[ancestor[FindSet(*it)]] ++;
			//printf("%d-%d:%d\n", u, *it, ancestor[FindSet(*it)]);
	}
}

int main() {
	freopen("in.txt", "r", stdin);

	int n1, n2;
	int i, j, k;
	while(scanf("%d", &n1) != EOF) {
		char t[20];
		//memset(tree, 0, sizeof(tree));
		memset(visited, 0, sizeof(visited));
		memset(vtimes, 0, sizeof(vtimes));
		memset(rank, 0, sizeof(rank));
		memset(sets, 0, sizeof(sets));
		memset(ancestor, 0, sizeof(ancestor));
		int nod, nno, nodc;
		for(i = 0;i < n1; ++i) {
			scanf("%s", t);
			sscanf(t, "%d:(%d)", &nod, &nno);
			for(j = 0; j < nno; ++j) {
				scanf("%d", &nodc);
				//tree[nodc] = nod;
				nodes[nod].sons.push_back(nodc);
				nodes[nodc].pre = nod;
			}
		}
		//backtrace nod
		while(nodes[nod].pre != 0)
			nod = nodes[nod].pre;
		//nod equals root

		scanf("%d", &n2);
		char t1[20];
		int p1, p2;
		char a[2], b[2];
		for(i = 0; i < n2; ++i) {
			scanf("%1s%d%d%1s", a, &p1, &p2, b);
			//sscanf(t, "(%d", &p1);
			//sscanf(t1, "%d)", &p2);
			nodes[p1].Q.push_back(p2);
			nodes[p2].Q.push_back(p1);
		}
		LCA(nod);
		for(i = 1; i < 910; ++i) {
			nodes[i].sons.clear();
			nodes[i].Q.clear();
			nodes[i].pre == 0;
			if(vtimes[i])
				printf("%d:%d\n", i, vtimes[i]);
		}
	}
}
