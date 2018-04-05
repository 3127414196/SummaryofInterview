class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        int inputlength = input.size();
        if (inputlength == 0 || inputlength < k)    //当元素个数小于k时，返回空的vector
            return result;

        set<int> minnum;

        for (int i = 0; i < inputlength; i++)
            minnum.insert(input[i]);

        set<int>::iterator it;
        int i = 0;
        for (it = minnum.begin(); it != minnum.end() && i < k; it++){
                result.push_back(*it);
                i++;
        }
        return result;
    }
};
