#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MSIZE 1000100

int prime_table[MSIZE];
bool prime_check[MSIZE];

int MakePrimeTable() {
	memset(prime_check, 1, sizeof(prime_check));
	int i, k = 0, j;
	for(i = 2; i < MSIZE; ++i) {
		if(prime_check[i]) {
			prime_table[k++] = i;
		}
		for(j = 2; j * i < MSIZE; ++j) {
			prime_check[j * i] = false;
		}
	}
	return k;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int prime_num = MakePrimeTable();

	char k[110];
	int l, i, j;
	long long s, mod = 0;
	while(scanf("%s %d", k, &l) && (l != 0 && strcmp("0", k))) {
		int len = strlen(k);
		for(i = 0; i < prime_num; ++i) {
			mod = 0;
			for(j = 0; j < len - 2; j += 3) {
				s = k[j] - '0';
				s = s*10 + k[j+1] - '0';
				s = s*10 + k[j+2] - '0';
				s += mod * 1000;
				mod = s % prime_table[i];
			}
			for(; j < len; ++j) {
				s = k[j] - '0';
				s += mod * 10;
				mod = s % prime_table[i];
			}
			if(mod == 0) 
				break;
		}
		if(i == prime_num || prime_table[i] >= l) printf("GOOD\n");
		else printf("BAD %d\n", prime_table[i]);
		 
	}
}
