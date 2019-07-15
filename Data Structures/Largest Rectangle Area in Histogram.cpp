//:::::::::::::::::::::Largest Rectangle Area in Histogram::::::::::::::::::
//Time Complexity: O(n) [Because we need to push every position n times and pop every position n times]
#include<bits/stdc++.h>
#define MX 105
using namespace std;

int main()
{
    int n, ara[MX];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    stack<int> position;
    int mx_area=0;
    for(int i=0; i<n; i++)
    {
        if(position.empty() || ara[position.top()]<=ara[i])
            position.push(i);
        else
        {
            while(!position.empty() && ara[position.top()]>ara[i])
            {
                int h=ara[position.top()], area;
                position.pop();

                if(position.empty())
                    area = h*i;
                else
                    area = h*(i-position.top()-1);
                mx_area=max(mx_area, area);
            }
            position.push(i);
        }
    }

    while(!position.empty())
    {
        int h=ara[position.top()], area;
        position.pop();

        if(position.empty())
            area = h*n;
        else
            area = h*(n-position.top()-1);
        mx_area=max(mx_area, area);
    }

    printf("%d\n", mx_area);

    return 0;
}

/*
5
1 3 2 1 2
*/
