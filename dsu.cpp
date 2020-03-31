class DSU
{
public:
	std::vector<int> parent;
	std::vector<int> rank;
	DSU(int n)
	{
		for(int i=0; i<=n; i++)
		{
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x)
	{
		if(parent[x]!=x)
		{
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y)
	{
		x=find(x);y=find(y);
		if(x==y)
			return;
		if(rank[x]>rank[y])
			parent[y]=x;
		else{
			parent[x]=y;
			if(rank[x]==rank[y])
				rank[y]++;
		}
	}
};