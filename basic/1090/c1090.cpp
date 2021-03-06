#include<cstdio>
#include<cstring>


#define NUM 500
int pow2[NUM];//1000
int result[NUM];
int data[2010];

int cacu[2010];

void Cacauc(int n, bool force) {
	if(n == 0) {
		if(force || data[0])
			cacu[0] ++;
		return;
	}/* else if(n == 1) {
		if(data[1]) {
			if(data[0])
				cacu[1] ++;
			else 
		}
	}*/
	if(force || data[n]) {
		cacu[n-1] ++;
		if(data[n-1]) {
			if(n > 1) Cacauc(n-2, false);
		} else Cacauc(n-1, true);
		cacu[0] ++;
	} else Cacauc(n-1, false);
}

void Multiply(int *m, int x) {
	int i;
	int carry = 0;
	for(i = 0; i < NUM-1; ++i) {
		m[i] *= x;
		m[i] += carry;
		if(m[i] >= 1000) {
			carry = (int)(m[i] / 1000);
			m[i] %= 1000;
		} else carry = 0;
	}
}

void MultiAdd(int x) {
	int i, carry = 0;
	for(i = 0 ; i < NUM -1; ++i) {
		result[i] += pow2[i] * x;
		result[i] += carry;
		if(result[i] >= 1000) {
			carry = (int)(result[i]/1000);
			result[i] %= 1000;
		} else carry = 0;
	}
}

int main() {

	freopen("in.txt", "r", stdin);

	int kn;
	scanf("%d", &kn);
	int i, j = 0;
	for(i = 0; i < kn; ++i) {
		scanf("%d", &data[i]);
		if(data[i])
			j = i;
	}
	memset(cacu, 0, sizeof(cacu));
	//Cacauc(kn-1, false);

	int n = j;
	bool force = false;
	while(true) {
		if(n == 0) {
			if(force || data[0] != 0)
				cacu[0] += 1;
			break;
		}
		if(force || data[n] != 0) {
			cacu[n-1] += 1;
			cacu[0] += 1;
			if(data[n-1]) {
				if(n > 1) {
					n -= 2;
					force = false;
				}
				else {
					break;
				}
			} else {
				--n;
				force = true;
			}
		} else {//Cacauc(n-1, false);
			--n;
			force = false;
		}
	}
	memset(pow2, 0, sizeof(pow2));
	memset(result, 0, sizeof(result));
	pow2[0] = 1;
	for(i = 0; i <= j; ++i) {
		if(cacu[i])
			MultiAdd(cacu[i]);
		//multiply 2 and plus 1
		if(i != j) {
			Multiply(pow2, 2);
			pow2[0] ++;
		}
	}
	bool s = true;
	for(i = NUM-1; i > 0; --i) {
		if(result[i-1] == 0 && s)
			continue;
		else {
			if(s)
				printf("%d", result[i-1]);
			else printf("%03d", result[i-1]);
			s = false;
		}
	}
	if(s)
		printf("0");
	printf("\n");
}
