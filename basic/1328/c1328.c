#include<stdio.h>
#include<math.h>

typedef struct {
	int x, y;
}Point;

Point points[1000 + 10];

int cmp(const void * a, const void * b) {
	return ((Point *)a) -> x - ((Point *) b) -> x;
}
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, d;
	int cases = 0;
	while(scanf("%d %d", &n, &d) && (n != 0 || d != 0)) {
		++ cases;
		int i = 0;
		for(; i < n; ++i) {
			scanf("%d %d", &points[i].x, &points[i].y);
		}

		qsort(points, n, sizeof(Point), cmp);

		int num = 0; i = 0;
		double pd = pow(d, 2);
		double pre = points[0].x;
		while(i < n) {
			if(points[i].y > d || points[i].y < -d) {
				num = -1;
				break;
			}
			double cx = points[i].x + sqrt(pd - pow(points[i].y, 2));
			if(cx < pre)
				--num;
			++i;
			while(pow(points[i].y, 2) + pow(points[i].x - cx, 2) <= pd
					&& i < n)
				++i;
			++num;
			pre = cx;
		}
		printf("Case %d: %d\n", cases, num);
	}

}
