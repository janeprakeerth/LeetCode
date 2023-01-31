class Solution {
public:
    
   
    vector<int>solve(int n,vector<int>nums){
        vector<int>ok;
        int j = 0;
        while(n>0){
            int a = n &1;
            if(a){
                ok.push_back(nums[j]);
            }
            j++;
            n = n>>1;
        }
        return ok;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>ab = solve(i,nums);
            ans.push_back(ab);
        }
        
        return ans;
    }
};