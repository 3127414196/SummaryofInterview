class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if (length == 0)        //题目中规定为空格返回false
        	return false;

        int root_loc = length - 1;
        int right_tree = 0;
        int i = 0;
        for (i = 0; i < root_loc; i++)
        {
            if (sequence[i] >= sequence[root_loc])
                break;
        }
        right_tree = i;

        for (i = right_tree; i < root_loc; i++)
        {
            if(sequence[i] <= sequence[root_loc])
                return false;
        }

    	vector <int> lefttree;
    	vector <int> righttree;
        bool result1 = true;
        bool result2 = true;

        if (i < right_tree)
        {
            for (int i = 0; i < right_tree; i++)
                lefttree.push_back(sequence[i]);
            result1 = VerifySquenceOfBST(lefttree);
        }
        if (right_tree < root_loc - 1)
        {
            for (int i = right_tree; i < root_loc - 1; i++)
                righttree.push_back(sequence[i]);
            result2 = VerifySquenceOfBST(righttree);
        }
    	return result1 && result2;
    }
};
