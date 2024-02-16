class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a.second<b.second;
        });
        int ans=0;
        for(auto it :v){
            if(k>=it.second){
                k=k-it.second;
                ans++;
            }else{
                break;
            }
        }
        return v.size()-ans;
    }
};