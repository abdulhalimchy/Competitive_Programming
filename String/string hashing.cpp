/*:::::::::::::::::::::::::String Hashing::::::::::::::::::::::::::*/
#include<bits/stdc++.h>
#define ll long long
#define MX 100005
#define mod 1000000007
#define base 347
using namespace std;
ll powr[MX], Hash[MX];
void pre_powr()
{
    powr[0]=1;
    for(int i=1; i<MX; i++)
        powr[i]=(powr[i-1]*base)%mod;
}

void hashing(string str, int len)
{
    for(int i=0; i<len; i++)
        Hash[i+1]=(Hash[i]*base+str[i])%mod;
}

ll hash_value(int l, int r)
{
    return (Hash[r]-((Hash[l-1]*powr[r-l+1])%mod)+mod)%mod;
}
int main()
{
    string str;
    cin >> str;
    pre_powr();
    int len=str.size();
    hashing(str, len);
    int l, r;
    while(cin >> l >> r)
    {
        cout << hash_value(l, r) << endl;
    }
    return 0;
}
