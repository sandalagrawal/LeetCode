class Solution {
public:
    
    bool isValid(int i, int j, int n , int m ,vector<vector<int>>& grid, int &area ){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
            return true;
        return false;
    }
    
    void dfs(int i, int j, int n , int m ,vector<vector<int>>& grid, int &area ){
         area++;
        grid[i][j]=0;
       
        
        if(isValid(i+1,j,n,m,grid,area)){
           
            dfs(i+1,j,n,m,grid,area);
        }
        if(isValid(i-1,j,n,m,grid,area)){
            
            dfs(i-1,j,n,m,grid,area);
        }
        if(isValid(i,j+1,n,m,grid,area)){
            
            dfs(i,j+1,n,m,grid,area);
        }
        if(isValid(i,j-1,n,m,grid,area)){
           
            dfs(i,j-1,n,m,grid,area);
        }
        
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans= 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                     dfs(i,j,n,m,grid,area);
                    ans = max(ans,area);
                }
                
                
            
            }
        }
        
        return ans;
    }
};