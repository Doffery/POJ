#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int change;//the last five bits related to the state of pqrst
char inc[100 + 10];
int ind;
int CacuChar() {
	int t1, t2;
	switch(inc[ind++]) {
		case 'p':
			return (change >> 0) & 1;
		case 'q':
			return (change >> 1) & 1;
		case 'r':
			return (change >> 2) & 1;
		case 's':
			return (change >> 3) & 1;
		case 't':
			return (change >> 4) & 1;

		case 'K':
			t1 = CacuChar(); t2 = CacuChar();
			return t1 && t2;
		case 'A':
			t1 = CacuChar(); t2 = CacuChar();
			return t1 || t2;
		case 'N':
			return !CacuChar();
		case 'C':
			t1 = CacuChar(); t2 = CacuChar();
			return t1 >= t2;
		case 'E':
			t1 = CacuChar(); t2 = CacuChar();
			return t1 == t2;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char *stp = "0";
	while (scanf("%s", inc) != EOF){
		if(!strcmp(inc, stp))
			break;
		int len = strlen(inc);

		//int i;
		//for(i = 0; i < len; ++i) {
		//	if(inc[i] <= 'p');
		//}
		bool t = true;
		for(change = 0; change < 32; ++change) {
			ind = 0;
			if(!CacuChar()) {
				t = false;
				break;
			}
		}
		if(t)
			printf("tautology\n");
		else printf("not\n");
	}
}
