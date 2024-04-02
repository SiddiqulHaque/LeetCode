class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> stt;
        unordered_map<char,char> tts;
        for(int i=0;i<s.length();i++){
            if(stt.find(s[i])!=stt.end()){
                if(stt[s[i]]!=t[i]){
                    return false;
                }
            }
            else if(tts.find(t[i])!=tts.end()){
                if(tts[t[i]]!=s[i]){
                    return false;
                }
            }
            stt[s[i]]=t[i];
            tts[t[i]]=s[i];
        }
        return true;
    }
};