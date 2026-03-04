// 18513

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

int n, k;
vector<int> pos;

long long getCost(long long n, long long now) {
	return (n + 1)*n / 2 + n * now;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pos.push_back(x);
	}
	sort(pos.begin(), pos.end());
	priority_queue<long long> pq;
	for (int i = 0; i < pos.size() - 1; i++) {
		int x = pos[i] - pos[i + 1] + 1;
		if (x == 0)continue;
		if (x / 2) {
			pq.push(x / 2);
		}
		pq.push(x - x / 2);
	}
	pq.push(-2147483647);
	pq.push(-2147483647);
	long long now = 0;
	long long cnt = 0;
	long long ans = 0;
	while (cnt < k) {
		long long cur = -pq.top();
		long long mul = pq.size();
		pq.pop();
		if (cur - now == 0)continue;
		if (mul*(cur-now) + cnt <= k) {
			long long cost = mul * getCost(cur - now, now);
			//cout << cur << " " << now << " " << mul << "\n";
			cnt += mul * (cur-now);
			ans += cost;
			now = cur;
		}
		else {
			long long toGoLevel = (k - cnt) / mul;
			long long left = (k - cnt) % mul;
			ans += mul * getCost(toGoLevel, now);
			now += toGoLevel;
			ans += (now + 1)*left;
			break;
		}
	}
	cout << ans;

}
