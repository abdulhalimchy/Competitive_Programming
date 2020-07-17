#include<stdio.h>

int nodes, edges, graph[100][100], visited[100]; //Globally declared, so initially, all the values are 0.

void dfs(int source)
{
    printf("%d ", source);  // Printing the node which can be visited
    visited[source]=1;
    int i;
    for(i=0; i<nodes; i++)
    {
        if(visited[i]!=1 && graph[source][i]==1) //If it is not visited already and If it is possible to go to this node from source.
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, source;
    scanf("%d %d", &nodes, &edges);

    //Scanning graph and keeping it in adjacency matrix.
    for(i=0; i<edges; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b]=1;      // it means, it is possible to go from node 'a' to node 'b'
        graph[b][a]=1;      // it means, it is possible to go from node 'b' to node 'a'
    }
    scanf("%d", &source);
    dfs(source); //Traverse Graph from source
    return 0;
}

/*
Input1:
14 12
0 1
0 4
0 2
1 3
1 4
3 5
5 6
5 7
6 8
2 11
11 10
9 13
0

Input2:
14 10
0 1
0 2
0 4
1 3
1 4
2 11
3 5
6 7
8 9
10 13
4

Input3:
7 5
1 2
1 4
2 5
3 6
0 6
6
*/
