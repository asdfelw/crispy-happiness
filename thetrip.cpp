#include <bits/stdc++.h>
using namespace std;

// HARD problem https://open.kattis.com/problems/trip

int main()
{
    int u;
    double students[1000], avg;
    int dollar, cent, n;

    u = scanf("%d", &n);

    while(n != 0)
    {
        avg=0;
        for(int i = 0; i < n; i++)
        {
            u = scanf("%d.%d", &dollar, &cent);
            students[i] = dollar * 100 + cent;
            avg += dollar * 100 + cent;
        }

        avg = avg / n;
        
        double diff, given=0, taken=0;
        for(int i = 0; i < n; i++)
        {
            diff = students[i]-avg;
            if(diff >= 0)
                given+= ((int)diff)/100.0;
            else
                taken+= -((int)diff)/100.0;
        }


        printf("$%.2lf\n", taken > given ? taken : given);

        u = scanf("%d", &n);
    }

    return 0;
}
