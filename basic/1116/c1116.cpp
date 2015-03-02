#include<cstdio>
#include<algorithm>
#include<cstring>

#define INF 0x3fffffff

struct Shelf{
	float y, x, l, x1, x2;
	bool operator < (const Shelf rhs) const {
		return y < rhs.y;
	}
};

int mx, my, nx, ny, n;
Shelf shelves[100];
int solution[2][3];//move cut and remove

void Modify(int sh, int s) {//shelf index and tome start x coodinate
	float mid;
	float len;
	if(shelves[sh].x1 >= s && shelves[sh].x2 <= s + nx) {
		solution[1][2] += 2;
		solution[1][1] += (int)shelves[sh].l;
	} else if(shelves[sh].x1 >= s + nx) {
		mid = (mx + s + nx) / 2;
		if(mid >= shelves[sh].x1 && mid <= shelves[sh].x2) {
			len = mx - s - nx;
		} else if(mid > shelves[sh].x2) {
			len = 2 * (shelves[sh].x2 - s - nx);
		} else {
			len = 2 * (mx - shelves[sh].x1);
		}
		if(shelves[sh].l > len)
			solution[1][1] += (int)(shelves[sh].l - len);
	} else if(shelves[sh].x2 <= s) {
		mid = s / 2;
		if(mid >= shelves[sh].x1 && mid <= shelves[sh].x2) {
			len = s;
		} else if(mid > shelves[sh].x2) {
			len = 2 * shelves[sh].x2;
		} else {
			len = 2 * (s - shelves[sh].x1);
		}
		if(shelves[sh].l > len)
			solution[1][1] += (int)(shelves[sh].l - len);
		
	} else if(shelves[sh].x1 < s && shelves[sh].x2 <= s + nx) {
		solution[1][2] ++;
		solution[1][1] += (int)(shelves[sh].l <= s ? 0 : shelves[sh].l - s);
		//count moves?
	} else if(shelves[sh].x1 >= s && shelves[sh].x2 > s + nx) {
		solution[1][2] ++;
		solution[1][1] += (int)(shelves[sh].l <= mx-s-nx?0:shelves[sh].l+s+nx-mx);
		//count moves?
	}
}

void Check() {
		if(solution[1][2] > solution[0][2])
			return;
		if(solution[1][1] > solution[0][1])
			return;
		solution[0][1] = solution[1][1];
		solution[0][2] = solution[1][2];
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d%d%d%d %d", &mx, &my, &nx, &ny, &n);
	int i, j, k;
	for(i = 0; i < n; ++i) {
		scanf("%f%f%f%f%f", &shelves[i].y, &shelves[i].x
				, &shelves[i].l, &shelves[i].x1, &shelves[i].x2);
		shelves[i].x1 += shelves[i].x;
		shelves[i].x2 += shelves[i].x;
	}

	std::sort(shelves, shelves+n);

	memset(solution, 0, sizeof(solution));
	solution[0][0] = INF;
	solution[0][1] = INF;
	solution[0][2] = INF;

	for(i = 0; i <= mx - nx; ++i) {
		//examine every possibility in which tome in the bottom
		memset(solution[1], 0, sizeof(solution[1]));
		for(j = 0; j < n; ++j) {
			if(shelves[j].y >= ny) {
				Check();
				break;
			}
			if(shelves[j].x < i + nx && shelves[j].x + shelves[j].l > i) {
				//no need to move or...
				Modify(j, i);
			}
		}
	}
	for(i = 0; i < n; ++i) {
		if(my - shelves[i].y < ny)
			break;
		if(shelves[i].l < nx)
			continue;
		float lb, up;
		lb = shelves[i].x1 - shelves[i].l / 2;
		up = shelves[i].x2 + shelves[i].l / 2 - nx;
		for(k = 0; k <= mx - nx; ++k) {
			memset(solution[1], 0, sizeof(solution[1]));
			if(k < lb || k > up)
				solution[1][2] += 1;
			for(j = i+1; j < n; ++j) {
				if(shelves[j].y >= ny + shelves[i].y) {
					Check();
					break;
				}
				if(shelves[j].x < k + nx && shelves[j].x + shelves[j].l > k) {
					//no need to move or...
					Modify(j, k);
				}
			}
		}
	}
	printf("%d %d\n", solution[0][2], solution[0][1]);
	return 0;
}
