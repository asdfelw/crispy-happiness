#include <bits/stdc++.h>
using namespace std;

// MEDIUM problem https://open.kattis.com/problems/martiandna

int main()
{
    // n length of dna
    // k alphabet size
    // r nucleobases for minimum quantity req
    int n, k, r, b, start = 0, reqlen=0, min_start=-1, minlen =200001, found = 0;

    cin >> n >> k >> r;

    int *dna = new int[n];
    int *alph = new int[k];
    int *reqs = new int[k];

    for (int i = 0; i < k; i++)
    {
        alph[i] = 0;
        reqs[i] = 0;
    }

    for (int i = 0; i < n; i++)
        cin >> dna[i];

    for (int i = 0; i < r; i++)
    {
        cin >> b;
        cin >> reqs[b];
        reqlen += reqs[b];
    }
    
    for (int i = 0; i < n; i++)
    {
        alph[dna[i]]++;

        if(reqs[dna[i]] != 0 && alph[dna[i]] <= reqs[dna[i]])
            found++;
        
        if(found == reqlen)
        {
            while(alph[dna[start]] > reqs[dna[start]] || reqs[dna[start]] == 0)
            {
                if(alph[dna[start]] > reqs[dna[start]]) alph[dna[start]]--;
                start++;
            }

            int t_len = i - start + 1;
            
            if(minlen > t_len)
            {
                minlen = t_len;
                min_start = start;
            }
        }

    }

    if(min_start == -1) cout << "impossible" << endl;
    else cout << minlen << endl;
    
    return 0;
}