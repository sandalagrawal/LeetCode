class Solution {
public:
    
    bool canFinishRec(int i, vector<bool> &visited, vector<bool> &dfsvisited, vector<int> adj[]){
        visited[i]=true;
        dfsvisited[i]=true;
        
        vector<int> data = adj[i];
        for(auto x : data){
            
            if(visited[x]==false){
                if(canFinishRec(x, visited, dfsvisited, adj))
                    return true;
            }else if(visited[x]==true && dfsvisited[x]==true){
                return true;
            }

        
        }
        dfsvisited[i] = false;
        return false;
        
    }
    
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        int n = numCourses;
        
        vector<bool> visited(n, false);
        vector<bool> dfsvisited(n,false);
        
        vector<int> adj[n];
        for(auto x : prerequisites){
            vector<int>data = x;
            int a = data[0];
            int b = data[1];
            adj[a].push_back(b);
        }
        
        
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(canFinishRec(i, visited, dfsvisited, adj))
                    return false;
            }
        }
        return true;
    }
};