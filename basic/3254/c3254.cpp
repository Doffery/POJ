#include<cstdio>
#include<cstring>
#include<vector>

using std::vector;

#define MOD 100000000
#define MSTATE 4096
int data[15];

int dp[15][MSTATE];
vector<int> vecdp[15];


bool Check(int x) {
	if(x & (x << 1))
		return false;
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);

	int M, N;
	scanf("%d %d", &M, &N);
	int i, j, k, s;
	for(i = 0; i < M; ++i) {
		s = 0;
		for(j = 0; j < N; ++j) {
			scanf("%d", &k);
			if(k) s+= 1 << j;
		}
		data[i] = s;
	}

	int rMSTATE = 1 << N;
	memset(dp, 0, sizeof(dp));
	for(i = 0; i < rMSTATE; ++i) {
		if((data[0] | i) == data[0] && Check(i)) {
			dp[0][i] = 1;
			vecdp[0].push_back(i);
		}
	}
	for(i = 1; i < M; ++i) {
		for(j = 0; j < rMSTATE; ++j) {
			if((data[i] | j) == data[i] && Check(j)) {
				for(k = 0; k < vecdp[i-1].size(); ++k) {
					if(!(vecdp[i-1][k] & j)) {
						dp[i][j] += dp[i-1][vecdp[i-1][k]];
						dp[i][j] = dp[i][j] % MOD;
					}
				}
				vecdp[i].push_back(j);
			}
		}
	}
	int res = 0;
	for(i = 0; i < vecdp[M-1].size(); ++i) {
		res += dp[M-1][vecdp[M-1][i]];
		res = res % MOD;
	}
	printf("%d\n", res);
}
