
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
vector<int> dijkstra(vector<vector<pair<int,int> > > graph, int src)
{ 
    priority_queue< pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > > pq; 
    vector<int> dist(V, INF); 
    vector<int> parent;
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        list< pair<int, int> >::iterator i; 
        for (i = graph[u].begin(); i != graph[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                parent[v] = u;
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    return dist;
}