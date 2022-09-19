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
   vector<int>ok;
    void ans(TreeNode *root){
        if(root==NULL){
            return;
        }
        ok.push_back(root->val);
        ans(root->left);
        ans(root->right);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        ans(root);
        sort(ok.begin(),ok.end());
        return ok[k-1];
    }
};