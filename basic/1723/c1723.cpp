//think about use the binary search to get the answer
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using std::priority_queue;

struct Position {
	int x, y;
	Position() {}
	Position(int xi, int yi) {
		x = xi; y = yi;
	}
};

bool cmpx(Position a, Position b) {
	return a.x < b.x;
}

bool cmpy(Position a, Position b) {
	return a.y < b.y;
}

int N;
Position data[10010];

int FindMedian(bool xoy) {
	priority_queue<int> heap_max;//low part
	priority_queue<int, std::vector<int>, std::greater<int> > heap_min;//high part
	int n, s = 0;
	int n1, n2;
	if(xoy) {
		n1 = data[0].x;
		n2 = data[1].x;
	} else {
		n1 = data[0].y;
		n2 = data[0].y;
	}
	if(n1 < n2) {
		heap_max.push(n1);
		heap_min.push(n2);
		s += 2 * n1;
	}else {
		heap_max.push(n2);
		heap_min.push(n1);
		s += n1 + n2;
	}
	int i;
	for(i = 2; i < N; ++i) {
		if(xoy)
			n = data[i].x;
		else n = data[i].y;
		if(heap_max.top() >= n) {
			heap_max.push(n);
			if(heap_max.size() > heap_min.size() + 1) {
				heap_min.push(heap_max.top());
				heap_max.pop();
			}
		}
		else if(heap_min.top() <= n) {
			heap_min.push(n);
			if(heap_min.size() > heap_max.size()) {
				heap_max.push(heap_min.top());
				heap_min.pop();
			}
		} else {
			if(heap_max.size() <= heap_min.size()) {
				heap_max.push(n);
			}
			else heap_min.push(n);
		}
	}
	return heap_max.top();
}

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d", &N);
	int i, j;
	for(i = 0; i < N; ++i) {
		scanf("%d %d", &data[i].x, &data[i].y);
	}
	if(N == 1)
		printf("0\n");
	else {
		std::sort(data, data+N, cmpx);

		int moves = 0;
		for(i = 0; i < N; ++i)
			data[i].x -= i;
		int s = FindMedian(true);
		int mid = FindMedian(false);
		for(i = 0; i < N; ++i) {
			moves += std::abs(data[i].x - s);
			moves += std::abs(data[i].y - mid);
		}
		
		printf("%d\n", moves);
	}
}
