#include<bits/stdc++.h>
#define MX 100005
using namespace std;
bool prime[MX];
vector<int> v;

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

    for(int i=2; i<=MX; i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }

}

void prime_factor(int n)
{
    int sz=v.size();
    for(int i=0; i<sz; i++)
    {
        while(n%v[i]==0)
        {
            n/=v[i];
            cout << v[i] << " ";
        }
        if(n==1)
            break;
    }
    if(n!=1)
       cout << n;
    cout << endl;

}


int main()
{
    sieve();
    int n;
    while(cin >> n)
    {
        prime_factor(n);
    }

    return 0;
}

// To Solve: 406, 10392, 11466, 583;
