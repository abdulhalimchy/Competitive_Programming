#include<stdio.h>
#define ll long long

int bigmod(int b, int p, int m)
{
    if(p==0)
        return 1%m;
    ll ans=bigmod(b, p/2, m);
    ans%=m;
    ans*=ans;
    ans%=m;
    if(p%2==1)
        ans*=b;
    return ans%m;     // will return b^p % m
}

int main()
{
    int b, p, m;
    while(scanf("%d %d %d", &b, &p, &m)!=EOF){
        printf("%d\n", bigmod(b, p, m));
    }
    return 0;
}
