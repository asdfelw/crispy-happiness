#include <bits/stdc++.h>
using namespace std;

// MEDIUM problem https://open.kattis.com/problems/jackpot

int gcd(int a, int b)
{
    int temp;
    while(b > 0)
    {
        temp = b;
        b = a % b;
        a = temp;    
    }
    return a;
}

int main()
{
    int n, w, u;
    long long per;
    vector<int> p(5);

    u=scanf("%d", &n);

    while(n--)
    {
        u=scanf("%d", &w);    

        for(int i = 0; i < w; i++)
            u=scanf("%d", &p[i]);
        per = p[0];
        
        for(int i = 1; i < w && per < 1000000000; i++)
            {
                per = (per*p[i])/gcd(per, p[i]);
            }
        if(per <= 1000000000)
            printf("%lld\n", per);
        else
            printf("More than a billion.\n");
    }
    return 0;
}