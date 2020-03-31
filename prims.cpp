void primMST(vector<pair<int,int> > graph[], int V) 
{ 
    priority_queue< pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > > pq; 
  
    int src = 0; 
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;
        for (auto x : graph[u]) 
        { 
            int v = x.first; 
            int weight = x.second; 
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
} 