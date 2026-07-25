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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        vector<long long>ans;

        long long sum=0;
        int level=0;

       

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            

            while(n--){
                TreeNode* front=q.front();

                sum+=front->val;

                q.pop();

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }

            ans.push_back(sum);
            sum=0;
            level++;


        }

         if(level<k){
            return -1;
        }

        sort(ans.begin(),ans.end(),greater<long long>()); // decreasing

        return ans[k-1];


        
    }
};