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
    
    vector<vector<int>>output;
    
    void solve(TreeNode *root,int targetSum,vector<int>ok){
       if(root==NULL){
            return;
       }
        ok.push_back(root->val);
        targetSum-=root->val;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==0){
                output.push_back(ok);
            }
            return;
        }
        solve(root->left,targetSum,ok);
        solve(root->right,targetSum,ok);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ok;
        set<vector<int>>s;
        if(root==NULL){
            return {};
        }
        
        solve(root,targetSum,ok);
        
        return output;
    }
};