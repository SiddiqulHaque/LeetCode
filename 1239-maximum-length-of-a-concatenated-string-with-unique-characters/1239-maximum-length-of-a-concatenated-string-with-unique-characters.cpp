class Solution {
public:
    int temp(int i,vector<string>& arr,unordered_map<char,int> mp){
        if(i==arr.size()){
            return 0;
        }
        int ntake=temp(i+1,arr,mp);
        for(auto it:arr[i]){
            if(mp.count(it)>=1){
                return ntake;
            }
            mp[it]=1;
        }
        int take=arr[i].length()+temp(i+1,arr,mp);
        return max(take,ntake);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> mp;
        return temp(0,arr,mp);
    }
};