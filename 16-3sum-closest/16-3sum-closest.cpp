class Solution {
public:
        int threeSumClosest(vector<int>& nums, int target) {
		// Sorting will save us a lot of time later on
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        
		// Frist iterator first is i(left most), mid one is j and last one is k
		
        for(int i=0; i<nums.size()-2; i++){
			// Check for every value of i while changing j and k
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k){
                int newSum = nums[i] + nums[j]+ nums[k];
                if(abs(newSum-target) < abs(res-target)) res = newSum;
                
				// Increase j if target is bigger, or decrease k if target is lesser
                if(newSum < target) j++;
                else k--;
            }
        }
        
        return res;
    }
};