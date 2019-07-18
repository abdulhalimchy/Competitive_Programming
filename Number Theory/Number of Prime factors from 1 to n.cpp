/*::::::::::::::::::Number of prime factors of all numbers from 1 to n:::::::::::::
                            Time Complexity: O(n*log(logn))
*/

#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
int spf[MX], tpf[MX];  // spf=smallest prime factor, tpf=total prime factor

void generate_spf()
{
    spf[1]=1;
    for(int i=2; i<MX; i++)
        spf[i]=2;
    for(int i=3; i<MX; i+=2)
        spf[i]=i;
    int root=sqrt(MX);
    for(int i=3; i<=root; i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i; j<MX; j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}


void number_of_prime_factors()
{
    tpf[1]=0;
    for(int i=2; i<MX; i++)
    {
        int n=i;
        while(n!=1)
        {
            tpf[i]++;
            n/=spf[n];
        }

    }
}

int main()
{
    int n;
    generate_spf();
    number_of_prime_factors();
    while(scanf("%d", &n)==1)
    {
        printf("%d\n", tpf[n]);
    }
    return 0;
}
