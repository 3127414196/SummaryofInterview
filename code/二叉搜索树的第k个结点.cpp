/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL || k < 1)
            return NULL;

        return SeekNode(pRoot, &k);
    }
    TreeNode* SeekNode(TreeNode* pRoot, int* k)
    {
        TreeNode* target = NULL;
        if (pRoot->left != NULL)
            target = SeekNode(pRoot->left, k);
        if (target == NULL)
        {
            (*k)--;
            if (*k == 0)
                return pRoot;
        }
        if (target == NULL && pRoot->right != NULL)
            target = SeekNode(pRoot->right, k);
        return target;
    }
};
