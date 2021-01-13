#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dwarves[9], sum;
    pair<int, int> not_dwarfs;
    
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &dwarves[i]);
    }

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if(i == j) continue;
            sum = 0;
            for (int x = 0; x < 9; x++)
            {
                if(x != i && x != j)
                    sum += dwarves[x];
            }
            if(sum == 100)
            {
                not_dwarfs = make_pair(i,j);
                break;
            }
        }
    
    for (int i = 0; i < 9; i++)
    {
        if(i != not_dwarfs.first && i != not_dwarfs.second)
            printf("%d\n", dwarves[i]);
    }   
    return 0;
}