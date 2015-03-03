#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

using std::vector;
using std::priority_queue;
using std::pair;

//typedef pair<int, int> mpair;

struct mpair {
	int first, second;
	mpair(int x, int y) {
		first = x; second = y;
	}

	bool operator < (const mpair rhs) const {
		if(first < rhs.first)
			return true;
		else if(first == rhs.first && second > rhs.second)
			return true;
		return false;
	}
};

int fn[25];
int dn[25];
int tn[24];

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
		fishe = -1;
		tn[0] = 0;
		int end, tfishe, ttimes[25];
		for(end = 0; end < n; ++end) {
			tmin = h * 60;
			tfishe = 0;
			priority_queue<mpair> heap_max;
			memset(ttimes, 0, sizeof(ttimes));
			for(j = 0; j <= end; ++j) {
				tmin -= tn[j] * 5;
				if(fn[j] > 0)
					heap_max.push(mpair(fn[j], j));
			}
			if(tmin <= 0)
				break;
			while(tmin - 5 >= 0 && !heap_max.empty()) {
				mpair mp = heap_max.top();
				heap_max.pop();
				tfishe += mp.first;
				ttimes[mp.second] += 5;
				if(dn[mp.second] < mp.first)
					heap_max.push(mpair(mp.first-dn[mp.second], mp.second));
				tmin -= 5;
			}
			if(tmin > 0)
				ttimes[0] += tmin;
			if(fishe < tfishe) {
				memcpy(times, ttimes, sizeof(times));
				fishe = tfishe;
			} else if(fishe ==tfishe) {
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
