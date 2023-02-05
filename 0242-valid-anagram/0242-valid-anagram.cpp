class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;
        if(s.length()!=t.length()){
            return false;
        }else{
            for(int i=0;i<s.length();i++){
                m1[s[i]]++;
                m2[t[i]]++;
            }
            
        }
        if(m1==m2){
            return true;
        }else{
            return false;
        }
    }
};