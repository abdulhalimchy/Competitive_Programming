#include<bits/stdc++.h>
#define MX 100005
using namespace std;

vector<int> v[MX];
int dist[MX], path[MX];

void graph(int edges)
{
    for(int i=0; i<MX; i++)
        v[i].clear();
    for(int i=0; i<edges; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void bfs(int source)
{
    memset(dist, -1, sizeof(dist));
    queue<int>q;
    q.push(source);
    dist[source]=0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vector<int> ::iterator it;
        for(it=v[u].begin(); it!=v[u].end(); it++)
        {
            if(dist[*it]==-1)
            {
                q.push(*it);
                dist[*it]=dist[u]+1;
                path[*it]=u;
            }
        }
    }
}

void print_path(int en)
{
    if(dist[en]==0)
    {
        printf("%d ", en);
        return;
    }
    print_path(path[en]);
    printf("%d ", en);
}
int main()
{
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);
    graph(edges);
    int query, destination;
    scanf("%d", &query);
    for(int i=0; i<query; i++)
    {
        scanf("%d",&destination);
        bfs(1); // Here, the source node is always 1.
        printf("Distance: %d\n", dist[destination]);
        print_path(destination);
        printf("\n");
    }

    return 0;
}

/*
10 13
1 2
1 3
1 4
2 6
3 7
3 8
4 7
5 8
5 10
6 10
7 8
7 9
9 10
*/
