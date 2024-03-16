class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum+=-1;
            }
            else{
                sum+=1;
            }
            if(mp.find(sum)!=mp.end()){
                auto it=mp[sum];
                int t=i-it;
                if(t>ans){
                    ans=t;
                }
            }
            else{
                mp[sum]=i;
            }
        } 
        return ans;
    }
};