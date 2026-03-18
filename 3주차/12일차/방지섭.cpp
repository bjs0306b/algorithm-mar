#include <bits/stdc++.h>
using namespace std;

int n,m,l,k;
vector<pair<int,int>> v;
void input(){
    cin >> n >> m >> l >> k;
    v.resize(k);
    for(int i=0;i<k;i++){
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }
}

int is_in(int x1, int x2, int y1, int y2){ // 해당 영역에 내에 몇 개의 별똥별이 있는 지 확인
    int ret = 0;
    for(int i=0;i<k;i++){
        int x = v[i].first, y = v[i].second;
        if(x1 <= x && x <= x2 && y1 <= y && y <= y2) ret++;
    }
    return ret;
}

int make_square(int a, int b){ // 두 점을 기준으로 영역을 만듬.
    int min_x = min(v[a].first, v[b].first);
    int max_x = max(v[a].first, v[b].first);
    int min_y = min(v[a].second, v[b].second);
    int max_y = max(v[a].second, v[b].second);

    int cnt1 = is_in(min_x, min_x + l, min_y, min_y + l); // 두 점이 왼쪽 아래로 가게 설치
    int cnt2 = is_in(min_x, min_x + l, max_y - l, max_y); // 두 점이 오른쪽 아래로 가게 설치
    int cnt3 = is_in(max_x - l, max_x, min_y, min_y + l); // 두 점이 왼쪽 위로 가게 설치
    int cnt4 = is_in(max_x - l, max_x, max_y - l, max_y); // 두 점이 오른쪽 위로 가게 설치

    return max(max(cnt1, cnt2), max(cnt3, cnt4));
}


void solve(){
    int mx = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            int cnt = make_square(i, j);
            mx = max(mx, cnt);
        }
    }
    cout << k - mx;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}   