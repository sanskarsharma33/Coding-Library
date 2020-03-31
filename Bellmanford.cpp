vector<vector<pair<int, int> > > addEdge(vector<vector<pair<int, int> > > graph, int u, int v, int wt) 
{ 
    graph[u].push_back(make_pair(v, wt)); 
    graph[v].push_back(make_pair(u, wt));
    return graph; 
}
void printGraph(vector<vector<pair<int, int> > > graph, int V) 
{ 
    int v; 
    for (int u = 0; u < V; u++) 
    {  
        for (int i=0; i<graph[u].size(); i++) 
        { 
            v =graph[u][i].first;  
            cout<<v<<" "; 
        } 
        cout<<endl; 
    } 
}
void bellmanford(vector<vector<pair<int, int> > > graph, int src)
{
    int V=graph.size();
    vector<int> dist(V, INF); 
    vector<int> parent;
    dist[src]=0;
    for(int i=1; i<V; i++)
    {
        for(int j=1; i<=V; i++)
        {
            for(int k=0; k<graph[j].size(); k++)
            {
                int u=j, v=graph[j][k].first, weight=graph[j][k].second;
                if(dist[u]!=INF && dist[u]+weight < dist[v])
                {
                    dist[v]=dist[u]+weight;
                    parent[v] = u;
                }
            }
        }
    }
}