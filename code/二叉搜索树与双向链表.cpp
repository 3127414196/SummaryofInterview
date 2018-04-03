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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;

        TreeNode* TreeLastNode = NULL;
        Convert(pRootOfTree, &TreeLastNode);

        while (TreeLastNode->left != NULL) {
            TreeLastNode = TreeLastNode->left;
        }

        return TreeLastNode;
    }

    void Convert(TreeNode* pRootOfTree, TreeNode** TreeLastNode)
    {
        if (pRootOfTree->left != NULL)
            Convert(pRootOfTree->left, TreeLastNode);

        pRootOfTree->left = *TreeLastNode;
        if (*TreeLastNode != NULL)
            (*TreeLastNode)->right = pRootOfTree;

        *TreeLastNode = pRootOfTree;

        if (pRootOfTree->right != NULL)
            Convert(pRootOfTree->right, TreeLastNode);
    }
};
