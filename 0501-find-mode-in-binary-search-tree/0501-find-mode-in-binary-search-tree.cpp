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
    vector<int> ans;
    int val = INT_MIN, count = 0, maxi = 0;
    void f(TreeNode* node){
        if(node == NULL) return;

        f(node -> left);
        if(val == node -> val) count++;
        else{
            val = node -> val;
            count = 1;
        }

        if(count > maxi){
            maxi = count;
            ans = {node -> val};
        }
        else if(count == maxi) ans.push_back(node -> val);

        f(node -> right);

    }
    vector<int> findMode(TreeNode* root) {
        f(root);
        return ans;
    }
};