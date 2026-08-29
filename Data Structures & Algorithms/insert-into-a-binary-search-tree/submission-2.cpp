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
    void insertion_helper(TreeNode *root, int &val)
    {
        if (!root)
            return;

        if (val > root->val)
        {
            if (!root->right)
            {
                root->right = new TreeNode(val);
                return;
            }
            else
            {
                insertion_helper(root->right, val);
            }
        }
        else
        {
            if (!root->left)
            {
                root->left = new TreeNode(val);
                return;
            }
            else
            {
                insertion_helper(root->left, val);
            }
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *head = root;

        insertion_helper(root, val);

        return head;
    }
};