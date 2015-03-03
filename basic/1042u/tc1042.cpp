#include<cstdio>
#include<cstring>

//typedef pair<int, int> mpair;

int fn[25];
int dn[25];
int tn[24];

int fm[25];

int times[25];
int fishe;

int main() {
	freopen("in.txt", "r", stdin);

	int n, h, tmin;
	int i, j, k;
	while(scanf("%d", &n) != EOF && n) {
		scanf("%d", &h);
		for(i = 0; i < n; ++i)
			scanf("%d", &fn[i]);	
		for(i = 0; i < n; ++i)
			scanf("%d", &dn[i]);	
		for(i = 1; i < n; ++i)
			scanf("%d", &tn[i]);
		memset(times, 0, sizeof(times));
		fishe = 0;
		tn[0] = 0;
		int end, tfishe, ttimes[25];
		for(end = 0; end < n; ++end) {
			tmin = h * 60;
			tfishe = 0;
			memset(fm, 0, sizeof(fm));
			memset(ttimes, 0, sizeof(ttimes));
			int flag = 0;
			for(j = 0; j <= end; ++j) {
				tmin -= tn[j] * 5;
				if(fn[j] != 0)
					fm[j] = fn[j];
				else flag++;
			}
			if(tmin <= 0)
				break;

			while(tmin - 5 >= 0 && flag != end + 1) {
				k = 0;
				for(j = 0; j <= end; ++j) {
					if(fm[j] > fm[k])
						k = j;
				}
				tfishe += fm[k];
				ttimes[k] += 5;
				if(dn[k] < fm[k])
					fm[k] -= dn[k];
				else fm[k] = 0;
				tmin -= 5;
				flag = 0;
				for(j = 0; j <= end; ++j)
					if(fm[j] <= 0)
						++flag;
			}
			if(tmin > 0)
				ttimes[0] += tmin;
			if(fishe < tfishe) {
				memcpy(times, ttimes, sizeof(times));
				fishe = tfishe;
			} else if(fishe == tfishe) {
				for(i = 0; i < n; ++i)
					if(times[i] > ttimes[i])
						break;
					else if(times[i] < ttimes[i]) {
						memcpy(times, ttimes, sizeof(times));
						break;
					}
			}
		}
		printf("%d", times[0]);
		for(i = 1; i < n; ++i)
			printf(", %d", times[i]);
		printf("\nNumber of fish expected: %d\n\n", fishe);
	}
	return 0;

}
