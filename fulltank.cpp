#include <bits/stdc++.h>
using namespace std;

#define INF 9999999
typedef pair<int, int> intpair;

//HARD problem https://open.kattis.com/problems/fulltank

int n, m;

struct edge {
    int city;
    int gas;
    int len;

    edge(int c1, int g1, int p1) : city(c1), gas(g1), len(p1){}

    bool operator<(const struct edge& other) const
    {
        return len > other.len;
    }
};

int dijkstras(int capacity, int start, int goal, vector<vector<edge>> roads, vector<int> fuel_price)
{
    vector<vector<int>> dist(n, vector<int>(capacity+1, INF));
    priority_queue<edge> pq;

    pq.push(edge(start, 0, 0));
    dist[start][0] = 0;

    while(!pq.empty())
    {
        edge u = pq.top();
        pq.pop();

        if(u.city == goal) return u.len;

        if(dist[u.city][u.gas] < u.len) continue;

        if(u.gas < capacity && u.len + fuel_price[u.city] < dist[u.city][u.gas+1])
        {
            dist[u.city][u.gas+1] = u.len + fuel_price[u.city];
            pq.push(edge(u.city, u.gas+1, u.len + fuel_price[u.city]));
        }
        
        for(auto road : roads[u.city])
        {
            int town = road.city, dis = road.len;
            if(u.gas >= dis)
            {
                int new_gas = u.gas - dis;
                if(u.len < dist[town][new_gas])
                {
                    dist[town][new_gas] = u.len;
                    pq.push(edge(town, new_gas, u.len));
                }
            }
        }
    }

    return -1;
}

int main()
{

    int sc, q, c, s, e, price;

    sc =scanf("%d %d", &n, &m);

    vector<vector<edge>> roads(n);
    vector<int> fuel_price(n);
    
    for (int i = 0; i < n; i++)
    {
        sc=scanf("%d",&fuel_price[i]);
    }

    for (int i = 0; i < m; i++)
    {
        sc=scanf("%d %d %d", &s, &e, &c);
        roads[s].push_back(edge(e,0,c));
        roads[e].push_back(edge(s,0,c));
    }

    sc=scanf("%d",&q);

    for (int i = 0; i < q; i++)
    {
        sc=scanf("%d %d %d", &c, &s, &e);
        
        int cheapest_trip = dijkstras(c,s,e,roads,fuel_price);

        if(cheapest_trip < 0)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n", cheapest_trip);
        }

    }
    return 0;
}