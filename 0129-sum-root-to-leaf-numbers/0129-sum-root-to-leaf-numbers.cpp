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
    void solve(TreeNode* root,vector<int>&ans,int &sum){
        
        if(root==NULL){
            return;
        }

        // NLR;
        ans.push_back(root->val);

        if(root->left ==NULL && root->right==NULL){

            int num=0;

            for(auto path:ans){
                num=num*10+path;
            }

            sum+=num;


        }

        solve(root->left,ans,sum);

        solve(root->right,ans,sum);

        // backtrack

        ans.pop_back();
    }
    int sumNumbers(TreeNode* root) {

        // NLR

        vector<int>ans;

        int sum=0;

          solve(root,ans,sum);

       

        return sum;

        
    }
};