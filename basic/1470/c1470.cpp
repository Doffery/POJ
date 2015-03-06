#include<cstdio>
#include<cstring>

int tree[910];
bool visited[910];
int vtimes[910];

int main() {
	freopen("in.txt", "r", stdin);

	int n1, n2;
	int i, j, k;
	while(scanf("%d", &n1) != EOF) {
		char t[20];
		memset(tree, 0, sizeof(tree));
		memset(visited, 0, sizeof(visited));
		memset(vtimes, 0, sizeof(vtimes));
		for(i = 0;i < n1; ++i) {
			scanf("%s", t);
			int nod, nno, nodc;
			sscanf(t, "%d:(%d)", &nod, &nno);
			for(j = 0; j < nno; ++j) {
				scanf("%d", &nodc);
				tree[nodc] = nod;
			}
		}
		scanf("%d", &n2);
		char t1[20];
		int p1, p2;
		for(i = 0; i < n2; ++i) {
			scanf("%s %s", t, t1);
			sscanf(t, "(%d", &p1);
			sscanf(t1, "%d)", &p2);
			int x = p1;
			while(x != 0) {
				visited[x] = true;
				x = tree[x];
			}
			x = p2;
			while(x != 0) {
				if(visited[x]) {
					++ vtimes[x];
					break;
				}
				x = tree[x];
			}
			x = p1;
			while(x != 0) {
				visited[x] = false;
				x = tree[x];
			}
		}
		for(i = 1; i < 910; ++i)
			if(vtimes[i])
				printf("%d:%d\n", i, vtimes[i]);
	}
}
