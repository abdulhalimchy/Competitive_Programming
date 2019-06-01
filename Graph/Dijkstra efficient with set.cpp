#include<bits/stdc++.h>
#define MX 100005
#define INF 2000100100105
#define LL long long
#define pb push_back
#define mp make_pair
using namespace std;
vector<pair<LL, LL> > v[MX];
vector<pair<LL, LL> > ::iterator vt;
int edge, node, path[MX];
LL dist[MX];

void graph()
{
    LL a, b, w;
    for(int i=1; i<=node; i++)
        dist[i]=INF;
    for(int i=1; i<=edge; i++)
    {
        cin >> a >> b >> w;
        v[a].pb(mp(b, w));
        v[b].pb(mp(a, w));
    }
}

void dijkstra(int source)
{
    set<pair<LL, LL> > s;
    set<pair<LL, LL> > ::iterator it;
    dist[source]=0;
    s.insert(mp(0, source));
    while(s.size())
    {
        it=s.begin();
        int u = it->second;
        s.erase(it);
        for(vt=v[u].begin(); vt!=v[u].end(); vt++)
        {
            if(dist[u]+vt->second<dist[vt->first])
            {
                if(dist[vt->first]!=INF)
                {
                    s.erase(s.find(make_pair(dist[vt->first],vt->first)));
                }
                dist[vt->first]=dist[u]+vt->second;
                s.insert(mp(dist[vt->first], vt->first));
                path[vt->first]=u;
            }
        }

    }
}

void print_path(int source)
{
    if(source==0)
        return;
    print_path(path[source]);
    cout << source << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> node >> edge;
    graph();
    dijkstra(1);
    //cout << dist[node] << endl;
    if(dist[node]!=INF)
    {
        print_path(node);
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
