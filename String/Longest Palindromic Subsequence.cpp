#include<bits/stdc++.h>
#define MX 105
using namespace std;
int lps[MX][MX];

int generate_lps(string s)
{
    int len=s.size();
    for(int i=0; i<len; i++)
        lps[i][i]=1;
    for(int l=2; l<=len; l++)
    {
        for(int i=0; i<=len-l; i++)
        {
            int j=i+l-1;

            if(s[i]==s[j] && i+1==j)
                lps[i][j]=2;
            else if(s[i]==s[j])
                lps[i][j]=lps[i+1][j-1]+2;
            else
                lps[i][j]=max(lps[i+1][j], lps[i][j-1]);
        }
    }
    return lps[0][len-1];
}

int lps_in_range(int l, int r)
{
    return lps[l-1][r-1];
}

int main()
{
    string s;
    cin >> s;
    cout << generate_lps(s) << endl;

    for(int i=0; i<s.size(); i++)
    {
        for(int j=0; j<s.size(); j++)
        {
            cout << lps[i][j] << " ";
        }
        cout << endl;
    }

    int l, r;
    while(true)
    {
        cin >> l >> r;
        if(l==0 && l==r)
            break;
        cout << lps_in_range(l, r) << endl;
    }

    return 0;
}
