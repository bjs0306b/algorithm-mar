#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree, v;

int build(int idx, int s, int e){
    if(s == e) return tree[idx] = v[s];
    int m = (s+e)/2;
    int ss = build(idx*2, s, m), ee = build(idx*2+1, m+1, e);
    return tree[idx] = ss + ee;
}

int update(int idx, int s, int e, int target_idx, int add_num){
    if(s == e){
        return tree[idx] = tree[idx] + add_num;
    }
    int m = (s+e)/2;
    if(m < target_idx){ // 오른쪽만 업데이트
        return tree[idx] = tree[2*idx] + update(idx*2+1, m+1, e, target_idx, add_num);
    }
    else{ // 왼쪽만 업데이트
        return tree[idx] = tree[2*idx+1] + update(idx*2, s, m, target_idx, add_num);
    }
}

int query(int idx, int s, int e, int th){
    if(s == e){
        update(1, 1, 1000000, s, -1);
        return s;
    }
    int m = (s+e)/2;
    if(tree[2*idx] < th) return query(idx*2+1, m+1, e, th - tree[2*idx]); // 왼쪽 등수 합이 원하는 등수보다 작으면 오른쪽으로
    else return query(idx*2, s, m, th); // 크거나 같으면 왼쪽으로
}


void input(){
    cin >> n;
    v.resize(1000000, 0);
    tree.resize(4000000);
    build(1, 1, 1000000); 
}

void solve(){
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a;
        if(a == 1){
            cin >> b;
            cout << query(1, 1, 1000000, b) << '\n';
        }
        else if(a == 2){
            cin >> b >> c;
            update(1, 1, 1000000, b, c);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}