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
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;
        
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        int level = 0;
        
        while (!levelQueue.empty()) {
            int currLevelSize = levelQueue.size();
            int prevNodeVal = (level % 2 == 0) ? 0 : 1000001;
            
            while (currLevelSize-- > 0) {
                TreeNode* currNode = levelQueue.front();
                levelQueue.pop();
                int currNodeVal = currNode->val;
                
                // Checks for naming even-odd binary tree
                if (level % 2 == 0) {
                    if (prevNodeVal >= currNodeVal || currNodeVal % 2 == 0)
                        return false;
                } else {
                    if (prevNodeVal <= currNodeVal || currNodeVal % 2 == 1)
                        return false;
                }
                
                prevNodeVal = currNodeVal;
                if (currNode->left)
                    levelQueue.push(currNode->left);
                if (currNode->right)
                    levelQueue.push(currNode->right);
            }
            level++;
        }
        return true;
    }
};