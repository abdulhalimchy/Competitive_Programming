//:::::::::::::::::::::DFS::::::::::::::::::::::::
void dfs(int src)
{
    visit[src]=true;
    vector<int> ::iterator it;
    for(it=v[src].begin(); it!=v[src].end(); it++)
    {
        if(visit[*it]==false)
            dfs(*it);
    }
}
