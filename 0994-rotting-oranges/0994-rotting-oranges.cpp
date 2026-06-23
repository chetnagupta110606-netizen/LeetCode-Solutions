class Solution {
public:
    queue<pair<pair<int,int>,int>> q;

    int orangesRotting(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }

        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();

            ans=max(ans,t);
            
            if(i-1 >=0 && !vis[i-1][j] && grid[i-1][j]==1){//top
                q.push({{i-1,j},t+1});
                vis[i-1][j]=true;
            }
            if(i+1 <m && !vis[i+1][j] && grid[i+1][j]==1){//bottom
                q.push({{i+1,j},t+1});
                vis[i+1][j]=true;
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1]==1){//left
                q.push({{i,j-1},t+1});
                vis[i][j-1]=true;
            }
            if(j+1 <n && !vis[i][j+1] && grid[i][j+1]==1){//right
                q.push({{i,j+1},t+1});
                vis[i][j+1]=true;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j] ){
                    return -1;
                }
            }
        }
        return ans;
    }
};