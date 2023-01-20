class Solution {
public:
    
    vector<vector<int>>ab;
    
    void solve(vector<int>nums,vector<int>permu,map<int,int>taken){
        
        if(permu.size()==nums.size()){
            ab.push_back(permu);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int>ok = permu;
            map<int,int>te = taken;
            
            if(!taken[i]){
                te[i] = 1;
                ok.push_back(nums[i]);
                solve(nums,ok,te);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int>x;
        solve(nums,{},x);
        return ab;
    }
};