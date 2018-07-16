/*...................Allah is almighty*.................*/

///-----Finding largest proper prefix which is suffix also (Prefix suffix can overlap)----///

/*Given, String="abcdabcd"

Prefix: a, ab, abc, abcd, abcda, abcdab, abcdabc, abcdabcd
Proper Prefix: a, ab, abc, abcd, abcda, abcdab, abcdabc

Suffix: d, cd, bcd, abcd, dabcd, cdabcd, bcdabcd, abcdabcd
Proper Suffix: d, cd, bcd, abcd, dabcd, cdabcd, bcdabcd*/

#include<bits/stdc++.h>
#define MX 100000
using namespace std;

int lps[MX]; //"Length of the largest proper prefix which is suffix also for 0 to MX length prefix" or "Faliure Table"

void generate_lps(string ptr, int lengthOfthePtr)
{
    lps[0]=0, lps[1]=0;
    for(int i=2; i<=lengthOfthePtr; i++)//i is the length of the prefix
    {
        int j=lps[i-1];
        while(true){
            if(ptr[j]==ptr[i-1])
            {
                lps[i]=j+1;
                break;
            }
            if(j==0)
            {
                lps[i]=0;
                break;
            }

                j=lps[j];
        }
    }
}

int main()
{
    string ptr;
    cin >> ptr;
    generate_lps(ptr, ptr.size()); // Gernate lps

    //printing the failure table
    for(int i=0; i<=ptr.size(); i++)
        cout <<"For " << i <<" length prefix, largest prefix=sufix's length " << lps[i] << endl;
    return 0;
}
