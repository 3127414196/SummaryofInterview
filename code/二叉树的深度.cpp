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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;

        int lefttreedepth = TreeDepth(pRoot->left);
        int righttreedepth = TreeDepth(pRoot->right);

        return max(lefttreedepth, righttreedepth) + 1;
    }
};
