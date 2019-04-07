#include<bits/stdc++.h>
#define MX 100000
using namespace std;
bool prime[MX]; //prime[i]=0 means: i is a prime number and prime[i]=1 means: i is not a prime number;

void sieve()
{
    prime[0]=1;
    prime[1]=1;
    for(int i=4; i<=MX; i+=2)
        prime[i]=1;
    int root = sqrt(MX);
    for(int i=3; i<=root; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=MX; j+=i)
            {
                prime[j]=1;
            }
        }
    }
}

int main()
{
    sieve();

    int n;
    while(cin>>n)
    {
        if(prime[n]==1)
            cout << "Not prime" << endl;
        else
            cout << "Prime" << endl;
    }
    return 0;
}
