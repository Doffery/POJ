#include<cstdio>
#include<algorithm>
#include<cstring>

#define INF 0x3fffffff

int N, P;

int dp[160][160];
int head[160];
int son[160];
bool fa[160];

void Dfs(int v) {
    int i,j,k;
    for(i = 0; i <= P; i++) dp[v][i] = INF;
    dp[v][1] = 0;
    int s = son[v];
    while(s)
    {
        Dfs(s);
        for(i = P; i >= 0; i--)
        {
            int tmp = dp[v][i]+1;
            for(j = 1; j < i; j++)
                tmp = std::min(tmp, dp[v][j]+dp[s][i-j]);
            dp[v][i] = tmp;
        }
        s = head[s];
    }
}

int main() {
	freopen("in.txt", "r", stdin);

	int i, j, k;
	while(~scanf("%d %d", &N, &P)) {
		int ht, st;
		int root;
		memset(fa, 0, sizeof(fa));
		memset(dp, 0, sizeof(dp));
		memset(head, 0, sizeof(head));
		memset(son, 0, sizeof(son));
		for(i = 1; i < N; ++i) {
			scanf("%d %d", &ht, &st);
			head[st] = son[ht];
			son[ht] = st;
			fa[st] = true;
		}
		for(i = 1; i <= N; ++i)
			if(!fa[i]) {
				root = i;
				break;
			}
		Dfs(root);
		//
		int ans = dp[root][P];
		for(i = 1; i <= N; i++)
		    ans = std::min(ans, dp[i][P]+1);
		printf("%d\n", ans);
	}

}
