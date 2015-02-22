#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char fWord[11];
	char eWord[11];
}DictItem;

DictItem dItems[100000];

int cmp(const void *a, const void *b) {
	return strcmp(((DictItem *)a)->fWord, ((DictItem *)b)->fWord);
}

int cmp2(const void *a, const void *b) {
	return strcmp((char *)a, ((DictItem *)b)->fWord);
}

int main() {
	freopen("in.txt", "r", stdin);

	DictItem di;

	int n = 0;
	char cline;
	int i = 0, j = 0;
	while(scanf("%c", &cline) && cline != '\n') {
		i = 0;
		dItems[n].eWord[i++] = cline;
		while(scanf("%c", &cline) && cline != ' ') {
			dItems[n].eWord[i++] = cline;
		}
		dItems[n].eWord[i] = '\0';
		i = 0;
		while(scanf("%c", &cline) && cline != '\n') {
			dItems[n].fWord[i++] = cline;
		}
		dItems[n].fWord[i] = '\0';
		//dItems[n] = di;// Is this OKAY?
		++n;
	}

	qsort(dItems, n, sizeof(di), cmp);
	
	//char wordD[11];
	while (scanf("%s", di.fWord) != EOF) {
		DictItem *d;
		d = (DictItem *) bsearch(&di, dItems, n, sizeof(di), cmp);
		if(d != NULL) printf("%s\n", d->eWord);
		else printf("eh\n");
	}

}
