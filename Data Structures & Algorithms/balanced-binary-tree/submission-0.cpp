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
    int is_balanced_helper(TreeNode *root, bool &res)
    {
        // Base Case
        if (!root)
            return 0;

        int leftHeight = is_balanced_helper(root->left, res);
        int rightHeight = is_balanced_helper(root->right, res);

        if (abs(leftHeight - rightHeight) > 1)
            res = false;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        bool res = true;
        is_balanced_helper(root, res);
        return res;
    }
};
