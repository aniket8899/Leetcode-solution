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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>st;

        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];


            // agar parent node exist nhi karta

            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }

            // agar child node exist nhi karta

            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }

            if(isleft==1){
                mp[parent]->left=mp[child];
            }else{
                mp[parent]->right=mp[child];
            }

            st.insert(child);

        }

        for(auto it:descriptions){
            int parent=it[0];

            if(st.find(parent)==st.end()){
                return mp[parent];
            }
        }

        return NULL;
        
    }
};