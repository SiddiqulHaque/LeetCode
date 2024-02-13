class Solution {
public:
    bool pal(string &s){
        int l=0;
        int r=s.length()-1;
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it :words){
            if(pal(it)){
                return it;
            }
        }
        return "";
    }
};