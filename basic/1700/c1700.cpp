#include<cstdio>
#include<algorithm>

int data[1010];
int ttime = 0;

void Cross(int n) {
	if(n == 1) {
		ttime += data[0];
		return;
	}
	else if(n == 2) {
		ttime += data[1];
		return;
	}
	if(n == 3) {
		ttime += data[0] + data[1] + data[2];
		return;
	}
	int x = 2 * data[1];
	int y = data[0] + data[n-2];
	if(x >= y)
		ttime += data[n-2] + data[n-1] + data[0] * 2;
	else ttime += x + data[0] + data[n-1];
	Cross(n-2);
}

int main() {
	freopen("in.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int i, j, k;
		for(i = 0; i < n; ++i) {
			scanf("%d", &data[i]);
		}

		std::sort(data, data+n);

		//greedy detail
		ttime = 0;
		Cross(n);
		printf("%d\n", ttime);
	}
}
