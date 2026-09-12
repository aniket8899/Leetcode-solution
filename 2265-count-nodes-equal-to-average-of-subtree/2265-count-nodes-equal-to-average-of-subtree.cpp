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
    int result;
    pair<int,int>solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }

        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);

        int totalsum=left.first+right.first+root->val;

        int cnt=left.second+right.second+1;

        int average=totalsum/cnt;

        if(root->val==average){
            result++;
        }

        return {totalsum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {

         result=0;

         solve(root);

        return result;
        
    }
};