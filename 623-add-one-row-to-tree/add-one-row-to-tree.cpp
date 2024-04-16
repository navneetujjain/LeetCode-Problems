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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> nodesQueue;
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        depth = depth - 2;
        nodesQueue.push(root);
        while (depth--) {
            queue<TreeNode*> tempQueue;
            while (!nodesQueue.empty()) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();
                if (currentNode->left != nullptr)
                    tempQueue.push(currentNode->left);
                if (currentNode->right != nullptr)
                    tempQueue.push(currentNode->right);
            }
            nodesQueue = tempQueue;
        }
        while (!nodesQueue.empty()) {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();
            TreeNode* leftChild = currentNode->left;
            TreeNode* newLeftNode = new TreeNode(val);
            currentNode->left = newLeftNode;
            newLeftNode->left = leftChild;
            
            TreeNode* rightChild = currentNode->right;
            TreeNode* newRightNode = new TreeNode(val);
            currentNode->right = newRightNode;
            newRightNode->right = rightChild;
        }
        return root;
    }
};