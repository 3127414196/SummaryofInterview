/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        stack<ListNode* > Nodestack1;
        stack<ListNode* > Nodestack2;

        while (pHead1 != NULL) {
            Nodestack1.push(pHead1);
            pHead1 = pHead1->next;
        }

        while (pHead2 != NULL) {
            Nodestack2.push(pHead2);
            pHead2 = pHead2->next;
        }

        ListNode *pri = NULL;
        while (!Nodestack1.empty() && !Nodestack2.empty()) {
            if (Nodestack1.top() != Nodestack2.top())
                break;
            pri = Nodestack1.top();
            Nodestack1.pop();
            Nodestack2.pop();
        }

        return pri;
    }
};
