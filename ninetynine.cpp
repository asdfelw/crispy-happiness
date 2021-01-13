#include <bits/stdc++.h>
using namespace std;

// MEDIUM problem https://open.kattis.com/problems/ninetynine

int main()
{
    int input, score = 0;

    cout << 1;

    while(score < 99)
    {
        cout << endl;
        cin >> input;

        if(input == 99) {
            return 0;
        }

        if(input % 3 == 2) 
        {
            score = input + 1;
        }
        else //(input % 3 == 1) or (input % 3 == 0) 
        {
            score = input + 2;
        }
        cout << score;
    }
    return 0;
}