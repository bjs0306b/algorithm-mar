#include <iostream>

#define SIZE 1000000

using namespace std;

int tree[4*SIZE+1]; // 구간: 값의 범위, 해당하는 수의 개수를 저장한다.

void update(int node,int left,int right,int idx,int diff) {
    if (idx<left||right<idx) return;

    tree[node]+=diff;
    if (left==right) return;

    int mid=(left+right)>>1;

    if (left<=idx&&idx<=mid) {
        update(node*2,left,mid,idx,diff);
    }
    else {
        update(node*2+1,mid+1,right,idx,diff);
    }
}

int kth(int node,int left,int right,int k) {
    if (left==right) return left;

    int mid=(left+right)>>1;
    int leftCnt=tree[node*2];

    if (k<=leftCnt) {
        return kth(node*2,left,mid,k);
    }
    else {
        return kth(node*2+1,mid+1,right,k-leftCnt);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for (int i=0;i<n;i++) {
        int cmd;
        cin>>cmd;

        if (cmd==1) {
            int a;
            cin>>a;
            int ret=kth(1,1,SIZE,a);
            cout<<ret<<"\n";
            update(1,1,SIZE,ret,-1);
        }
        else {
            int a,b;
            cin>>a>>b;
            update(1,1,SIZE,a,b);
        }
    }
}
