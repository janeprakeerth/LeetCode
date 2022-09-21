class Solution {
public:
    
 
    bool canJump(vector<int>& nums) {
        int x = nums.size()-1;
        
        bool canReach = false;
        int curr = x;
        if(nums.size()==1){
            return true;
        }
        while(x>0){
            int sum = x-1 + nums[x-1];
            if(sum>=curr){
                canReach = true;
                curr = x-1;
            }else{
                canReach = false;
            }
            x--;
        }
        
        return canReach;
    }
};