#include <bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1001];
int ans = 0;
deque<int> dq, ans_dq;
int mx[1001];
vector<pair<int,int>> v[1001];
void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
}

void dfs(int dep, int num, int sum){
    if(dep > 0 && num == 1){
        if(ans < sum){
            ans = sum;
            ans_dq = dq;
        }
        return;
    }

    for(auto k : v[num]){
        if(visited[k.first]) continue;
        if(mx[k.first] >= sum + k.second) continue;
        mx[k.first] = sum + k.second;

        dq.push_back(k.first);
        visited[k.first] = true;

        dfs(dep+1, k.first, sum + k.second);

        dq.pop_back();
        visited[k.first] = false;
    }
}

void solve(){
    dq.push_back(1);
    dfs(0, 1, 0);
    cout << ans << "\n";
    for(auto k : ans_dq) cout << k << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}