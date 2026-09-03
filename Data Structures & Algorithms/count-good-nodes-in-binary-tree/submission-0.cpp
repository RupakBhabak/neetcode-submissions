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
    int good_nodes_helper(TreeNode *root, int pathMax)
    {
        if (!root)
            return 0;

        bool isGood = false;

        if (pathMax <= root->val)
            isGood = true;

        int leftCount = good_nodes_helper(root->left, max(pathMax, root->val));
        int rightCount = good_nodes_helper(root->right, max(pathMax, root->val));

        if (isGood)
            return 1 + leftCount + rightCount;
        else
            return leftCount + rightCount;
    }

    int goodNodes(TreeNode *root)
    {
        return good_nodes_helper(root, INT_MIN);
    }
};
