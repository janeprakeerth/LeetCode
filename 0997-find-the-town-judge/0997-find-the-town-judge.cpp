class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int>x;
        map<int,int>m;
        map<int,int>tr;
        for(int i=0;i<trust.size();i++){
            m[trust[i][0]]++;
            tr[trust[i][1]]++;
            x.insert(trust[i][0]);
            x.insert(trust[i][1]);
        }
        
        for(auto a:x){
            if(m[a]==0 && tr[a]==n-1){
                return a;
            }
        }
        if(trust.size()==0 && n==1){
            return n;
        }
        return -1;
    }
};