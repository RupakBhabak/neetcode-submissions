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
class Solution
{
public:
    pair<int, int> rob_helper(TreeNode *root)
    {
        // B.C.
        if (!root)
            return {0, 0};

        pair<int, int> case1 = rob_helper(root->left);
        pair<int, int> case2 = rob_helper(root->right);

        pair<int, int> curCase = {root->val + case1.second + case2.second, max(case1.first, case1.second) + max(case2.first, case2.second)};

        return curCase;
    }

    int rob(TreeNode *root)
    {
        // cases -> pair(withRoot, withoutRoot)
        pair<int, int> cases = rob_helper(root);

        return max(cases.first, cases.second);
    }
};