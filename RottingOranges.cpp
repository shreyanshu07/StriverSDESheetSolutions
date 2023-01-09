class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        queue<vector<int>> q;
        bool vis[n][m];
        memset(vis,false,sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {q.push({i,j,0});vis[i][j]=true;}
            }
        }
        
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            
            if((v[0]>0) and (!vis[v[0]-1][v[1]])){
                vis[v[0]-1][v[1]]=true;
                if((grid[v[0]-1][v[1]]==1)) {
                    grid[v[0]-1][v[1]]=2;
                    q.push({v[0]-1,v[1],v[2]+1});
                }
            }
            if((v[0]<n-1) and (!vis[v[0]+1][v[1]])){
                vis[v[0]+1][v[1]]=true;
                if(grid[v[0]+1][v[1]]==1) {
                    grid[v[0]+1][v[1]]=2;
                    q.push({v[0]+1,v[1],v[2]+1});
                }
            }
            if((v[1]>0) and (!vis[v[0]][v[1]-1])){
                vis[v[0]][v[1]-1]=true;
                if(grid[v[0]][v[1]-1]==1) {
                    grid[v[0]][v[1]-1]=2;
                    q.push({v[0],v[1]-1,v[2]+1});
                }
            }
            if((v[1]<m-1) and (!vis[v[0]][v[1]+1])){
                vis[v[0]][v[1]+1]=true;
                if(grid[v[0]][v[1]+1]==1) {
                    grid[v[0]][v[1]+1]=2;
                    q.push({v[0],v[1]+1,v[2]+1});
                }
            }
            ans=max(ans,v[2]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false and grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
