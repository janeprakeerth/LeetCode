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
    void triml(TreeNode* x,TreeNode *prev,int low){
        if(x==NULL){
            return;
        }
        if(x->val==low){
            x->left = NULL;
            // x->right = NULL;
            return;
        }
        if(x->val<low){
            prev->left = x->right;
            x->left = NULL;
            x = x->right;
            triml(x,prev,low);
            return;
        }
        if(x->val>low){
            prev = x;
            // x->right = NULL;
            x= x->left;
            triml(x,prev,low);
        }
    }
    
    void trimh(TreeNode* x,TreeNode *prev,int high){
        if(x==NULL){
            return;
        }
        if(x->val==high){
            // x->left = NULL;
            x->right = NULL;
            return;
        }
        if(x->val>high){
            prev->right = x->left;
            x->right = NULL;
            x = x->left;
            trimh(x,prev,high);
            return;
        }
        if(x->val<high){
            prev = x;
            // x->left = NULL;
            x= x->right;
            trimh(x,prev,high);
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode *ans = root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            if(x==NULL){
                continue;
            }
            if(x->val>high){
                ans = x->left;
                q.push(x->left);
            }else if(x->val<low){
                ans = x->right;
                q.push(x->right);
            }else if(x->val<=high && x->val>=low){
                ans = x;
                if(x->val==low){
                    x->left=NULL;
                }
                if(x->val==high){
                    x->right=NULL;
                }
                triml(x->left,x,low);
                trimh(x->right,x,high);
                return ans;
            }
        }
        return NULL;
    }
};