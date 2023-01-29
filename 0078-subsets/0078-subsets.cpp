class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int x = nums.size();
        int a=pow(2,x);
        vector<vector<int>>ans;
        for(int i=0;i<a;i++){
            vector<int>a;
            for(int j=0;j<nums.size();j++){
                if((1<<j)&i){
                    a.push_back(nums[j]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};