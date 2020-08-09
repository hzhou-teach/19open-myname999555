/*
* Jeffrey Chen
* Time: 15 minutes
* Test Cases: 10/10
* Difficulty: 4/10
* This was a simple unionfind while keeping track of the minimum and maximum x and y values.
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<vector<int>> graph(100005);
vector<pii> cowPos(100005);
bool vis[100005];
int maxX;
int minX;
int maxY;
int minY;

void dfs(int cow) {
	if (vis[cow]) return;
	maxX = max(maxX, cowPos[cow].first);
	minX = min(minX, cowPos[cow].first);
	maxY = max(maxY, cowPos[cow].second);
	minY = min(minY, cowPos[cow].second);
	vis[cow] = true;
	for (int node : graph[cow]) {
		dfs(node);
	}
}

int unionFind() {
	int best = 1e9;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			maxX = -1e8;
			minX = 1e8;
			maxY = -1e8;
			minY = 1e8;
			dfs(i);
			best = min(best, 2 * (maxX - minX + maxY - minY));
		}
	}
	return best;
}

int main(int argc, char* argv[]) {
	const char* FIN = "fenceplan.in";
	const char* FOUT = "fenceplan.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		cowPos[i] = make_pair(x, y);
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	cout << unionFind() << endl;

	return 0;
}
