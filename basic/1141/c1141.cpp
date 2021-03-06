#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using std::stack;
#define INF 0x3ffffff

int d[110][110];
char data[110];

bool match(char a,char b){
	if((a=='('&&b==')')||(a=='['&&b==']')) return true;
	return false;
}
void print(int i,int j){
	if(i>j) return;
	if(i==j){
		if(data[i]=='('||data[i]==')') printf("()");
		if(data[i]=='['||data[i]==']') printf("[]");
		return;
	}
	int ans=d[i][j];
	if(ans==d[i+1][j-1]&&match(data[i],data[j])){
		printf("%c",data[i]);
		print(i+1,j-1);
		printf("%c",data[j]);
		return;
	}
	for(int k=i;k<j;k++){
		if(ans==d[i][k]+d[k+1][j]){
			print(i,k);
			print(k+1,j);
			return;
		}
	}
}
int main() {
	freopen("in.txt", "r", stdin);

	scanf("%s", data) != EOF;
		int len = strlen(data);
		int i, j, p, k;
		//memset(d, 0 , sizeof(d));
		for(i = 0; i < len; ++i)
			d[i][i] = 1;
		for(i = 1; i < len; ++i)
			d[i][i-1] = 0;
		for(p = 1; p < len; ++p)
			for(i = 0; i < len-p; ++i) {
				j = i + p;
				d[i][j] = INF;
				if(match(data[i], data[j]))
					d[i][j] = d[i+1][j-1];
				if(data[i] == '(' || data[i] == '[') 
					d[i][j] = std::min(d[i+1][j] + 1, d[i][j]);
				if(data[j] == ']' || data[j] == ')')
					d[i][j] = std::min(d[i][j-1] + 1, d[i][j]);
				for(k = i; k < j; ++k)
					d[i][j] = std::min(d[i][j], d[i][k] + d[k+1][j]);
			}
		print(0, len-1);
		printf("\n");
	}

