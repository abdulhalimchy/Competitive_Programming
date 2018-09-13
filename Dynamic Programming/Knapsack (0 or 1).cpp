///::::::::::::: Knapsack 0/1 :::::::::::::
///             (Recursive DP)
///         complexity = O(n*capacity)
#include<bits/stdc++.h>
#define MX 100
using namespace std;
int n, capacity, weight[MX], value[MX], dp[MX][MX];

int max_profit(int i, int w)
{
    if(i>n) return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int profit1=0, profit2=0;
    if(w+weight[i]<=capacity)
        profit1=value[i]+max_profit(i+1, w+weight[i]);
    profit2=max_profit(i+1, w);
    return dp[i][w]=max(profit1, profit2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &capacity);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &weight[i], &value[i]);
    printf("Maximum profit is : %d\n", max_profit(1, 0));
}
