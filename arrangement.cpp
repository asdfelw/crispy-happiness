#include <bits/stdc++.h>
using namespace std;

// EASY problem https://open.kattis.com/problems/upprodun

int main()
{
    int n, m, u;

    u = scanf("%d %d", &n, &m);

    vector<int> rooms(n,m/n);

    u = m%n;

    for(int i = 0; i < n; i++)
    {
        if(u > 0) 
        {
            rooms[i] +=1;
            u--;
        }

        while(rooms[i] > 0) 
        {
            printf("*");
            rooms[i]--;
        }
        printf("\n");
    }
    
    return 0;
}