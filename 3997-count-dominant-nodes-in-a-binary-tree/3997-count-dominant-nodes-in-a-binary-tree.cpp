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

    // is question me sabsa phala leaf node tar phauch kar maximum find karna ka baad usa node value se compare karenga ki equal to nhi h yehi dominant ka definition h

    int solve(TreeNode* root,int& cnt){
        if(root==NULL){
            return NULL;
        }

        // LRN ->postorder

        int left=solve(root->left,cnt);
        int right=solve(root->right,cnt);

        int maxi=max(root->val,max(left,right));

        if(maxi==root->val){
            cnt++;
        }

        return maxi;
    }

    int countDominantNodes(TreeNode* root) {

        int cnt=0;

        solve(root,cnt);

        return cnt;

        
    }
};