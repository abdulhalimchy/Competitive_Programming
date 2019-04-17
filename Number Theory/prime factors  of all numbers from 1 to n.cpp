///::::::::::::::Prime factors of all numbers from 1 to n:::::::::::::::
///::::::::::::::::::::Time Complexity : O(nloglogn)::::::::::::::::::::

#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
int spf[MX];

void sieve()
{
    spf[1]=1;
    //marking smallest prime factor for every number
    for(int i=2; i<MX; i+=2)
        spf[i]=2;
    for(int i=3; i<MX; i+=2)
        spf[i]=i;
    int root=sqrt(MX);
    for(int i=3; i<=root; i+=2)
    {
        if(spf[i]==i)
        {
            for(int j=i*i; j<MX; j+=i)
            {
                // marking spf[j] if it is not previously marked
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void primefactors(int n)
{
    while(n!=1)
    {
        printf("%d ", spf[n]);
        n/=spf[n];
    }
    printf("\n");
}

int main()
{
    sieve();
    int n;
    while(cin>>n)
    {
        primefactors(n);
    }
    return 0;
}
