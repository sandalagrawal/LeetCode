class Solution {
public:
    bool isValid(vector<vector<int>>& image, int i, int j, int color, int m , int n,int ini)
    {
        if(i>=0&& i<n && j>=0 && j<m && image[i][j]==ini)
            return true;
        
        return false;
    }
    
    void floodFillRec(vector<vector<int>>& image, int i, int j, int color, int m , int n,int ini){
        image[i][j]=color;
        
        if(isValid(image, i+1,j,color,m,n,ini))
            floodFillRec(image, i+1,j,color,m,n,ini);
        if(isValid(image, i-1,j,color,m,n,ini))
            floodFillRec(image, i-1,j,color,m,n,ini);
        if(isValid(image, i,j+1,color,m,n,ini))
            floodFillRec(image, i,j+1,color,m,n,ini);
        if(isValid(image, i,j-1,color,m,n,ini))
            floodFillRec(image, i,j-1,color,m,n,ini);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m = image[0].size();
        int ini = image[sr][sc];
        
        if(ini==color)
        {
            return image;
        }
        floodFillRec(image, sr,sc,color, m ,n , ini);
        return image;
    }
};