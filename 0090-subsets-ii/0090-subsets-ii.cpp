class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int x = nums.size();
        int a=pow(2,x);
        set<vector<int>>ans;
        for(int i=0;i<a;i++){
            vector<int>a;
            for(int j=0;j<nums.size();j++){
                if((1<<j)&i){
                    a.push_back(nums[j]);
                }
            }
            sort(a.begin(),a.end());
            ans.insert(a);
        }
        vector<vector<int>>abc;
        for(auto x:ans){
            abc.push_back(x);
        }
        return abc;
    }
};