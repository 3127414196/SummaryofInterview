/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if(IsSameTree(pRoot1, pRoot2) == false)
        {
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
        else
            return true;
    }

    bool IsSameTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL)
            return false;

        if (pRoot1->val != pRoot2->val)
        {
            return false;
        }
        else
        {
            return IsSameTree(pRoot1->left, pRoot2->left) && IsSameTree(pRoot1->right, pRoot2->right);
        }
    }
};
