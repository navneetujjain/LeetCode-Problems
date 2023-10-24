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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node -> val);

                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }

            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};