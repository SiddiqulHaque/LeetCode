class Solution {
public:
   int mod = pow(10,9)+7;
    vector<vector<int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
    int temp(int m,int n,int k,int row,int col,vector<vector<vector<int>>>&dp){
        if((row>=m || row<0 || col>=n || col<0)){
            return 1;
        }
        if(k==0){
            return 0;
        }
        if(dp[row][col][k]!=-1) return dp[row][col][k]%mod;
        int ans=0;
        for(auto i: dirs)
        {
            ans+=(temp(m,n,k-1,row+i[0],col+i[1],dp));
            ans%=mod;
        }
        return dp[row][col][k]=ans%mod;
    }
    int findPaths(int m, int n, int k, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return temp(m,n,k,startRow,startColumn,dp)%mod;
    }
};