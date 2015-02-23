#include<stdio.h>
#include<math.h>

#define INTMAX 0x7fffffff

int integer_index[50000];//1, 2, 3..., 9, 11, 13, 15... sum up

int integer_group[100];//9, 90*2, 900*3, 9000*4...

int nn;
void Init() {
	unsigned sum = 0;
	int du = 9;
	int i, j, k = 0, l, m;
	integer_group[0] = 0;
	for(j = 1; sum <= INTMAX; ++j, du *= 10) {
		integer_group[j] = du * j + integer_group[j - 1];
		for(i = 0; i < du && sum <= INTMAX; ++i) {
			k += j;
			sum += k;
			integer_index[nn++] = sum;
		}
	}
}

int Find(int x) {
	if(x == 1)
		return 1;
	int s = 0;
	int i = 0, j;
	while(integer_index[i] <= x && i < nn-1)
		++i;
	s = x - integer_index[i-1];
	if(s == 0)
		s = integer_index[i-1] - integer_index[i-2];
	i = 0;
	while(integer_group[i] <= s)
		++i;
	s = s - integer_group[i-1];
	if(i == 1)
		return s;
	if(s == 0)
		return 9;
	int t, m;
	t = (int)pow(10, i-1);
	t += (int)(s / i);
	m = s % i;
	if(m) {
		t /= (int)pow(10, (i - m));
		return t % 10;
	}
	else return (s/i - 1) % 10;

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	int i, j;
	scanf("%d", &n);
	Init();
	for(i = 0; i < n; ++i) {
		scanf("%d", &m);
		printf("%d\n", Find(m));
	}

	return 0;
}
