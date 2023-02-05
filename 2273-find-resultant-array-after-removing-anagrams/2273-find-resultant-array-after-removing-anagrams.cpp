class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        int i=0,j=1;
        ans.push_back(words[0]);
        while(i<words.size()-1 &&j<words.size()){
            map<char,int>m1;
            map<char,int>m2;
            for(int k=0;k<words[i].length();k++){
                m1[words[i][k]]++;
            }
            for(int k=0;k<words[j].length();k++){
                m2[words[j][k]]++;
            }
            if(m1==m2){
                j++;
            }
            if(m1!=m2){
                i=j;
                j++;
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};