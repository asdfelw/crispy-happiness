#include <bits/stdc++.h>
using namespace std;
#define ll long long

// MEDIUM problem https://open.kattis.com/problems/standings

int main()
{
    int t, n, pref;
    ll badness;
    string name;
    cin >> t;

    while(t)
    {
        cin >> n;

        vector<int> teams(n);

        for(int i = 0; i < n; i++)
        {
            cin >> name >> pref;
            teams[i] = pref;
        }

        sort(teams.begin(), teams.end());

        badness = 0;
        for(int i = 1; i <= n; i++)
        {
            badness += abs(i-teams[i-1]);
        }

        cout << badness << endl;
        t--;
    }
    
    return 0;
}