#include <bits/stdc++.h>
using namespace std;

int d,n,m;
vector<int> v, dif;
void input(){
    cin >> d >> n >> m;
    v.resize(n+2);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    v[0] = 0;
    v[n+1] = d;
    sort(v.begin(), v.end());
    for(int i=1;i<v.size()-1;i++){
        dif.push_back(v[i] - v[i-1]);
    }
}

void solve(){
    int s = 1, e = d;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;

        int cnt = 0;
        int sum = 0;
        for(int i=0;i<dif.size();i++){
            sum += dif[i];
            if(sum < mid){
                cnt++;
            }
            else{
                sum = 0;
            }
        }

        if(cnt <= m){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
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