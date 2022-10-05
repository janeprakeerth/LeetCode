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
    int count = 0;
    TreeNode *a;
    void solution(TreeNode* root,int val,int depth,int curr_depth,TreeNode *prev){
        
        if(depth==1){

            TreeNode* x= new TreeNode();
                x->val = val;
                x->left = root;
                x->right = NULL;
                root = x;
                a=root;
                cout<<root->left->val;
                return;
        }
        else if(depth==curr_depth){
            if(count%2==0){
                TreeNode* x= new TreeNode();
                x->val = val;
                x->left = prev->left;
                x->right = NULL;
                prev->left = x;
                count++;
            }else if(count%2==1){
                TreeNode* x= new TreeNode();
                x->val = val;
                x->right = prev->right;
                x->left = NULL;
                prev->right = x;
                count++;
            }
            
        }
        
        if(root==NULL){
            return;
        }
        
        
        solution(root->left,val,depth,curr_depth+1,root);
        solution(root->right,val,depth,curr_depth+1,root);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        solution(root,val,depth,1,NULL);
        if(depth==1){
            return a;
        }
        return root;
    }
};