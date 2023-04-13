//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long dp[1001][1001];
    long long solve(int coins[],int idx,int n,int sum){
        if(idx==n){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        return dp[idx][sum] = solve(coins,idx,n,sum-coins[idx])+solve(coins,idx+1,n,sum);
    }
    long long int count(int coins[], int N, int sum) {
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j] = -1;
            }
        }
        return solve(coins,0,N,sum);
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends