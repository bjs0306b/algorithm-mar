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
	int n;
	cin >> n;
	/*
	1
	4	3
	9	5
	16	7
	25	9
	...	...
	몸무게는 오른쪽 순열의 연속합 중 아무거나 G가 되는 위치이다.
	*/
	deque<int> v;
	long long int sum = 0;
	bool flag = true;
	for (int i = 2; i < 60000; i++) {
		sum += 2 * i - 1;
		v.push_back(2 * i - 1);
		while (sum >= n) {
			if (sum == n) {
				flag = false;
				cout << i << "\n";
			}
			sum -= v.front();
			v.pop_front();
		}
	}
	if (flag)cout << -1;
}
