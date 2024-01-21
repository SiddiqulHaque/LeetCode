class Solution {
public:
//simple recursion 
    int srecur(vector<int> &nums,int ind){
        if(ind==0)
        return nums[ind];
        if(ind<0)
        return 0;
        int pick=nums[ind] + srecur(nums,ind-2);
        int notpick= 0+ srecur(nums,ind-1);
        return max(pick,notpick);
    }
    //memoisation 
    int memo(vector<int> &nums,vector<int>&dp,int ind){
        if(ind==0)
        return nums[ind];
        if(ind<0)
        return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind] + memo(nums,dp,ind-2);
        int notpick= 0+ memo(nums,dp,ind-1);
        return dp[ind]=max(pick,notpick);
    }
    //space optimisation 

    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> dp(n,-1);
        // int ind=nums.size()-1;
        // return memo(nums,dp,ind);
        //space optimisation
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=0+prev;
            int curi=max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};