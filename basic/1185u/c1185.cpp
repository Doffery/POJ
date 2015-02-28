#include<cstdio>
#include<vector>
#include<cstring>

using std::vector;

//int map[100][10];
int data[100];
int state[65];
int state_rev[1024];
int num[65];
int dp[100][65][65];
int dplmax[100][65];

vector<int> vecdp[100];

int N, M;
int state_num;

void Init() {
	int i, j, s;
   	state_num = 0;
	for(i = 0; i < (1 << M); ++i) {
		if(!(i << 1 & i) && !(i << 2 & i)) {
			s = 0;
			for(j = 0; j < M; ++j) {
				if(i & (1 << j))
					++s;
			}
			num[state_num] = s;
			state_rev[i] = state_num;
			state[state_num++] = i;
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

	//for(i = 0; i < state_num; ++i)
	//	for(j = 0; j < state_num; ++j)
	//		dp[0][i][j] = vecdp[0].size();
	k = 0;
	for(i = 0; i < vecdp[0].size(); ++i) {
		if(num[state_rev[vecdp[0][i]]] > k)
			k = num[state_rev[vecdp[0][i]]];
	}
	for(i = 0; i < state_num; ++i)
		for(j = 0; j < state_num; ++j)
			dp[0][i][j] = k;
	if(N > 1)
		for(i = 0; i < vecdp[0].size(); ++i) {
			k = 0;
			for(j = 0; j < vecdp[1].size(); ++j) {
				if(vecdp[1][j] & vecdp[0][i])
					continue;
				if(num[state_rev[vecdp[1][j]]] > k)
					k = num[state_rev[vecdp[1][j]]];
			}
			//dplmax[1][state_rev[vecdp[1][i]]] = k;
			for(j = 0; j < state_num; ++j)
				dp[1][state_rev[vecdp[0][i]]][j] = k + num[state_rev[vecdp[0][i]]];
		}/*
	for(i = 0; i < vecdp[1].size(); ++i) {
		k = 0;
		for(j = 0; j < vecdp[0].size(); ++j) {
			if(vecdp[0][j] & vecdp[1][i])
				continue;
			++k;
		}
		dplmax[1][state_rev[vecdp[1][i]]] = k;
	}	*/

	int lmaxt;
	for(i = 2; i < N; ++i) {
		for(j = 0; j < vecdp[i-1].size(); ++j) {
			for(k = 0; k < vecdp[i-2].size(); ++k) {
				if(vecdp[i-1][j] & vecdp[i-2][k])
					continue;
				s = 0;
				for(l = 0; l < vecdp[i].size(); ++l) {
					if((vecdp[i][l] & vecdp[i-1][j])
							|| (vecdp[i][l] & vecdp[i-2][k]))
						continue;
					if(num[state_rev[vecdp[i][l]]] > s)
						s = num[state_rev[vecdp[i][l]]];
				}
				lmaxt = 0;
				if(i != 2) {
					for(l = 0; l < vecdp[i-3].size(); ++l) {
						int tl = dp[i-1][state_rev[vecdp[i-2][k]]][state_rev[vecdp[i-3][l]]];
						if(tl > lmaxt)
							lmaxt = tl;
					}
				} else {
					lmaxt = dp[i-1][state_rev[vecdp[i-2][k]]][0];
				}
				s +=  lmaxt;//dplmax[i-2][state_rev[vecdp[i-2][k]]];
				dp[i][state_rev[vecdp[i-1][j]]][state_rev[vecdp[i-2][k]]] = s;
				//if(s > lmaxt)
				//	lmaxt = s;
			}
			//dplmax[i-1][state_rev[vecdp[i-1][j]]] = lmaxt;
		}
	}

	int ans = 0, ta;
	if(N < 3) {
		if(N == 2) {
			for(i = 0; i < vecdp[0].size(); ++i) {
				ta = dp[1][state_rev[vecdp[0][i]]][0];
				if(ta > ans)
					ans = ta;
			}
		} else if(N == 1) {
			ans = dp[0][0][0];
		}
	}
	else for(j = 0; j < vecdp[N-2].size(); ++j)
		for(k = 0; k < vecdp[N-3].size(); ++k) {
			ta = dp[N-1][state_rev[vecdp[N-2][j]]][state_rev[vecdp[N-3][k]]];
			if(ta > ans)
				ans = ta;
		}
	printf("%d\n", ans);
}
