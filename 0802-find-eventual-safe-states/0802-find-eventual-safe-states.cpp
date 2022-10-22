class Solution {
public:
    
    bool dfsrec(int i, vector<bool>&visited, vector<bool>&dfsvisited,vector<vector<int>>& graph, vector<bool> &present_cycle ){
          
        visited[i]=true;
        dfsvisited[i]=true;
        
        vector<int> data = graph[i];
        
            for(auto x : data){
                if(visited[x]==false){
                    if(dfsrec(x,visited,dfsvisited,graph, present_cycle)){
                       return  present_cycle[i]= true;
                 }
                } else if(visited[x]==true && dfsvisited[x]==true){
                  return  present_cycle[i] = true;
            } 
                
                
            }
        
        dfsvisited[i]=false;
        return false;
        }

    
    
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool>dfsvisited(n,false);
        vector<int> ans;
        
        vector<bool> present_cycle(n , false);
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfsrec(i, visited, dfsvisited, graph, present_cycle);
            }
        }
        
        for(int i=0;i<n;i++){
            if(!present_cycle[i])
                ans.push_back(i);

        }
        
        return ans;
    }
};