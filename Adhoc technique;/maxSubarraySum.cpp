:::::::::::::::::::::::Maximum Sum of Subarray:::::::::::::::::::::
/*Given an array with n positive and negative numbers, find the subarray with one or more
consecutive numbers where the sum of the subarray is maximum.

#include<bits/stdc++.h>
#define MX 1000
using namespace std;

int main()
{
    int n, ara[MX];
    scanf("%d", &n);
    int mx=-INT_MIN;
    int sum=0, l=1, r=1, temp=1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &ara[i]);
        sum+=ara[i];
        if(mx<sum)
        {
            mx=sum;
            l=temp;
            r=i;
        }
        if(sum<0)
        {
            temp=i+1;
            sum=0;
        }
    }

    for(int i=l; i<=r; i++)
        cout << ara[i] << " ";
    cout << endl;

    cout << mx << endl;
}
/*
9
-2 1 -3 4 -1 2 1 -5 4

7
5 -10 6 -2 4  -10 1
*/

