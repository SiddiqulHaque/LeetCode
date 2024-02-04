class Solution {
public:
    string minWindow(string s, string t) {
        int starti=0;
        int endi=-1;
        int slen = s.length();
        int tlen = t.length(); 
        unordered_map<char,int> mp;
        for(int i=0;i<tlen;i++)
            mp[t[i]]++;
        int count = mp.size();
        string res = "";
        if(slen<tlen)
            return res;
        if(s==t)
            return s;
        int ans = INT_MAX;
        int ans_i = 0;
        while(endi<slen){
            if(count!=0){
                endi++;
                if(mp.find(s[endi])!=mp.end()){
                    mp[s[endi]]--;
                    if(mp[s[endi]]==0)
                        count--;
                    
                }
            }
            while(count==0 && starti<slen){
                if(ans>(endi-starti)+1){
                    ans = (endi-starti)+1;
                    ans_i = starti;
                }
                if(mp.find(s[starti])!=mp.end()){
                    mp[s[starti]]++;
                    if(mp[s[starti]]>0)
                        count++;
                }
                starti++;
            }
        }
        if(ans==INT_MAX)
            return "";
        return s.substr(ans_i,ans);
    }
};