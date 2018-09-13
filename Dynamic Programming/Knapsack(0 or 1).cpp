///:::::::::::: Knapsack 0/1 ::::::::::::
///          (using iterative DP)
///        complexity, O(n*capacity)     ; where n=number of items

#include<bits/stdc++.h>
#define MX 105
using namespace std;
int n, capacity, weight[MX], value[MX], dp[MX][MX];

int max_value()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            if(weight[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
    }
    return dp[n][capacity];
}

int main()
{
    scanf("%d %d", &n, &capacity);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &weight[i], &value[i]);
    printf("Max value is : %d\n", max_value());

    return 0;
}

/*
3 26
17 72
23 44
24 31
ans: 72

4 5
2 3
3 4
4 5
5 6
ans: 7

4 10
1 120
4 280
3 150
4 200
ans: 600
*/
