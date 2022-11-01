class Solution {
public:
    
void dfs(vector<vector<int>>& graph,   vector<int>&path,  vector<vector<int>>&ans,int s){
       
    path.push_back(s);
    
    if(s==graph.size()-1){
        ans.push_back(path);
    }
    else {
        for(auto x: graph[s]){
            dfs(graph,path,ans, x);
        }
    }
       
   path.pop_back();
   
        
 }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n = graph.size();
        vector<int>path;
        
        dfs(graph, path,ans,0);
  
        return ans;
    }
};