class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        vector<pair<int,char>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(int i=0;i<v.size();i++){
            int temp=v[i].first;
            while(temp--){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};