//::::::::::::Range Minimum Query Using Sparse Table::::::::::::
//__________________Time Complexity: O(n*log(n))________________
//Tutorial Link: https://www.youtube.com/watch?v=c5O7E_PDO4U

#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5+2;
int sparse[MX][(int)log2(MX)+1];
int ara[MX];

void rmq_preprocess(int n)
{

    for(int i=0; i<n; i++)
        sparse[i][0]=ara[i];
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=0; i+(1<<j)-1<n; i++)
        {
            sparse[i][j]= min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq_value(int l, int r)
{
    int k=log2(r-l+1);
    return min(sparse[l][k], sparse[r-(1<<k)+1][k]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    rmq_preprocess(n);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", rmq_value(l,r));
    }
    return 0;
}
