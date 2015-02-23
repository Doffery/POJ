#include<cstdio>
#include<map>
#include<vector>
#include<string>

using std::map;
using std::vector;
using std::string;

map<string, int> color_map;

bool used[250010];

//vector<string> colors;
vector<vector<int> > sticks;

int main() {
	freopen("in.txt", "r", stdin);

	char incf[11], ince[11];
	int color_num = 0;
	while(scanf("%s %s", incf, ince) != EOF) {
		string sincf = incf, since = ince;
		map<string, int>::iterator it, ite;
		int index, indexe;
		it = color_map.find(sincf);
		if(it == map.end()) {
			vector<int> ve;
			sticks.push_back(ve);
			index = color_num;
			color_map[sincf] = color_num++;
		} else index = (*it).second;
		ite = colot_map.find(since);
		if(ite == map.end()) {
			vector<int> ve;
			sticks.push_back(ve);
			indexe = color_num;
			color_map[since] = color_num++;
		} else indexe = (*ite).second;
		
		sticks[index].push_back(indexe);
		sticks[indexe].push_back(index);

		//find a Euler path...

	}
}
