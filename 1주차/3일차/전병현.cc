#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>

using namespace std;
int n, a, b;

int tc() {
	cin >> n >> a >> b;
	if (n == 0 && a == 0 && b == 0)return 0;
	int ans = 0;
	priority_queue<pair<pair<int,int>, pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		int k, ad, bd;
		cin >> k >> ad >> bd;
		pq.push({ {abs(ad - bd), k}, {ad, bd } });
	}
	while (pq.size()) {
		int ad = pq.top().second.first;
		int bd = pq.top().second.second;
		int k = pq.top().first.second;
		pq.pop();
		int far = max(ad, bd);
		int near = min(ad, bd);
		int &farx = (ad > bd) ? a : b;
		int &nearx = (ad > bd) ? b : a;
		int use = min(k, nearx);
		ans += use * near;
		k -= use;
		nearx -= use;
		ans += k * far;
		farx -= k;
	}
	cout << ans << "\n";
	return 1;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	while (tc());
}

