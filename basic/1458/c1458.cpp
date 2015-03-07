#include<cstdio>
#include<cstring>

#define MAXLEN 1000
char strf[MAXLEN];
char strs[MAXLEN];

int cs[MAXLEN][MAXLEN];

int main() {
	freopen("in.txt", "r", stdin);
	while(scanf("%s %s", strf+1, strs+1) != EOF) {
		memset(cs, 0, sizeof(cs));
		int i, j;
		int lenf = strlen(strf+1);
		int lens = strlen(strs+1);
		for(i = 1; i <= lenf; ++i)
			for(j = 1; j <= lens; ++j) {
				if(strf[i] == strs[j]) {
					cs[i][j] = cs[i-1][j-1] + 1;
				}
				else {
					if(cs[i-1][j] > cs[i][j-1])
						cs[i][j] = cs[i-1][j];
					else cs[i][j] = cs[i][j-1];
				}
			}
		printf("%d\n", cs[lenf][lens]);
	}
}
