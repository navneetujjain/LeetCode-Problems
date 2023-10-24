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
    vector<int> largestValues(TreeNode* root) {

        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;


        while(!q.empty()){
            int size = q.size();

            vector<int> arr;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                arr.push_back(node -> val);

                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }

            int great = INT_MIN;
            for(int i = 0; i < arr.size(); i++){
                great = max(great, arr[i]);
            }

            ans.push_back(great);
        }

        return ans;
    }
};