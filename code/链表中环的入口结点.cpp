/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;

        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        bool isring = true;

        while (p2 != NULL) {
            p1 = p1->next;
            if (p2->next == NULL)
            {
                isring = false;
                break;
            }
            p2 = p2->next->next;
            if (p1 == p2)   //注意移到下方，因为p1=p2=pHead
                break;
        }

        if (p2 == NULL || isring == false)
            return NULL;

        int ringsize = 0;
        p2 = p2->next;  //注意这里已经是p1==p2
        while (p1 != p2) {
            p2 = p2->next;
            ringsize++;
        }
        p1 = pHead;
        p2 = pHead;
        for (int i = 0; i <= ringsize; i++) //环的数量少记录了1
            p1 = p1->next;

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};
