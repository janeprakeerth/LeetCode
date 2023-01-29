class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>ok;
        for(int i=0;i<=nums.size();i++){
            ok.push_back(i);
        }
        int a = 0;
        for(int i=0;i<nums.size();i++){
            a^=nums[i];
            a^=ok[i];
        }
        a^=ok[nums.size()];
        return a;
    }
};