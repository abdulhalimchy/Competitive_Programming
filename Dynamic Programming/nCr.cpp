#include<bits/stdc++.h>
#define MX 100
#define ll long long
using namespace std;

ll dp[MX][MX];

ll nCr(int n, int r)
{
     if(n==r)
          return 1;
     if(r==1)
          return n;
     if(dp[n][r]!=0)
          return dp[n][r];
     dp[n][r]=nCr(n-1, r)+nCr(n-1, r-1);
     return dp[n][r];
}

int main()
{
     int n, r;
     cin >> n >> r;
     cout << nCr(n,r) << endl;
     return 0;
}
