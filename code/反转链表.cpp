/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//use stack
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL)
            return NULL;

        stack <ListNode* > NodeList;
        ListNode* pri = NULL;
        ListNode* cur = NULL;
        while (pHead != NULL)
        {
            NodeList.push(pHead);
            pHead = pHead->next;
        }

        pHead = NodeList.top();
        NodeList.pop();
        pri = pHead;
        while (!NodeList.empty())
        {
            cur = NodeList.top();
            pri->next = cur;
            cur->next = NULL;   //attention : will form a loop, because now is pri->cur, cur->pri.
            pri = cur;
            NodeList.pop();
        }

        pri = pHead;
        while (pri != NULL)
        {
            cout << pri->val << ' ';
            pri = pri->next;
        }
        return pHead;
    }
};


// no use extra space
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL)
            return NULL;

        ListNode* pri = pHead;
        ListNode* cur = pHead->next;
        ListNode* behind = NULL;

        while (cur != NULL)
        {
            behind = cur->next;
            cur->next = pri;
            pri = cur;
            cur = behind;
        }

        pHead->next = NULL;
        pHead = pri;

        while (pri != NULL)
        {
            cout << pri->val << ' ';
            pri = pri->next;
        }

        return pHead;
    }
};
