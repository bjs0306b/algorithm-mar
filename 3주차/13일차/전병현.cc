#include <bits/stdc++.h>
using namespace std;


int n, m;
priority_queue<int> classes[1001];
int ans = 2147483647;
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            classes[i].push(x);
        }
    }
    int mini = 2147483647;
    priority_queue<pair<int,int>> pq;
    for (int i=0;i<n;i++)
    {
        int x = classes[i].top();
        pq.push({x, i});
        mini = min(mini, x);
    }
    while (1)
    {
        ans = min(pq.top().first - mini, ans);
        int nv = pq.top().second;
        pq.pop();
        if (classes[nv].size())
        {
            mini = min(mini, classes[nv].top());
            pq.push({classes[nv].top(), nv});
            classes[nv].pop();
        }else
        {
            cout<<ans;
            return 0;
        }
    }
}





















