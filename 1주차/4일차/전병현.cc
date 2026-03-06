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

typedef long long int ll;

using namespace std;

class Exp {
public:
	ll value;
	char oper;
	Exp(ll value, char oper) {
		this->value = value;
		this->oper = oper;
	}
};

ll calc(Exp a, Exp oper, Exp b) {
	switch (oper.oper) {
	case 2:
		return a.value + b.value;
	case 3:
		return a.value - b.value;
	case 4:
		return a.value * b.value;
	case 5:
		return a.value / b.value;
	}
	return -1;
}

bool isFront(Exp fo, Exp ro, ll f, ll r) {
	if ((fo.oper & 4) > (ro.oper & 4)) {
		return true;
	}
	if ((fo.oper & 4) < (ro.oper & 4)) {
		return false;
	}
	return f >= r;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	string str;
	cin >> str;

	//tokenizer
	vector<Exp> exps;
	ll value = 0 ;
	bool firstMinus = 0;
	if (str[0] == '-')firstMinus = 1;
	for (int i = firstMinus; i < str.size();i++) {
		char x = str[i];
		if (x >= '0' && x <= '9') {
			value *= 10;
			value += (x - '0');
		}
		else {
			if (firstMinus) {
				firstMinus = 0;
				value *= -1;
			}
			exps.push_back(Exp{ value, 0 });
			switch (x) {
			case '+':
				x = 2;
				break;
			case '-':
				x = 3;
				break;
			case '*':
				x = 4;
				break;
			case '/':
				x = 5;
				break;
			}
			exps.push_back(Exp{ 0, x });
			value = 0;
		}
	}
	if (firstMinus) {
		value *= -1;
	}
	exps.push_back(Exp{ value, 0 });
	int s = 0;
	int e = exps.size() - 1;
	while (e != s) {
		ll f = calc(exps[s], exps[s + 1], exps[s + 2]);
		ll r = calc(exps[e - 2], exps[e - 1], exps[e]);
		if (isFront(exps[s+1], exps[e-1], f, r)) {
			s += 2;
			exps[s].value = f;
		}
		else {
			e -= 2;
			exps[e].value = r;
		}
	}
	cout << exps[s].value;
}

