/*...................Allah is almighty*.................*/

///-----KMP Algorithm-Substring Searching----///
// Complexity O(textSize+patternSize)

#include<bits/stdc++.h>
#define MX 100000
using namespace std;

int lps[MX]; //"Length of the largest proper prefix which is suffix also for 0 to MX length prefix" or "Faliure Table"

//Generate largest proper prefix which is suffix also, for every prefix of the pattern string
void generate_lps(string pattern, int lengthOfthepattern)
{
    lps[0]=0, lps[1]=0;
    for(int i=2; i<=lengthOfthepattern; i++)//i is the length of the prefix string
    {
        int j=lps[i-1];
        while(true){
            if(pattern[j]==pattern[i-1])
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


bool kmp(string text, string pattern, int textSize, int patternSize){

    generate_lps(pattern, patternSize); // Generate lps array

    int i=0; // index of text
    int j=0; // index of pattern

    while(true)
    {
        if(i==textSize)
            return false;
        if(text[i]==pattern[j])
        {
            i++; //next character of the text
            j++; //next character of the pattern;
            if(j==patternSize)
                return true;
        }
        else
        {
            if(j==0) // when j=0, we have to start comparing again from  beginning of the pattern
                i++; // next character of the text
            else
                j=lps[j]; // next index of the already matched characters of the pattern string
        }
    }
    return false;
}


int main()
{
    string pattern, text;
    cin >> text >> pattern;
    int n=text.size(), m=pattern.size();
    bool flag=kmp(text, pattern, n, m);

    if(flag==true)
        cout << "Substirng Found" << endl;
    else
        cout << "Substirng not Found" << endl;

    return 0;
}

