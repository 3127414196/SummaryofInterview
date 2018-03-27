class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int num = 0;
        if (stack2.empty())	//如果栈中没有元素
        {
            while (!stack1.empty())
            {
                num = stack1.top();
                stack1.pop();
                stack2.push(num);
            }
            if (!stack2.empty())
            {
                num = stack2.top();
                stack2.pop();
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            num = stack2.top();
            stack2.pop();
        }
        return num;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
