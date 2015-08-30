#include<cstdio>
#include<cstring>

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char in[80];

	in[0] = '0';

	while(in[0] != '*') {
		scanf("%s\n", in);
		int len = strlen(in);
		int unique = 1;
		while(unique != len) {
			int i = 0;
			while(i < len - unique - 1) {
			}

			++unique;
		}
	}

}
