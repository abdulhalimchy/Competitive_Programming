#include<bits/stdc++.h>
#define MX 100
using namespace std;

int v[MX][MX];
int dist[MX], path[MX], nodes;

void graph(int edges)
{
    memset(v, 0, sizeof(v));
    for(int i=0; i<edges; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a][b]=1;
        v[b][a]=1;
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
        for(int i=1; i<=nodes; i++)
        {
            if(v[u][i]==1 && dist[i]==-1)
            {
                q.push(i);
                dist[i]=dist[u]+1;
                path[i]=u;
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
    int edges;
    scanf("%d %d", &nodes, &edges);
    graph(edges);
    int query, destination;
    scanf("%d", &query);
    for(int i=0; i<query; i++)
    {
        scanf("%d",&destination);
        bfs(1); // Here, the source node is always 1.
        printf("Distance from 1 to %d is %d\n", destination, dist[destination]);
        printf("Path: ");
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
