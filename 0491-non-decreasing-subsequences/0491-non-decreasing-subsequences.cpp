class Solution {
public:
    set<vector<int>>ans;
    
    void solve(vector<int>nums,vector<int>subSeq,int index,int max){
        if(nums.size()==index){
            if(subSeq.size()>1){
                ans.insert(subSeq);
            }
            return;
        }
        
        if(nums[index]>=max){
            vector<int>ok = subSeq;
            ok.push_back(nums[index]);
            solve(nums,ok,index+1,nums[index]);
            solve(nums,subSeq,index+1,max);
        }else{
            solve(nums,subSeq,index+1,max);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,{},0,INT_MIN);
        vector<vector<int>>ab;
        for(vector<int>x:ans){
            ab.push_back(x);
        }
        return ab;
    }
};