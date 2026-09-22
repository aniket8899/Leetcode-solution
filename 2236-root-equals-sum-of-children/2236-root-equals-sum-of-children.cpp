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
    bool checkTree(TreeNode* root) {
        if(root==NULL) return true;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();

            while(size--){
                TreeNode* front=q.front();
                int sum=0;
                q.pop();

                if(front->left){
                    sum+=front->left->val;
                    q.push(front->left);
                }

                if(front->right){
                    sum+=front->right->val;
                    q.push(front->right);
                }

                if(front->val!=sum && (front->left ||front->right)){
                    return false;
                }
            }
        }

        return true;
    }
};