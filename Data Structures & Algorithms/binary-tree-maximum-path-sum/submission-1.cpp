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
    int ans=INT_MIN;
    int f(TreeNode* root){
        if(root==NULL)return 0;
        int l=root->val+f(root->left);
        int r=root->val+f(root->right);
        int sum=l+r-root->val;
        ans=max({ans,l,r,sum});
        return max(l,r)<0?0:max(l,r);
    }
    int maxPathSum(TreeNode* root) {
     f(root);
     return ans;
    }
};
