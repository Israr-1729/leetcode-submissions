class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &nodes,int &deg){
        vis[node]=1;
        nodes++;
        deg+=adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,nodes,deg);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=0;
                int deg=0;
                dfs(i,adj,vis,nodes,deg);
                if((deg/2)==(nodes*(nodes-1))/2) count++;
            }
        }
        return count;
    }
};