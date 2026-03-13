#include <bits/stdc++.h>
using namespace std;

long long n,m;
bool is_visible[100000];
vector<pair<long long,long long>> v[100000];
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
void input(){
    cin >> n >> m;
    for(long long i=0;i<n;i++){
        long long num; cin >> num;
        if(num) if(i != n-1) is_visible[i] = true;
        else is_visible[i] = false;
    }
    for(long long i=0;i<m;i++){
        long long a,b,c; cin >> a >> b >> c;
        if(!is_visible[a] && !is_visible[b]){ // 둘 다 상대한테 안보일 때
            v[a].push_back({c,b});
            v[b].push_back({c,a});
        }
    }


}

void solve(){
    vector<long long> dis(n, INT64_MAX);
    dis[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();

        long long cur_cost = t.first, cur_pos = t.second;
        if(cur_cost > dis[cur_pos]) continue;

        for(auto k : v[cur_pos]){
            long long next_cost = k.first, next_pos = k.second;
            if(dis[next_pos] > dis[cur_pos] + next_cost){
                dis[next_pos] = dis[cur_pos] + next_cost;
                pq.push({dis[next_pos], next_pos});
            }
        }
    }
    if(dis[n-1] == INT64_MAX) cout << -1;
    else cout << dis[n-1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}