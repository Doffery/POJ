#include<cstdio>
#include<algorithm>

int cube[101];
int hash[10010];

int compare(const void * a, const void * b) {
	return *((int *)a) - *((int *)b);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a1, a2, a3, a4, a5;
	scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
	
	int i, x1, x2, x3, x4, x5;
	for(i = 51; i < 101; ++i) {
		int x = i - 50;
		cube[i] = x*x*x;
	}
	for(i = 0; i < 50; ++i)
		cube[i] = -cube[100 - i];
	int n = 0;
	for(x1 = 0; x1 < 101; ++x1)
		if(x1 != 50) for(x2 = 0; x2 < 101; ++x2)
				if(x2 != 50) hash[n++] = -a1 * cube[x1] - a2 * cube[x2];
	std::sort(hash, hash+n);

	int count = 0;
	for(x3 = 0; x3 < 101; ++x3)
		if(x3 != 50) for(x4 = 0; x4 < 101; ++x4)
			if(x4 != 50) for(x5 = 0; x5 < 101; ++x5)
				if(x5 != 50) {
					int re = a3*cube[x3]+a4*cube[x4]+a5*cube[x5];
					int *p = std::lower_bound(hash, hash+n, re);
					while(*(p++)  == re)
						++count;
				}
	printf("%d\n", count);
	
}
