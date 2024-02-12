class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int ans=0;
       int count=1;
       for(int i=1;i<nums.size();i++)
       {
            if(nums[i]==nums[ans]){
               count++;
           }
           else {
                count--;
           }
           if(count==0)
           {
               ans=i;
               count=1;
           }
       }
       count=0;
       int result;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[ans]==nums[i])
           count++;
       }
       if(count>(nums.size()/2))
        result=nums[ans];
       return result;
    }
};