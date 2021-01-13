#include <bits/stdc++.h>

using namespace std;

// MEDIUM problem https://open.kattis.com/problems/speedlimit

int main()
{
    string input;
    
    while(getline(cin, input) && input != "-1")
    {
        int it, speed, t, t0 = 0, dis = 0;
        it = stoi(input);

        for (int i = 0; i < it; i++)
        {
            cin >> speed >> t;
            
            dis += (t-t0)*speed;
            t0 = t;
        }

        cout << dis << " miles" << endl;

        getline(cin, input);
    }
    
    return 0;
}