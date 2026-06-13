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
    void is_same_tree_helper(TreeNode *root1, TreeNode *root2, bool &res)
    {
        // Base Case
        if (!root1 && !root2)
        {
            return;
        }
        else if ((root1 && !root2) || (!root1 && root2))
        {
            res = false;
            return;
        }

        if (root1->val != root2->val)
        {
            res = false;
            return;
        }

        is_same_tree_helper(root1->left, root2->left, res);
        is_same_tree_helper(root1->right, root2->right, res);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool res = true;
        is_same_tree_helper(p, q, res);
        return res;
    }
};
