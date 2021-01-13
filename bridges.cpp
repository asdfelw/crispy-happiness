#include <bits/stdc++.h>
using namespace std;

#define INF 999999
typedef pair<int, int> intpair;

// MEDIUM problem https://open.kattis.com/problems/bryr

int main()
{
    // 2 <= n <= 100000
    // n-1 <= m <= min(200000, n*(n-1)/2)
    int n, m, a, b, c, u;
    u=scanf("%d", &n);
    u=scanf("%d", &m);
    int start = 0;

    vector<vector<intpair>> bridges(n);
    vector<int> dist(n, INF);
    vector<int> visited(n, 0);

    for (int i = 0; i < m; i++)
    {
        u=scanf("%d", &a);
        u=scanf("%d", &b);
        u=scanf("%d", &c);
        bridges[a-1].push_back(make_pair(b-1, c));
        bridges[b-1].push_back(make_pair(a-1, c));
    }
    priority_queue<intpair, vector<intpair>, greater<intpair>> pq;
    
    pq.push(make_pair(0,start));
    dist[start] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(visited[u]) 
            continue;
        visited[u] = 1;

        for(auto edge : bridges[u])
        {
            int town = edge.first, cost = edge.second;
            if(dist[u]+cost < dist[town])
            {
                dist[town] = dist[u]+cost;
                pq.push(make_pair(dist[town], town));
            }
        }
    }
    
    printf("%d\n", dist[n-1]);

    return 0;
}