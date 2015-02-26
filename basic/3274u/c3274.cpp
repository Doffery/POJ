///don't know this staff

#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

#define HASHSIZE 200001
using std::vector;

int cows[100000][30];
int tsum[30];

vector<int> hash[HASHSIZE];

int main() {
	freopen("in.txt", "r", stdin);

	memset(tsum, 0, sizeof(tsum));
	memset(cows, 0, sizeof(cows));
	int N, K;
	scanf("%d %d", &N, &K);
	int i, j, num;
	for(i = 0; i < N; ++i) {
		scanf("%d", &num);
		for(j = 0; j < K; ++j) {
			if(num % 2)
				tsum[j] += 1;
			if(j != 0)
				cows[i][j] = tsum[j] - tsum[0];
			num = num >> 1;
		}
		cows[i][0] = 0;
	}
	
	int maxlen = 0;

	int p = 0, s = 0;
	for(i = 0; i < N; ++i) {
		s = 0; p = 0;
		for(j = 1; j < K; ++j) {
			if(p++ == 7)
				p = 0;
			s += cows[i][j] * (int)pow(10, p);
		}
		int k = s % HASHSIZE;
		for(j = 0; j < hash[k].size(); ++j)
			if(hash[k][j] == i) {
				int m;
				for(m = 0; m < K; ++m) {
					if(cows[hash[k][j]][m] != cows[i][m])
						break;
				}
				if(m == K) {
					if(abs(hash[k][j]) - i > maxlen)
						maxlen = abs(hash[k][j]) - i;
				}
			}
		hash[k].push_back(i);
	}
	printf("%d\n", maxlen+1);
}
