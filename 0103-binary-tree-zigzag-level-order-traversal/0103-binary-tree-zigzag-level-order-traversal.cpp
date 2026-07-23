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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        bool leftToright=true;


        

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int n=q.size();

            vector<int>temp;
            while(n--){
                TreeNode* front=q.front();

                q.pop();

                temp.push_back(front->val);

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }

            }

            if(!leftToright){
                reverse(temp.begin(),temp.end());
            }
                ans.push_back(temp);
             leftToright=!leftToright;
        }

        return ans;
    }
};