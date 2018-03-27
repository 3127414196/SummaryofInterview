struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty()) {
			return NULL;
		}

		vector <int> left_pre, right_pre, left_in, right_in;
		int root_num = 0;

		TreeNode* root = new TreeNode(pre[0]);

		for (unsigned int i = 0; i < vin.size(); i++) {
			if (vin[i] == pre[0]) {
				root_num = i;
				break;
			}
		}

		for (int i = 0; i < root_num; i++) {
			left_pre.push_back(pre[i + 1]);
			left_in.push_back(vin[i]);
		}

		for (unsigned int i = root_num + 1; i < vin.size(); i++) {
			right_pre.push_back(pre[i]);
			right_in.push_back(vin[i]);
		}

		root->left = reConstructBinaryTree(left_pre, left_in);
		root->right = reConstructBinaryTree(right_pre, right_in);

		return root;
	}
};
