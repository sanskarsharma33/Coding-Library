long long prim(vector<pair<int,int> > adj[], int x, int n)
{
    bool marked[n];
    memset(marked,false,n);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > Q;
    int y;
    long long minimumCost = 0;
    pair<int,int> p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.second;
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
} 
