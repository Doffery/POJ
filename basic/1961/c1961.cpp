#include<cstdio>
#include<cstring>

char str[1000010];

int next[1000010];


int main() {
	freopen("in.txt", "r", stdin);

	int cases = 0;
	int n;
	int i, j, k;
	while(scanf("%d", &n) != EOF && n) {
		cases ++;/*
		scanf("%s", str);
		memset(next, 0, sizeof(next));
		next[0] = -1;
		k = -1;
		i = 0;
		while(i < n) {
			if(k == -1 || str[i] == str[k]) {
				++i;
				++k;
				next[i] = k;
			} else k = next[k];
		}*/
		scanf("%s", str+1);
		//memset(next, 0, sizeof(next));
		next[0] = 0;
		k = 0;
		for(i = 2; i <= n; ++i) {
			while(k > 0 && str[k+1] != str[i])
				k = next[k];
			if(str[k+1] == str[i])
				++k;
			next[i] = k;
		}

		printf("Test case #%d\n", cases);
		for(i = 2; i <= n; ++i) {
			int len = i - next[i];
			if(i % len == 0 && i / len > 1)
				printf("%d %d\n", i, (int)i/len);
		}
		printf("\n");
	}

}
