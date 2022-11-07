class Solution {
public:
    
    bool bipartiteBFS(int src, vector<vector<int>>& graph, int color[]){
        queue<int>q;
        q.push(src);
        color[src]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vector<int> data = graph[node];
            for(auto x : data){
                if(color[x]==-1){
                    color[x]= 1-color[node];
                    q.push(x);
                }else if(color[x]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
    bool checkBipartite(vector<vector<int>>& graph, int n){
        int color[n];
        memset(color,-1,sizeof color);
        for(int i=0;i<n;i++){
            // this color array will act as visited array
            if(color[i]==-1){
                if(!bipartiteBFS(i,graph,color)){
                    return false;
                }

            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        if(checkBipartite(graph,n))
            return true;
        else
            return false;
        
        return 0;
    }
};