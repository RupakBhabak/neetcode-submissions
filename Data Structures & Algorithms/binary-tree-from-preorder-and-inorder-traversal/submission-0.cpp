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
    unordered_map<int, int> m; // map -> (item, freq) of preorder
    int i = 0;

    TreeNode *build_tree_helper(vector<int> &preorder, vector<int> &inorder, int l, int r)
    {
        if (l > r)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[i]);

        if (l == r)
        {
            i++;
            return root;
        }

        int mid = m[preorder[i]];
        i++;

        root->left = build_tree_helper(preorder, inorder, l, mid - 1);
        root->right = build_tree_helper(preorder, inorder, mid + 1, r);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        return build_tree_helper(preorder, inorder, 0, preorder.size() - 1);
    }
};