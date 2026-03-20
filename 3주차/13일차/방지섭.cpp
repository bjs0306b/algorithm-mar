#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
int n,m; 

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num; cin >> num;
            v.push_back({num, i});
        }
    }
    sort(v.begin(), v.end());
}

void solve(){
    int i = 0;
    int ans = INT32_MAX;
    vector<int> cnt(n, 0); // 각 반의 대표선수 수
    int unique = 0; // 대표선수가 속한 반의 수
    for(int j=0;j<v.size();j++){
        int value = v[j].first;
        int class_num = v[j].second;

        if(cnt[class_num]++ == 0) unique++;
        while(unique == n){
            ans = min(ans, v[j].first - v[i].first);
            if(--cnt[v[i].second] == 0)unique--;
            i++;
        }
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}