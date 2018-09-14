///:::::::::::::::: COIN CHANGE - I ::::::::::::::
///Given, different types of coins, and an amount of money.
///We need to check, is it possible to make the given amount using these coins.
///We can use all the coins any number of times.

#include<bits/stdc++.h>
#define MX 50
using namespace std;
int coins[MX], dp[MX][MX], n, amountTomake;

int can_make(int i, int curAmount)
{
    if(i>n)
    {
        if(amountTomake==curAmount)
            return 1;
        else
            return 0;
    }
    if(dp[i][curAmount]!=-1)
        return dp[i][curAmount];
    int ret1=0, ret2=0;
    if(curAmount+coins[i]<=amountTomake)
        ret1=can_make(i, curAmount+coins[i]);
    ret2=can_make(i+1, curAmount);
    return dp[i][curAmount]= max(ret1,ret2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &amountTomake);
    for(int i=1; i<=n; i++)
        scanf("%d", &coins[i]);

    if(can_make(1,0)==1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
