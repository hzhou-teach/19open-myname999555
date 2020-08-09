/*
* Jeffrey Chen
* Time: 3 hours
* Test Cases: 5/12
* Difficulty: 10/10
* This was a really weird ad hoc problem, I didn't really know how to 
* solve it, since none of the standard techniques worked. I wouldn't have 
* spent this long on the real contest, but I really wanted to solve it 
* while practicing.
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
int n;
char arr[1003][1003];


int main(int argc, char* argv[]) {
	const char* FIN = "leftout.in";
	const char* FOUT = "leftout.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			arr[i][j] = s[j];
			cnt += (s[j] == 'R');
		}
	}

	if (n == 2) {
		if (cnt % 2 == 1) {
			cout << 1 << " " << 1 << endl;
			return 0;
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	if (cnt == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] == 'R') {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	if (cnt == n*n-1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] == 'L') {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	int totalCnt = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			int lCnt = 0;
			for (int k = i; k <= i + 1; ++k) {
				for (int l = j; l <= j + 1; ++l) {
					lCnt += (arr[k][l] == 'R');
				}
			}
			if (lCnt % 2 == 1) {
				v.push_back(make_pair(i, j));
				++totalCnt;
			}
		}
	}
	if (totalCnt == 0 || totalCnt >= 5) {
		cout << -1 << endl;
		return 0;
	}
	if (totalCnt == 1) {
		cout << v[0].first + 1 << " " << v[0].second +1<< endl;
		return 0;
	}
	if (totalCnt == 2) {
		if (v[0].first + 1 == v[1].first && v[0].second == v[1].second) {
			cout << v[0].first + 2 << " " << v[1].second + 1 << endl;
			return 0;
		}
		else if (v[0].first == v[1].first && v[0].second + 1 == v[1].second) {
			cout << v[0].first + 1 << " " << v[1].second + 1 << endl;
		}
		else {
			return 0;
		}
	}
	if (totalCnt == 3) {
		if (v[0].first != v[1].first && v[0].second + 1 != v[1].second
			&& v[0].first + 1 != v[2].first && v[0].second != v[1].second) {
			cout << v[0].first + 2 << " " << v[0].second + 2 << endl;
			return 0;
		}
		else if (v[0].first != v[1].first && v[0].second + 1 != v[1].second
			&& v[1].first + 1 != v[2].first && v[1].second != v[1].second) {
			cout << v[0].first + 2 << " " << v[0].second + 2 << endl;
			return 0;
		}
		else if (v[0].first+1 != v[1].first && v[0].second != v[1].second
			&& v[1].first != v[2].first && v[1].second+1 != v[1].second) {
			cout << v[0].first + 2<< " " << v[0].second + 2 << endl;
			return 0;
		}
		else if (v[0].first + 1 != v[2].first && v[0].second != v[2].second
			&& v[1].first != v[2].first && v[1].second + 1 != v[1].second) {
			cout << v[0].first + 1 << " " << v[0].second + 2 << endl;
			return 0;
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	if (totalCnt == 4) {
		if (v[0].first != v[1].first || v[0].second + 1 != v[1].first
			|| v[0].first + 1 != v[2].first || v[0].second != v[1].second
			|| v[2].first != v[3].first || v[2].second + 1 != v[3].first) {
			cout << -1 << endl;
			return 0;
		}
		else {
			cout << v[0].first + 2 << " " << v[0].second + 2 << endl;
			return 0;
		}
	}
	return 0;
}