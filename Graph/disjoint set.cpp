///::::::::::::::::::::::::Disjoint Set Union:::::::::::::::::::::::::
///:::::::::::::Example: Hackerrank - Merging Communities:::::::::::::
#include<bits/stdc++.h>
#define MX 100005
using namespace std;

int parent[MX], parent_size[MX];


int find_parent(int r)
{
    if(parent[r]==r)
        return r;
    parent[r]=find_parent(parent[r]);
    return parent[r];
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    for(int i=1; i<=n; i++)
    {
        parent[i]=i;    //Initially, every node's parent as itself
        parent_size[i]=1;   //set size initially 1.
    }
    for(int i=1; i<=q; i++)
    {
        char ch;
        int a, b;
        cin >> ch;
        if(ch=='Q')
        {
            scanf("%d", &a);
            printf("%d\n", parent_size[find_parent(a)]);
        }
        else
        {
            scanf("%d %d", &a, &b);
            int u=find_parent(a);
            int v=find_parent(b);
            if(u!=v)        //If not in the same set, then marge..
            {
                int temp=parent_size[u];
                parent[u]=v;
                parent_size[v]+=temp;
            }
        }
    }
    return 0;
}
