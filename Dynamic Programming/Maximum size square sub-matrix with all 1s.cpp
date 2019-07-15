//::::::::Maximum size square sub-matrix with all 1's:::::::
//              Time Complexity: O(n^2)

#include<bits/stdc++.h>
#define MX 105
#define min(a, b, c) min(a, min(b, c))
using namespace std;
int sum[MX][MX];

int main()
{
    int n, m, num;
    while(scanf("%d %d", &n, &m)==2)
    {
        if(n+m==0)
            break;
        int mx=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d", &num);
                if(num==1)
                    sum[i][j]=min(sum[i-1][j], sum[i][j-1], sum[i-1][j-1])+1;
                else
                    sum[i][j]=0;
                mx=max(sum[i][j], mx);
            }
        }

        printf("%d\n", mx);
    }
    return 0;
}

/*
Input:
4 5
0 1 0 1 1
1 1 1 1 1
0 1 1 1 0
1 1 1 1 1
3 4
1 1 1 1
1 1 1 1
1 1 1 1
0 0
*/
