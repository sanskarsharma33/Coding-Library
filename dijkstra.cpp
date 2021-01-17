vector<pair<int,int> > graph[100001];

void addEdge(int frm, int to, int weight) 
{ 
    graph[frm].push_back({ to, weight }); 
    graph[to].push_back({frm,weight});
}

pair<vector<int>,vector<int>> dijkstra( int src, int V)
{ 
    priority_queue< pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > > pq; 
    vector<int> dist(V+1, INF); 
    vector<int> parent(V+1, 0);
    pq.push(make_pair(0, src));
    dist[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
   
        for (int i = 0; i < graph[u].size(); ++i) 
        { 
            int v = (graph[u][i]).first; 
            int weight = (graph[u][i]).second; 
  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                parent[v] = u;
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    return {dist,parent};
}
void findPath(vector<int> parent, int final)
{
	vector<int> path;
	while(final!=0)
	{
		path.push_back(final);
		final=parent[final];
	}
	for(int i=path.size()-1; i>0; i--)
		cout<<path[i]<<"->";
	cout<<path[0];
}
