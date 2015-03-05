#include<cstdio>
#include<cstdlib>
#include<cstring>

char data[400010];

int next[400010];

int ans[400010];

int main() {
	freopen("in.txt", "r", stdin);

	while(scanf("%s", data+1) != EOF) {
		int len = strlen(data+1);
		int i, j, k;

		//getnext for len+1 data
		memset(next, 0, sizeof(next));
		k = 0;
		next[1] = 0;
		for(i = 2; i <= len; ++i) {
			while(k > 0 && data[k+1] != data[i])
				k = next[k];
			if(data[k+1] == data[i])
				++k;
			next[i] = k;
		}

		j = 1;
		k = next[len];
		ans[0] = len;
		while(k > 0) {
			ans[j++] = k;
			k = next[k];
		}
		printf("%d", ans[j-1]);
		for(i = j-2; i >= 0; --i)
			printf(" %d", ans[i]);
		printf("\n");
	}
	
}
