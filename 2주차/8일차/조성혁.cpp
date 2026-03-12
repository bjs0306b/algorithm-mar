#include <iostream>
#include <vector>
#include <queue>

#define INF 1e10

using namespace std;
typedef long long ll;
typedef pair<int,ll> pill;
typedef pair<ll,int> plli;

int status[100001];
ll dist[100001];
vector<pill> graph[100001];

int main() {
    int n,m;
    cin>>n>>m;

    for (int i=0;i<n;i++) {
        cin>>status[i];
        dist[i]=INF;
    }

    for (int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;

        if (a!=n-1&&status[a]) continue;
        if (b!=n-1&&status[b]) continue;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    priority_queue<plli,vector<plli>,greater<>> pq;
    dist[0]=0;
    pq.push({dist[0],0});

    while (!pq.empty()) {
        int x=pq.top().second;
        ll w=pq.top().first;
        pq.pop();

        if (dist[x]<w) continue;

        for (int i=0;i<graph[x].size();i++) {
            int y=graph[x][i].first;
            ll nw=graph[x][i].second;

            if (dist[y]>w+nw) {
                dist[y]=w+nw;
                pq.push({dist[y],y});
            }
        }
    }

    if (dist[n-1]==INF) cout<<-1;
    else cout<<dist[n-1];
}
