class Solution {
public:
    void push(int value) {
        if (min_number.empty())
        {
            number.push(value);
            min_number.push(value);
        }
        else
        {
            if (value < min_number.top())
            {
                number.push(value);
                min_number.push(value);
            }
            else
            {
                number.push(value);
                min_number.push(min_number.top());
            }
        }
    }
    void pop() {
        number.pop();
        min_number.pop();
    }
    int top() {
        return number.top();
    }
    int min() {
        return min_number.top();
    }
    stack <int> number;
    stack <int> min_number;
};
