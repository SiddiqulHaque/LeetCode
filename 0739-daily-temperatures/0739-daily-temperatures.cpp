class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]>arr[s.top()]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};