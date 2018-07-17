/*...................Allah is almighty*.................*/

///-----KMP Algorithm (SubString Searching)-----///
// Complexity O(textSize+patternSize)

#include<bits/stdc++.h>
#define MX 100000
using namespace std;

int lps[MX]; //"Length of the largest proper prefix which is suffix also for 0 to MX length prefix" or "Faliure Table"

//Generate largest proper prefix which is suffix also, for every prefix of the pattern string
void generate_lps1(string pattern, int lengthOfthepattern)
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

//another way of generating lps[]
void generate_lps2(string pattern, int patternSize)
{
	int i=1, j=0;
	lps[0]=0, lps[1]=0;

	while(i<patternSize)
    {
        while(j>0 && pattern[i]!=pattern[j])
        {
            j=lps[j];
        }
        i++, j++;
        lps[i]=j;
    }
}




//implementing of KMP algorithm
bool kmp1(string text, string pattern, int textSize, int patternSize){

    generate_lps1(pattern, patternSize); // Generate lps array, we can use any of generate_lps1() or generate_lps2(). Both are doing same

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


// Another way of implementation of KMP algorithm... 
bool kmp2(string text, string pattern, int textSize, int patternSize)
{
    generate_lps1(pattern, patternSize); //we can use any of  generate_lps1() or generate_lps2(). Both are doing same
    int i=0, j=0;

    while(i<textSize)
    {
        while(j>0 && pattern[j]!=text[i])
        {
            j=lps[j];
        }
        i++, j++;
        if(j==patternSize)
            return true;
    }
}


int main()
{
    string pattern, text;
    cin >> text >> pattern;
    int n=text.size(), m=pattern.size();
    bool flag=kmp1(text, pattern, n, m); //we can use any of kmp1() or  kmp2(). Both are doing same

    if(flag==true)
        cout << "Substirng Found" << endl;
    else
        cout << "Substirng not Found" << endl;
    
    return 0;
}

