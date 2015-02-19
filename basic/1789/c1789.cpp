#include<cstdio>
#include<queue>
#include<cstring>

using std::priority_queue;
using std::strlen;

//the smallest spanning tree

char data[10][2010];
int dist[2010][2010];

struct Node{
	int key, value;
	Node() {
	}
	Node(int x, int y) {
		key = x;
		value = y;
	}
	bool operator < (const Node n) const {
		return key > n.key;
	}
};

//priority_queue<Node> nqueue;
bool visit[2010];
int cdist[2010];

int CacuDist(char *a, char *b) {
	int i = 0, c = 0;
	for(; i < 7; ++i)
		if(a[i] != b[i])
			++c;
	return c;
}

int main() {
	std::freopen("in.txt", "r", stdin);
	std::freopen("out.txt", "w", stdout);

	int n, i, j;
	while(scanf("%d", &n) != EOF && n != 0) {
		for(i = 0; i < n; ++i) {
			char in[2010];
			scanf("%s", data[i]);
			dist[i][i] = 8;
			visit[i] = false;
			for(j = 0; j < i; ++j) {
				dist[i][j] = CacuDist(data[i], data[j]);
				dist[j][i] = dist[i][j];
			}
		}

		int m = 0;
		for(i = 0; i < n; ++i) {
			//if(dist[0][i] != 0)
			//	nqueue.push(Node(dist[0][i], i));
			cdist[i] = dist[0][i];
		}
		cdist[0] = 8;
		visit[0] = true;
		//while(!nqueue.empty()) {
		for(i = 1; i < n; ++i) {
			/*Node node = nqueue.top();
			nqueue.pop();
			if(visit[node.value])
				continue;
			m += node.key;
			visit[node.value] = true;
			for(i = 0; i < n; ++i) {
				if(!visit[i])
					nqueue.push(Node(dist[node.value][i], i));
			}*/
			int min = 9, minindex = -1;
			for(j = 0; j < n; ++j) {
				if(!visit[j] && cdist[j] < min) {
					min = cdist[j];
					minindex = j;
				}
			}
			if(minindex != -1) {
				visit[minindex] = true;
				m += cdist[minindex];
				for(j = 0; j < n; ++j) {
					if(cdist[j] > dist[minindex][j])
						cdist[j] = dist[minindex][j];
				}
			}
		}

		printf("The highest possible quality is 1/%d.\n", m);
	}
}
