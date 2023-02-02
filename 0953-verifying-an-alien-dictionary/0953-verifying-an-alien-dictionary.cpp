class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>m;
        for(int i=0;i<order.length();i++){
            m[order[i]] = i+1;
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int s1 = words[i].length();
                int s2 = words[j].length();
                int num = min(s1,s2);
                bool x = true;
                for(int k=0;k<num;k++){
                    if(m[words[i][k]]<m[words[j][k]]){
                        x = false;
                        break;
                    }
                    if(m[words[i][k]]>m[words[j][k]]){
                        return false;
                    }
                }
                if(s1>s2 &&x){
                    return false;
                }
            }
        }
        return true;
    }
};