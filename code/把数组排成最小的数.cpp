class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string result = "";
        if (numbers.empty())
            return result;

        int numberlength = numbers.size();
        sort(numbers.begin(), numbers.end(), compare);

        for (int i = 0; i < numberlength; i++)
            result = result + to_string(numbers[i]);
        return result;
    }
    static bool compare(int num1, int num2)     //注意这里用static类型
    {
        char num1num2[20];
        char num2num1[20];

        sprintf(num1num2, "%d%d", num1, num2);
        sprintf(num2num1, "%d%d", num2, num1);

        return (strcmp(num1num2, num2num1) > 0) ? false : true; //注意这里strcmp返回的始终>=0，但是要求的是true or false
    }
};
