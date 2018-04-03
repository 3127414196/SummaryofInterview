class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL)
            return true;
        int depth = 0;  //注意这里要有变量分配存储区，不然直接传0过去不能够写。
        return IsBalanced_Solution(pRoot, &depth);
    }
    bool IsBalanced_Solution(TreeNode* pRoot, int *depth)
    {
        if (pRoot == NULL)
        {
            depth = 0;
            return true;
        }

        int leftdepth = 0;
        int rightdepth = 0;

        if (IsBalanced_Solution(pRoot->left, &leftdepth) && IsBalanced_Solution(pRoot->right, &rightdepth))
        {
            int diff = leftdepth - rightdepth;
            if (diff <= 1 && diff >= -1)
            {
                *depth = max(leftdepth, rightdepth) + 1;
                return true;
            }
            else
                return false;
        }
        return false;
    }
};
