#include<cstdio>
#include<queue>
#include<vector>

using std::priority_queue;
using std::vector;

priority_queue<long long, vector<long long>, std::greater<long long> > haffqueue;

//int planks[50010];

int main() {
	freopen("in.txt", "r", stdin);

	int n, i, j;
	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		//scanf("%d", &planks[i]);
		scanf("%d", &j);
		haffqueue.push(j);
	}
	long long min1, min2, add, cost = 0;
	while(haffqueue.size() > 1) {
		min1 = haffqueue.top(); haffqueue.pop();
		min2 = haffqueue.top(); haffqueue.pop();
		add = min1 + min2;
		cost += add;
		haffqueue.push(add);
	}

	printf("%lld\n", cost);

}
