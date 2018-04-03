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
    vector<vector<int> >path;
    vector<int> curpath;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL)
            return path;

        curpath.push_back(root->val);
        if ((expectNumber == root->val) && (root->left == NULL) && (root->right == NULL))
        {
            path.push_back(curpath);
        }

        if (root->left != NULL)
            FindPath(root->left, expectNumber - root->val);
        if (root->right != NULL)
            FindPath(root->right, expectNumber - root->val);

        curpath.pop_back();
        return path;
    }
};
