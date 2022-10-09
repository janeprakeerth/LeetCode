/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>num;
    
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        num.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        sort(num.begin(),num.end());
        int start = 0;
        int end = num.size()-1;
      
        while(start<end){
            if(num[start]+num[end]==k){
                return true;
            }
            
            if(num[start]+num[end]>k){
                end--;
            }
            if(num[start]+num[end]<k){
                start++;
            }
        }
        return false;
    }
};