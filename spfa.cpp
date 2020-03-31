void addEdge(int frm, int to, int weight) 
{ 
	graph[frm].push_back({ to, weight }); 
}
void shortestPathFaster(int src, int V) 
{ 
    vector<int> dist(V+1,INF);
    bool inQueue[V + 1];
    memset(inQueue, false, V+1); 
    dist[src] = 0; 
    queue<int> q; 
    q.push(src); 
    inQueue[src] = true; 
  
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
        inQueue[u] = false; 
        for (int i = 0; i < graph[u].size(); i++) 
        { 
            int v = graph[u][i].first; 
            int weight = graph[u][i].second; 
  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                if (!inQueue[v]) 
                { 
                    q.push(v); 
                    inQueue[v] = true; 
                } 
            } 
        } 
    } 
}