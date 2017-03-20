#include<stdio.h>
#include<math.h>

int dp[10000010];
int main() {
	freopen("in.txt", "r", stdin);
	freopen("./out.txt", "w", stdout);
	double sum = 0;
	for(int i = 1; i < 10000001; ++i) {
		sum += log10(i+0.0);
		dp[i] = static_cast<int>(sum);
	}
	
	int n, m;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		printf("%d\n", dp[m]+1);
	}
	return 0;
}
