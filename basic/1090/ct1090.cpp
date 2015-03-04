#include<cstdio>

bool data[1010];

int count = 0;

void Set(int x) {
	++count;
	if(x == 0) {
		data[0] = !data[0];
		return;
	}
	if(!data[x-1])
		Set(x-1);
	int i;
	for(i = x-2; i >= 0; --i)
		if(data[i])
			Set(i);
	data[x] = !data[x];
}

int main() {
	freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	int i, j;
	for(i = 0;i < n; ++i) {
		scanf("%d", &j);
		data[i] = j;
	}
	for(i = n-1; i >= 0; --i)
		if(data[i])
			Set(i);
	printf("%d\n", count);
}
