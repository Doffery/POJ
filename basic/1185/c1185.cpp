#include<cstdio>
#include<vector>
#include<cstring>

using std::vector;

//int map[100][10];
int data[100];
int state[65];
int state_rev[1024];
int dp[100][65][65];
int dplmax[100][65];

vector<int> vecdp[100];

int N, M;
int state_num;

void Init() {
	int i;
   	state_num = 0;
	for(i = 0; i < (1 << M); ++i) {
		if(!(i << 1 & i) && !(i << 2 & i)) {
			state[state_num++] = i;
			state_rev[i] = state_num;
		}
	}
}

void DFSI(int x, int ind, int s) {
	if(x < 0) 
		vecdp[ind].push_back(s);
	else {
		DFSI(x-1, ind, s);
		if(data[ind] & (1 << x))
			DFSI(x-3, ind, s+(1<<x));
	}
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	Init();

	int i, j, k, l, s;
	char t[20];
	for(i = 0; i < N; ++i) {
		scanf("%s", t);
		s = 0;
		for(j = 0; j < M; ++j) {
			if(t[j] == 'P') {
				s |= 1 << j;
			//	map[i][j] = 1;
			}
			//else map[i][j] = 0;
		}
		data[i] = s;
		DFSI(M, i, 0);
	}

	memset(dp, 0, sizeof(dp));
	memset(dplmax, 0, sizeof(dplmax));

	for(i = 0; i < state_num; ++i)
		for(j = 0; j < state_num; ++j)
			dp[0][i][j] = vecdp[0].size();
	for(i = 0; i < vecdp[1].size(); ++i) {
		k = 0;
		for(j = 0; j < vecdp[0].size(); ++j) {
			if(vecdp[0][j] & vecdp[1][i])
				continue;
			++k;
		}
		dplmax[1][state_rev[vecdp[1][i]]] = k;
		for(j = 0; j < state_num; ++j) 
			dp[1][state_rev[vecdp[1][i]]][j] = k;
	}

	int lmaxt;
	for(i = 2; i < N; ++i) {
		for(j = 0; j < vecdp[i-1].size(); ++j) {
			lmaxt = 0;
			//for(k = 0; k < state_num; ++k) {
			//}
			for(k = 0; k < vecdp[i-2].size(); ++k) {
				s = 0;
				for(l = 0; l < vecdp[i].size(); ++l) {
					if(vecdp[i][l] & vecdp[i-1][j] 
							|| vecdp[i][l] & vecdp[i-2][k])
						continue;
					++s;
				}
				s +=  dplmax[i-1][state_rev[vecdp[i-2][k]]];
				dp[i][state_rev[vecdp[i-1][j]]][state_rev[vecdp[i-2][k]]] = s;
				if(s > lmaxt)
					lmaxt = s;
			}
			dplmax[i][state_rev[vecdp[i-1][j]]] = lmaxt;
		}
	}

	int ans = 0, ta;
	for(j = 0; j < vecdp[N-2].size(); ++j)
		for(k = 0; k < vecdp[N-3].size(); ++k) {
			ta = dp[N-1][state_rev[vecdp[N-2][j]]][state_rev[vecdp[N-3][k]]];
			if(ta > ans)
				ans = ta;
		}
	printf("%d\n", ans);
}
