class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int dup,miss;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                dup=nums[i];
                break;
            }
            
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int t=(n*(n+1))/2;
        miss=t+dup-sum;
        return {dup,miss};
        
    }
};