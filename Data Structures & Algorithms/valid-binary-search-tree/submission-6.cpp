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
    bool valid_bst_helper(TreeNode *root, int left, int right)
    {
        if (!root)
            return true;

        if (!(left < root->val && root->val < right))
            return false;

        bool leftRes = valid_bst_helper(root->left, left, root->val);

        bool rightRes = valid_bst_helper(root->right, root->val, right);

        return leftRes && rightRes;
    }

    bool isValidBST(TreeNode *root)
    {
        return valid_bst_helper(root, INT_MIN, INT_MAX);
    }
};
