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
    int getheight(TreeNode* root){
        if(root==NULL) return 0;

        int lh=getheight(root->left);
        int rh=getheight(root->right);
        int maxheight=max(lh,rh);

        return maxheight+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=getheight(root->left);
        int rh=getheight(root->right);
        int absdiff=abs(lh-rh);

        bool status=(absdiff<=1);

        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);

        if(status && leftans&& rightans){
            return true;
        }
        else{
            return false;
        }
        
    }
};