#include <bits/stdc++.h>
using namespace std;

// EASY problem https://open.kattis.com/problems/fodelsedagsmemorisering

#define NR_OF_MONTHS 13
#define NR_OF_DAYS 32

bool lex_sort(pair<int, string> a, pair<int, string> b) {return a.second < b.second;}

int main()
{
    int n, u, c, month, day, nr = 0;
    string name;
    char b;

    u=scanf("%d", &n);
    vector<pair<int, string>> friends(NR_OF_MONTHS*NR_OF_DAYS, make_pair(-1, ""));

    for (int i = 0; i < n; i++)
    {
        cin >> name >> c >> day >> b >> month;

        if(friends[month*NR_OF_DAYS + day].first < c) 
        { 
            if(friends[month*NR_OF_DAYS + day].first < 0) 
                nr++;
            friends[month*NR_OF_DAYS + day] = {c, name};
        }
    }

    cout << nr << endl;
    sort(friends.begin(), friends.end(), lex_sort);
    for(int i = (NR_OF_MONTHS*NR_OF_DAYS)-nr; i < (NR_OF_MONTHS*NR_OF_DAYS);i++)
            cout << friends[i].second << endl;
    
    return 0;
}