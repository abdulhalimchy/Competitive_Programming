/*
    Cycle finding in a undirected graph
    Example- SPOJ::PT07Y - Is it a tree
*/

#include<bits/stdc++.h>
#define MX 10005
#define pb push_back
using namespace std;

vector<int> v[MX];
int n, m, visited[MX], f=0;

void dfs(int source, int parent)
{
    visited[source]=1;
    vector<int> ::iterator it;
    for(it=v[source].begin(); it!=v[source].end(); it++)
    {
        if(visited[*it]==-1)
            dfs(*it, source);
        else if(*it!=parent)
        {
            f=1;
            return;
        }
    }
}

int main()
{
    memset(visited,-1,sizeof(visited));
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=1; i<=n; i++) //If the graph is not connected
    {
        if(visited[i]==-1)
            dfs(i,0);
    }
    if(f==1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
