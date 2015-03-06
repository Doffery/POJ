#include<cstdio>
#include<algorithm>

int data[10010];

int main() {

	freopen("in.txt", "r", stdin);

	int N, K;
	scanf("%d %d", &N, &K);
	int i, j;
	float t;
	long long sum;
	for(i = 0; i < N; ++i) {
		scanf("%f", &t);
		data[i] = (int)(t * 100);
		sum += data[i];
	}
	std::sort(data, data+N);

	long long maxLen = sum / K;
	//binary search the answer
	long long minLen = 0;
	while(minLen <= maxLen) {
		long long mid = (minLen + maxLen) / 2;
		if(mid == 0) {
			minLen = 1;
			break;
		}
		long long cables = 0;
		for(i = N-1; i >= 0; --i) {
			cables += data[i] / mid;
		}
		if(cables >= K)
			minLen = mid+1;
		else maxLen = mid-1;
	}
	printf("%0.2f\n", (minLen-1)/100.0);
}
