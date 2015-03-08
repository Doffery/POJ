#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

int color[210];
int lens[210];

int f[210][210][210];

int DP(int i, int j, int k) {
	if(f[i][j][k])
		return f[i][j][k];
	int tem = (k+lens[j])*(k+lens[j]);
	if(i == j)
		return tem;
	int l;
	f[i][j][k] = DP(i, j-1, 0)+tem;
	for(l = i; l < j; ++l)
		if(color[l] == color[j])
			f[i][j][k] = 
				std::max(f[i][j][k], DP(i,l,k+lens[j])+DP(l+1,j-1,0));
	return f[i][j][k];
}

int main() {
	freopen("in.txt", "r", stdin);

	int T, cases = 0;
	scanf("%d", &T);
	int i, j, k, n;
	while(T--) {
		cases ++;
		scanf("%d", &n);
		memset(f, 0 , sizeof(f));
		memset(lens, 0, sizeof(lens));
		memset(color, 0, sizeof(color));
		int pre = 0;
		for(i = 0; i < n; ++i) {
			scanf("%d", &j);
			if(j == color[pre])
				++ lens[pre];
			else {
				color[++pre] = j;

				++ lens[pre];
			}
		}
		
		printf("Case %d: %d\n", cases, DP(1, pre, 0));
	}
}
