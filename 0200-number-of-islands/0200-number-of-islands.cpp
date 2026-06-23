class Solution {
public:

    void graphIslands(int i,int j, vector<vector<bool>> &vis,vector<vector<char>>& grid,int n,int m){
        
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] != '1' || vis[i][j] ){
            return;
        }
       
        vis[i][j]=true;

        graphIslands(i-1,j,vis,grid,n,m);//top
        graphIslands(i+1,j,vis,grid,n,m);//bottom
        graphIslands(i,j-1,vis,grid,n,m);//left
        graphIslands(i,j+1,vis,grid,n,m);//right

    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),islands=0;
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    graphIslands(i,j,vis,grid,n,m);
                    islands++;
                }          
            }
        }
        return islands;
    }
};