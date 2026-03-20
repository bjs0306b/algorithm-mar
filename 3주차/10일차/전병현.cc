#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> e[1001], re[1001];
	for (int i = 0; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({ b, c });
		e[b].push_back({ a, c });
		re[a].push_back({ b, !c });
		re[b].push_back({ a, !c });
	}
	priority_queue<pair<int,int>> q;
	q.push({ -1,0 });
	int count1 = 0;
	int visited[1001]{ 0 };
	while (q.size()) {
		int nw = -q.top().first;
		int nv = q.top().second;
		q.pop();
		if (visited[nv])continue;
		visited[nv] = 1;
		count1 += !nw;
		for (auto x : e[nv]) {
			if (visited[x.first])continue;
			q.push({ -x.second, x.first });
		}
	}
	q.push({ 0,0 });
	int count2 = 0;
	int visited2[1001]{ 0 };
	while (q.size()) {
		int nw = -q.top().first;
		int nv = q.top().second;
		q.pop();
		if (visited2[nv])continue;
		visited2[nv] = 1;
		count2 += nw;
		for (auto x : re[nv]) {
			if (visited2[x.first])continue;
			q.push({ -x.second, x.first });
		}
	}


	cout << count1 * count1 - count2*count2;
}
