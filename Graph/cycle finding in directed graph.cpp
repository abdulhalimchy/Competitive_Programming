#include<bits/stdc++.h>
#define MX 10005
#define pb push_back
using namespace std;

vector<int> v[MX];
int n, m, visited[MX], f=0;

void dfs(int source)
{
    visited[source]=0;
    vector<int> ::iterator it;
    for(it=v[source].begin(); it!=v[source].end(); it++)
    {
        if(visited[*it]==-1)
            dfs(*it);
        else if(visited[*it]==0)
        {
            f=1;
            return;
        }
    }
    visited[source]=1;
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
    }
    dfs(1); //The graph is connected
    if(f==1)
        printf("Has Cycle.\n");
    else
        printf("No cycle.\n");
    return 0;
}
