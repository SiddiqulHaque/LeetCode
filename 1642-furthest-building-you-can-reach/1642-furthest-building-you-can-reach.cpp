class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
         int i=0;
        int n=nums.size();
        int Max=INT_MIN;
        long long sum=0;
        priority_queue<int>pq;
        while(ladders>0 && i<n-1){
            if(nums[i]<nums[i+1]){
                 int diff=nums[i+1]-nums[i];
                 pq.push(diff);
                sum+=diff;
                if(sum>bricks){
                    sum-=pq.top();
                    pq.pop();
                    ladders--;
              }    
            }
               i++;
        }
        while(sum<=bricks && i<n-1){
            if(nums[i]<nums[i+1]){
                sum+=nums[i+1]-nums[i];
                if(sum>bricks)
                break;
            }
            i++;
        }
        return i;
    }
};