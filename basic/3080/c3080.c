//Find the longest common sequence
#include<stdio.h>
#include<string.h>

#define BL 60

char data[10][65];
int maxLen[10][65];
int dpLen[61][61];

void ComputeLS(int index) {
	int i, j;
	for(i = 0; i < BL; ++i)
		if(data[0][i] == data[index][0])
			dpLen[i][0] = 1;
		else dpLen[i][0] = 0;
	for(i = 1; i < BL; ++i)
		if(data[0][0] == data[index][i])
			dpLen[0][i] = 1;
		else dpLen[0][i] = 0;
	for(i = 1; i < BL; ++i)
		for(j = 1; j < BL; ++j)
			if(data[0][i] == data[index][j])
				dpLen[i][j] = dpLen[i-1][j-1] + 1;
			else dpLen[i][j] = 0;
	for(i = 0;i < BL; ++i) {
		int max = 0;
		for(j = 0; j < BL; ++j)
			if(dpLen[i][j] > max)
				max = dpLen[i][j];
		maxLen[index][i] = max;
	}
	return;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, m, i, j, k, l;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		for(i = 0; i < m; ++i) {
			scanf("%s", data[i]);
		}

		//compare the 0th sequence with every other
		for(i = 1; i < m; ++i) {
			ComputeLS(i);
		}

		//get the longest
		int longest = 0, index = 0;
		for(i = 0; i < BL; ++i) {
			int min = 60;
			for(j = 1; j < m; ++j)
				if(maxLen[j][i] < min)
					min = maxLen[j][i];
			if(min > longest) {
				longest = min;
				index = i;
			} else if(min == longest) {
				if(strncmp(data[0]+i-min+1,
						   	data[0]+index-longest+1, min) < 0) {
					longest = min;
					index = i;
				}
			}
		}
		if(longest > 2) {
			char result[61];
			strncpy(result, data[0] + index - longest + 1, longest);
			result[longest] = '\0';
			printf("%s\n", result);
		}
		else printf("no significant commonalities\n");
	}

}
