///:::::::::::::::: Coin change (III) :::::::::::::
///   Complexity: O(numberOfCoins * frequency * amountTomake)
/// Given, n coins, we can use coin[i] coin limit[i] times. and an amount to make using these coins.
///In how many ways, we can make the given amount using these coins?

LL limit[52], coins[52], dp[52][1002][22], n, k;
LL make(LL i, LL curAmount, LL cur) ///cur = number of coin[i] type coin is currently used.
{
    if(i>n)
    {
        if(curAmount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][curAmount][cur]!=-1)
        return dp[i][curAmount][cur];
    LL ret1=0, ret2=0;
    if((curAmount-coins[i]>=0) && (cur<limit[i]))
        ret1=make(i, curAmount-coins[i], cur+1);
    ret2=make(i+1, curAmount, 0);
    return dp[i][curAmount][cur]=(ret1+ret2)%mod;
}
