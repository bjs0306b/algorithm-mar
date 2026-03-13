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

queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int d, n, m;
	cin >> d >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int s = 1;
	int e = d;
	int ans=0;
	while (s <= e) {
		int mi = (s + e) / 2;
		// stone - stone 간격 m 미만이면 전부 배제
		int cnt = 0;
		int prev = 0;
		int mini = 2147483647;
		for (int x : v) {
			if (x - prev >= mi) {
				mini = min(mini, x - prev);
				cnt++;
				prev = x;
			}
		}
		if (d - prev < mi) {
			cnt++;
		}

		if (n - cnt <= m) {
			ans = max(ans, mi);
			s = mi + 1;
		}
		else {
			e = mi - 1;
		}
	}
	cout << ans;
}
