class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int tot=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                tot+=nums[i];
                m[i]++;
            }
        }
        // cout<<tot<<endl;
        vector<int>output;
        for(int i=0;i<queries.size();i++){
            int index = queries[i][1];
            int x = nums[index] +queries[i][0];
            cout<<x<<"kokok"<<endl;
            if(m[index]){
                if(x%2==0){
                    tot+=x-nums[index];
                    nums[index] = x;
                }else{
                    tot-=nums[index];
                    nums[index] = x;
                    m[index]=0;
                }
                cout<<tot<<"ok"<<endl;
                output.push_back(tot);
            }
            else if(x%2==0){
                tot+=x;
                nums[index] = x;
                cout<<tot<<endl;
                output.push_back(tot);
                m[index]++;
            }else if(x%2==1 || x%2==-1){
                nums[index] = x;
                cout<<tot<<endl;
                output.push_back(tot);
            }
        }
        return output;
    }
};