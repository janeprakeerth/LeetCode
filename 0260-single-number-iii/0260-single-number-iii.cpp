class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0;
        // for(int i=0;i<nums.size();i++){
        //     int x = 1e9+7;
        //     nums[i] = nums[i]%x;
        // }
        for(int i=0;i<nums.size();i++){
            n = n ^ nums[i];
        }
        int two_comp;
        if(n==-2147483648){
            two_comp =n; 
        }else{
            two_comp = ~n+1;
        }
        int rsb = n & two_comp;
        int a = 0;
        int b = 0;
        for(int i=0;i<nums.size();i++){
            int ok = nums[i]&rsb;
            if(ok!=0){
                a = a^nums[i];
            }else{
                b = b ^nums[i];
            }
        }
        return {a,b};
    }
};