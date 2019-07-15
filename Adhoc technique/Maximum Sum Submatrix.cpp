/*::::::::::::::::::Maximum Sum Sub-matrix:::::::::::::::::::::::
Given, NxN matrix, find out the sum of the maximal sub-rectangle.
*/

#include<bits/stdc++.h>
#define MX 105
using namespace std;
int sum[MX][MX], temp[MX];

int main()
{
    int n;
    scanf("%d", &n);
    int ara[MX][MX];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &ara[i][j]);
            sum[i][j]=sum[i-1][j]+ara[i][j];
        }
    }

    int ans_mx=INT_MIN, tx, ty, bx, by;

    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int mx=INT_MIN, l=1, r=1, s=1, cur_mx=0;
            for(int k=1; k<=n; k++)
            {
                temp[k]=sum[j][k]-sum[i-1][k];
                cur_mx+=temp[k];
                if(cur_mx>mx)
                {
                    mx=cur_mx;
                    l=s;
                    r=k;
                    if(ans_mx<mx)
                    {
                        ans_mx=mx;
                        tx=i, ty=l, bx=j, by=r;
                    }
                }
                if(cur_mx<0)
                {
                    cur_mx=0;
                    s=k+1;
                }
            }
        }
    }

    //printing the sub-matrix/sub-rectangle
    printf("\n");
    for(int i=tx; i<=bx; i++)
    {
        for(int j=ty; j<=by; j++)
            printf("%d ", ara[i][j]);
        printf("\n");
    }
    printf("Maximum sum : %d\n", ans_mx);
    return 0;
}

//Practice problem: UVA-108
