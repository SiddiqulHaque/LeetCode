class Solution {
public:
    int temp(int row,int col1,int col2,vector<vector<int>> &grid,vector<vector<vector<int>>> & dp){
        int m=grid.size();
        int n=grid[0].size();
        if(col1>=n || col2>=n || col1<0 || col2<0){
            return -1e9;
        }
        if(row==m-1){
            if(col1==col2){
                return grid[row][col1];

            }else{
                return grid[row][col1]+grid[row][col2];
            }
        }
        if(dp[row][col1][col2]!=-1){
            return dp[row][col1][col2];
        }
        int ans=-1e8;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int t=0;
                if(col1==col2){
                    t=grid[row][col1];
                }
                else{
                    t=grid[row][col1]+grid[row][col2];
                }
                t+=temp(row+1,col1+i,col2+j,grid,dp);
                ans=max(ans,t);
            }
        }
        return dp[row][col1][col2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return temp(0,0,n-1,grid,dp);
    }
};