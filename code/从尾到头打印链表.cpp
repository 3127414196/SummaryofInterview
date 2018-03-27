/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack <ListNode *> stacklist;
        vector <int> plist;
        ListNode *phead = head;

        while (phead != NULL)
        {
            stacklist.push(phead);
            phead = phead->next;
        }

        while(!stacklist.empty())   //注意empty()函数当为空返回的是ture,不为空时返回false
        {
            phead = stacklist.top();  //stack需要使用这个来得到栈顶的数据
            stacklist.pop();
            if (phead != NULL)
                plist.push_back(phead->val);
        }
        return plist;
    }
};
