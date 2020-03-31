void addEdge(vector<pair<int,pair<int,int> > > edges, int u, int v, int w) 
{ 
    edges.push_back({w, {u, v}});
    return edges; 
}

void kruskalMST(vector<pair<int,pair<int,int> > > edges, int V) 
{ 
    int mst_wt = 0; 
    sort(edges.begin(), edges.end()); 
    DSU dsu(V); 
    for (int i=0; i<edges.size(); i++) 
    { 
        int u = edges[i].second.first; 
        int v = edges[i].second.second; 
  
        int set_u = dsu.find(u); 
        int set_v = dsu.find(v); 
        if (set_u != set_v) 
        { 
            mst_wt += edges[i].first; 
            dsu.merge(set_u, set_v); 
        } 
    } 
    return; 
}