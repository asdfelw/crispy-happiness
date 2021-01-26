#include <bits/stdc++.h>
using namespace std;

// MEDIUM problem https://open.kattis.com/problems/dungeon

#define INF 999999

struct point {
    int l,r,c;

    point(int l1, int r1, int c1) : l(l1), r(r1), c(c1){}

    point() : l(0), r(0), c(0){}
};

bool in_bound(int l, int r, int c, int maxl, int maxr, int maxc)
{
    return (l >= 0 && l < maxl && r >= 0 && r < maxr && c >= 0 && c < maxc);
}

int bfs(vector<vector<vector<int>>> dungeon, point s, point e, int maxl, int maxr, int maxc)
{
    queue<point> q;
    q.push(s);
    dungeon[s.l][s.r][s.c] = 0;

    while(!q.empty())
    {
        point u = q.front();
        q.pop();

        if(u.l == e.l && u.r == e.r && u.c == e.c) return dungeon[u.l][u.r][u.c];

        if(in_bound(u.l+1, u.r, u.c, maxl, maxr, maxc) && dungeon[u.l+1][u.r][u.c] == -1)
        {
            q.push(point(u.l+1, u.r, u.c));
            dungeon[u.l+1][u.r][u.c] = dungeon[u.l][u.r][u.c]+1;
        }

        if(in_bound(u.l-1, u.r, u.c, maxl, maxr, maxc) && dungeon[u.l-1][u.r][u.c] == -1)
        {
            q.push(point(u.l-1, u.r, u.c));
            dungeon[u.l-1][u.r][u.c] = dungeon[u.l][u.r][u.c]+1;
        }

        if(in_bound(u.l, u.r+1, u.c, maxl, maxr, maxc) && dungeon[u.l][u.r+1][u.c] == -1)
        {
            q.push(point(u.l, u.r+1, u.c));
            dungeon[u.l][u.r+1][u.c]  = dungeon[u.l][u.r][u.c]+1;
        }

        if(in_bound(u.l, u.r-1, u.c, maxl, maxr, maxc) && dungeon[u.l][u.r-1][u.c] == -1)
        {
            q.push(point(u.l, u.r-1, u.c));
            dungeon[u.l][u.r-1][u.c] = dungeon[u.l][u.r][u.c]+1;
        }

        if(in_bound(u.l, u.r, u.c+1, maxl, maxr, maxc) && dungeon[u.l][u.r][u.c+1] == -1)
        {
            q.push(point(u.l, u.r, u.c+1));
            dungeon[u.l][u.r][u.c+1] = dungeon[u.l][u.r][u.c]+1;
        }

        if(in_bound(u.l, u.r, u.c-1, maxl, maxr, maxc) && dungeon[u.l][u.r][u.c-1] == -1)
        {
            q.push(point(u.l, u.r, u.c-1));
            dungeon[u.l][u.r][u.c-1] = dungeon[u.l][u.r][u.c]+1;
        }

    }

    return -1;
}

int main()
{
    int l,r,c,time;
    char in;
    point start, end;
    scanf("%d %d %d", &l, &r, &c);

    while(l && r && c)
    {
        // dungeon 
        // - l levels
        //   - r rows with c characters

        vector<vector<vector<int>>> dungeon(l, vector<vector<int>>(r, vector<int>(c, -1)));

        scanf("%c", &in); 

        for(int ll = 0; ll < l; ll++)
        {
            for(int rr = 0; rr < r; rr++)
            {
                for(int cc = 0; cc < c; cc++)
                {
                    scanf("%c", &in);
                    if(in == '#')
                        dungeon[ll][rr][cc] = -2;
                    if(in == 'S')
                        start = {.l = ll, .r = rr, .c = cc};
                    if(in == 'E')
                        end = {.l = ll, .r = rr, .c = cc};
                }
                scanf("%c", &in);
            }
            scanf("%c", &in);
        }

        time = bfs(dungeon, start, end, l, r, c);

        if(time < 0)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", time);

        scanf("%d %d %d", &l, &r, &c);
    }
    return 0;
}