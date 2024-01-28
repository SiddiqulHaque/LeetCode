class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_map<int,int> m;
        int count=0;
        int currsum=0;
        int i=0;
        while(i<n){
            currsum=currsum+nums[i];
            if(currsum==k){
                count=count+1;
            }
            if(m.find(currsum-k)!=m.end()){
                count=count+m[currsum-k];
            }
            m[currsum]=m[currsum]+1;
            i++;
        }
        return count;
    }
};