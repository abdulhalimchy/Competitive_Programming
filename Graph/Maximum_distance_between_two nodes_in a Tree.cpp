///*************Maximum distance between two nodes in a Tree**********
/*-----------------------------------Approach-----------------------------------------
Start bfs from any node and find out the farthest node, this farthest node will be u.
Again, start bfs from u and find out the farthest node from u, this farthest node will be v.
The distance between u and v is the maximum distance of any two nodes in a Tree.
                        -------------------x---------------------

Task: Find out maximum distance from a given node to any node in a Tree.

Solution: At first calculate distance of all nodes from u (suppose stored in u_dist[]),
          and calculate distance of all nodes from v (suppose stored in v_dist[]).
Then, the maximum distance from a given node to any node = max(u_dist[given_node],v_dist[given_node]).

Practice problem: Hackerrank - journey scheduling
--------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
#define MX 100005
#define pb push_back
#define ll long long
using namespace std;

vector<int> g[MX];

void bfs(int source, int dist[])
{
    queue<int> que;
    dist[source]=0;
    que.push(source);
    vector<int> ::iterator it;
    while(que.size())
    {
        int fr=que.front();
        que.pop();
        for(it=g[fr].begin(); it!=g[fr].end(); it++)
        {
            if(dist[*it]==-1)
            {
                dist[*it]=dist[fr]+1;
                que.push(*it);

            }
        }
    }
}

int main()
{
    int u_dist[MX], v_dist[MX], node, q, u, v, dist[MX];
    scanf("%d %d", &node, &q);
    memset(u_dist, -1, sizeof(u_dist));
    memset(v_dist, -1, sizeof(v_dist));
    memset(dist, -1, sizeof(dist));
    for(int i=1; i<node; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    bfs(1, dist);
    int mx=0;
    for(int i=1; i<=node; i++)
    {
        if(dist[i]>mx)
        {
            mx=dist[i];
            u=i;
        }
    }
    bfs(u, u_dist);

    int mx1=0;
    for(int i=1; i<=node; i++)
    {
        if(u_dist[i]>mx1)
        {
            mx1=u_dist[i];
            v=i;
        }
    }

    bfs(v, v_dist);

    for(int i=1; i<=q; i++)
    {
        int start;
        ll jour;
        scanf("%d %lld", &start, &jour);
        ll ans=max(v_dist[start], u_dist[start]);
        ans+=((jour-1)*(ll)mx1);
        printf("%lld\n", ans);
    }
    return 0;
}
