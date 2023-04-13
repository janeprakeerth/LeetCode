//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int>m;
        int first = A[0];
        int sum_till_now = 0;
        int ans =INT_MIN;
        for(int i=0;i<A.size();i++){
            sum_till_now+=A[i];
            if(sum_till_now==0){
                ans = i+1-0;
            }
            else if(sum_till_now==first){
                ans = max(ans,i-0);
            }else if(m[sum_till_now]!=0){
                ans = max(ans,i-m[sum_till_now]);
            }else{
                m[sum_till_now] = i;
            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends