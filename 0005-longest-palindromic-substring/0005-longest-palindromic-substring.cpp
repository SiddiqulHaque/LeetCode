class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int len=0;
        int n=s.length();
        for(int i=0;i<s.length();i++){
            // for odd length
            int l=i,r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            // for even length
            int l1=i,r1=i+1;
            while(l1>=0 and r1<n and s[l1]==s[r1]){
                if(r1-l1+1>len){
                    len=r1-l1+1;
                    ans=s.substr(l1,r1-l1+1);
                }
                l1--;
                r1++;
            }
        }
        return ans;
    }
};