#include<cstdio>
#include<stack>

using std::stack;

int sequence[1010];

int main() {
	freopen("in.txt", "r", stdin);

	int n;
	while(scanf("%d", &n) != EOF && n) {
		while(true) {
			int i, j = 0, k;
			stack<int> s;
			bool ch = true;
			scanf("%d", &sequence[0]);
			if(sequence[0] == 0)
				break;
			for(i = 1; i < n; ++i) {
				scanf("%d", &sequence[i]);
			}
			for(i = 0; i < n; ++i) {
				k = sequence[i];
				if(j < k) {
					for(j++; j < k; ++j)
						s.push(j);
					j = k;
				} else if(j >= k) {
					if(s.top() == k)
						s.pop();
					else {
						ch = false;
						break;
					}
				}
			}
			if(ch)
				printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
}
