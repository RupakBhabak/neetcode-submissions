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
    // BFS
    void level_order_helper(TreeNode *root, vector<vector<int>> &ans)
    {
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            int n = q.size();

            vector<int> curLevel;

            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();

                curLevel.push_back(cur->val);

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            ans.push_back(curLevel);
        }
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans = {};

        if (!root)
            return ans;

        level_order_helper(root, ans);

        return ans;
    }
};
