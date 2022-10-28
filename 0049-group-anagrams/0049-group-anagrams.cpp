class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        
        for(int i=0;i<strs.size();i++){
            string x = strs[i];
            sort(x.begin(),x.end());
            m[x].push_back(strs[i]);
        }
        
        vector<vector<string>>a;
        for(auto b:m){
            a.push_back(b.second);
        }
        return a;
    }
};