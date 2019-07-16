/*::::::::::::::(Sum of all numbers in a range)%M:::::::::::::::::::*/

#include<bits/stdc++.h>
#define MX 1005
using namespace std;
int sumMod[MX];

int main()
{
    int n, m, ara[MX];
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &ara[i]);
        sumMod[i]=((ara[i]%m)+sumMod[i-1])%m;
    }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", ((sumMod[r]-sumMod[l-1]+m)%m));
    }
    return 0;
}
