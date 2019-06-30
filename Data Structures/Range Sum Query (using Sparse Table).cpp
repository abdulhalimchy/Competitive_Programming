//::::::::::::Range Sum Query Using Sparse Table::::::::::::
//____________Preprocess Time Complexity: O(n*log(n))___________
//__________________Query Time Complexity: O(log(n))_________________
//Tutorial Link: https://cp-algorithms.com/data_structures/sparse-table.html

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MX = 1e5+2;
ll sparse[MX][(int)log2(MX)+1];
ll ara[MX];

void rsq_preprocess(int n)
{

    for(int i=0; i<n; i++)
        sparse[i][0]=ara[i];
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=0; i+(1<<j)-1<n; i++)
        {
            sparse[i][j]= sparse[i][j-1]+sparse[i+(1<<(j-1))][j-1];
        }
    }
}

ll query(int l, int r)
{
    long long sum = 0;
    int k=(int)log2(MX)+1;
    for (int j=k; j>=0; j--)
    {
        if ((1 << j) <= r-l+1)
        {
            sum += sparse[l][j];
            l += 1 << j;
        }
    }
    return sum;
}

int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lld", &ara[i]);
    rsq_preprocess(n);
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(l,r));
    }
    return 0;
}
