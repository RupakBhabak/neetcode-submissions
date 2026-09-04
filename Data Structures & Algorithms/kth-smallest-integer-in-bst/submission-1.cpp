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
    stack<int> s;
    int count = 0;

    void dfs(TreeNode *root, int &k, int &ans)
    {
        if (!root)
        {
            if (!s.empty())
            {
                int top = s.top();
                s.pop();
                count++;

                if (count == k)
                    ans = top;
            }

            return;
        }

        s.push(root->val);

        dfs(root->left, k, ans);

        dfs(root->right, k, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int ans;

        dfs(root, k, ans);

        return ans;
    }
};
