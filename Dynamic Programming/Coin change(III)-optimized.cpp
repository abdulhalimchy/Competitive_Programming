///:::::::::::::::: Coin change (III) :::::::::::::
///   Complexity: O(numberOfCoins * frequency * amountTomake)
/// Given, n coins, we can use coin[i] coin limit[i] times. and an amount K to make using these coins.
///In how many ways, we can make the given amount using these coins?


LL limit[52], coins[52], dp[52][MX], n, k;

LL make(LL i, LL curAmount)
{
    if(i>n)
    {
        if(curAmount==k)
            return 1;
        else
            return 0;
    }
    if(dp[i][curAmount]!=-1)
        return dp[i][curAmount];
    LL ret=0;
    for(int j=0; j<=limit[i]; j++)
    {
        if(curAmount+(coins[i]*j)<=k)
        {
            ret+= make(i+1, curAmount+(coins[i]*j));
            ret%=mod;
        }
        else
            break;
    }
    return dp[i][curAmount]=ret;
}
