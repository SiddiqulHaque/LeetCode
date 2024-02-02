class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // queue<int> q = {{1,2,3,4,5,6,7,8,9}};
        vector<int> ans;
        for(int i=1;i<9;i++){
            int num=i;
            for(int j=i+1;j<=9;j++){
                num=num*10+j;
                if(num>=low and num<=high){
                    ans.push_back(num);
                    // break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};