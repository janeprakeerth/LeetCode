class Solution {

public:

    bool increasingTriplet(vector<int>& nums) {

        int arr[3] = {INT_MAX,INT_MAX,INT_MAX};

        for(int i=0;i<nums.size();i++){

            for(int j=0;j<3;j++){

                if(arr[j]>=nums[i]){

                    arr[j] = nums[i];

                    if(j==2){

                        return true;

                    }

                    break;

                }

            }

        }

        return false;

    }

};