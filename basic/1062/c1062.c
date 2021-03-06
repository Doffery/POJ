#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<list>
using namespace std;

struct Edge {
	int index;
	int money;
	Edge() {}
	Edge(int x, int y) {
		index = x; money = y;
	}
};

struct TNode{
	int money;
	int level;
	list<Edge> edges;
}nodes[110];

int m, n;
int minMoney;
int minLevel, maxLevel;
void dfs(int p, int money) {
	int s = nodes[p].edges.size();
	list<Edge>::iterator it;
	it = nodes[p].edges.begin();
	for(; it != nodes[p].edges.end(); ++it) {
		if(nodes[it->index].level > minLevel + m 
				|| nodes[it->index].level < maxLevel - m)
			continue;
		int tminl = minLevel, tmaxl = maxLevel;
		if(nodes[it->index].level < minLevel)
			minLevel = nodes[it->index].level;
		else if(nodes[it->index].level > maxLevel)
			maxLevel = nodes[it->index].level;
		if(it->index == 1) {
			if(money + it->money < minMoney)
				minMoney = it->money + money;
		} else dfs(it->index, money + it->money);
		minLevel = tminl; maxLevel = tmaxl;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int i, j;
	int en;
	int tindex, tmoney;
	scanf("%d %d", &m, &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d %d %d", &nodes[i].money, &nodes[i].level, &en);
		nodes[0].edges.push_back(Edge(i, nodes[i].money));
		for(j = 0; j < en; ++j) {
			scanf("%d %d", &tindex, &tmoney);
			//nodes[i].edges.push_back(Edge(tindex, tmoney));
			nodes[tindex].edges.push_back(Edge(i, tmoney));
		}
	}
	minLevel = nodes[1].level;
	minMoney = nodes[1].money;
	dfs(0, 0);
	printf("%d\n", minMoney);

	return 0;
}



