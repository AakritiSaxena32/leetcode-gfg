class DisjointSet
{
    public:
    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        else if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v))
                cntExtras++;
            else
                ds.unionBySize(u,v);
        }
        int cntC = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i]==i)
            {
                cntC++;
            }
        }
        int ans = cntC - 1;
        if(cntExtras>=ans) return ans;
        else return -1;
    }
};