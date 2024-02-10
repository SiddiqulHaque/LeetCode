class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            int x=i-1,y=i+1;
            count++;
            while(x>=0 and y<=s.length()-1 and s[x]==s[y]){
                count++;
                x--;
                y++;
            }
            x=i,y=i+1;
            while(x>=0 and y<=s.length()-1 and s[x]==s[y]){
                count++;
                x--;
                y++;
            }
        }
        return count;
    }
};