#include<bits/stdc++.h>
using namespace std;

void reverse_string(string &str, int sizeOfstr)
{
    int sz=sizeOfstr/2;
    for(int i=0, j=sizeOfstr-1; i<sz; i++, j--)
    {
        swap(str[i],str[j]);
    }
}

int main()
{
    string s;
    cin>> s;
    reverse_string(s, s.size());
    cout << s << endl;
    return 0;
}
