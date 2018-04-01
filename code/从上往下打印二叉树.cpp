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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue <TreeNode* > NodeQueue;
        vector <int> result;

        while(root != NULL)
        {
            if (root->left != NULL)
                NodeQueue.push(root->left);
            if (root->right != NULL)
                NodeQueue.push(root->right);

            result.push_back(root->val);
            if(NodeQueue.empty())
                break;
            else
            {
                root = NodeQueue.front();
                NodeQueue.pop();
            }
        }

        return result;
    }
};
