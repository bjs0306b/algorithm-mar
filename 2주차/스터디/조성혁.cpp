#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    string cmd;
    cin>>n>>k>>cmd;

    // 현재 좌표가 (a, b)일 때,
    // A: x>a && x-y==a-b인 좌표 중 가장 작은 x좌표를 가진 좌표 == a-b인 좌표들 중 upper_bound
    // B: x>a && x+y==a+b인 좌표 중 가장 작은 x좌표를 가진 좌표 == a+b인 좌표 중 upper_bound
    // C: x<a && x+y==a+b인 좌표 중 가장 큰 x좌표를 가진 좌표 == a+b인 좌표 중 lower_bound-1
    // D: x<a && x-y==a-b인 좌표 중 가장 큰 x좌표를 가진 좌표 == a-b인 좌표 중 lower_bound-1
    // 를 찾는다.
    // '가깝다'는 것은 방향에 위치하면서 x 또는 y좌표가 가장 작은 또는 큰 좌표를 말함.

    int x,y;
    vector<pair<int,int>> v;
    map<int,set<pair<int,int>>> plus,minus;
    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;

        if (i==0) {
            x=a;
            y=b;
        }

        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    for (int i=0;i<n;i++) {
        int a=v[i].first;
        int b=v[i].second;

        plus[a+b].insert({a,b});
        minus[a-b].insert({a,b});
    }

    for (int i=0;i<k;i++) {
        char c=cmd[i];

        // 1사분면
        if (c=='A') {
            auto minusIter=minus[x-y].lower_bound(make_pair(x,y));
            auto plusIter=plus[x+y].lower_bound(make_pair(x,y));
            auto nxtIter=minus[x-y].upper_bound(make_pair(x,y));

            if (nxtIter==minus[x-y].end()) continue;

            int nx=nxtIter->first;
            int ny=nxtIter->second;

            minus[x-y].erase(minusIter);
            plus[x+y].erase(plusIter);

            x=nx;
            y=ny;
        }
        // 4사분면
        else if (c=='B') {
            auto minusIter=minus[x-y].lower_bound(make_pair(x,y));
            auto plusIter=plus[x+y].lower_bound(make_pair(x,y));
            auto nxtIter=plus[x+y].upper_bound(make_pair(x,y));

            if (nxtIter==plus[x+y].end()) continue;

            int nx=nxtIter->first;
            int ny=nxtIter->second;

            minus[x-y].erase(minusIter);
            plus[x+y].erase(plusIter);

            x=nx;
            y=ny;
        }
        // 2사분면
        else if (c=='C') {
            auto minusIter=minus[x-y].lower_bound(make_pair(x,y));
            auto plusIter=plus[x+y].lower_bound(make_pair(x,y));
            auto nxtIter=prev(plusIter);

            if (plusIter==plus[x+y].begin()) continue;

            int nx=nxtIter->first;
            int ny=nxtIter->second;

            minus[x-y].erase(minusIter);
            plus[x+y].erase(plusIter);

            x=nx;
            y=ny;
        }
        // 3사분면
        else {
            auto minusIter=minus[x-y].lower_bound(make_pair(x,y));
            auto plusIter=plus[x+y].lower_bound(make_pair(x,y));
            auto nxtIter=prev(minusIter);

            if (minusIter==minus[x-y].begin()) continue;

            int nx=nxtIter->first;
            int ny=nxtIter->second;

            minus[x-y].erase(minusIter);
            plus[x+y].erase(plusIter);

            x=nx;
            y=ny;
        }
    }

    cout<<x<<' '<<y;
}
