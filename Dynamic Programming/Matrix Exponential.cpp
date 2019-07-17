/*::::::::::::::::::::::::::::Matrix Exponential::::::::::::::::::::::::::::::::
Matrix exponentiation allows us to find nth term of a linear recurrence relation in O(logN).
To calculate the nth term of the recurrence relation we need to calculate M^N (M is the Constant Matrix of size K*K).
By using fast exponentiation we can find out M^N in O(K^3(logN)).

Example: UVA 12470
Find n'th Tribonacci where T(n)=T(n-1)+T(n-2)+T(n-3) and T(1)=0, T(2)=1, T(3)=2.
Now, T(n)=a*T(n-1)+b*T(n-2)+c*T(n-3) where a=b=c=1.

| a b c |       | T(n-1) |      | T(n)   |
| 1 0 0 |   X   | T(n-2) |  =   | T(n-1) |
| 0 1 0 |       | T(n-3) |      | T(n-2) |

or

| 1 1 1 |       | T(n-1) |      | T(n)   |
| 1 0 0 |   X   | T(n-2) |  =   | T(n-1) |
| 0 1 0 |       | T(n-3) |      | T(n-2) |

*/

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000009
using namespace std;

void multiply(ll a[][3], ll b[][3])
{
    ll mul[3][3];
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            mul[i][j]=0;
            for (int k=0; k<3; k++)
                mul[i][j]=(mul[i][j]+((a[i][k]*b[k][j])%mod))%mod;
        }
    }

    //storing the multiplication result.
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j]%mod;
}

void nth_power(ll m[][3], ll n)
{
    if(n==0 || n==1)
        return;
    ll temp[][3]={{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    nth_power(m, n/2);
    multiply(m, m);
    if(n%2==1)
        multiply(m, temp);
}

ll tribonacci(ll n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else if(n==3)
        return 2;

    ll m[][3]={{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    nth_power(m, n-3);
    return (m[0][0]*2+m[0][1]*1+m[0][2]*0)%mod;
}

int main()
{
    ll n;
    while(scanf("%lld", &n)==1)
    {
        if(n==0)
            break;
        printf("%lld\n", tribonacci(n));
    }
    return 0;
}
