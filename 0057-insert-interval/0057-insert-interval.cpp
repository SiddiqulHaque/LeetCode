class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newin) {
        vector<vector<int>> ans;
        for(auto it:in){
            if(it[1]<newin[0]){
                ans.push_back(it);
            }
            else if(it[0]>newin[1]){
                ans.push_back(newin);
                newin=it;
            }
            else{
                newin[0]=min(it[0],newin[0]);
                newin[1]=max(it[1],newin[1]);
            }
        }
        ans.push_back(newin);
        return ans;
    }
};