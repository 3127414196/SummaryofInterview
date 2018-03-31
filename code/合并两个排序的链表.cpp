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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL)
            return NULL;

        ListNode tempHead(0);
        ListNode* MergeHead = &tempHead;

        while (pHead1 != NULL && pHead2 != NULL)
        {
            if (pHead1->val <= pHead2->val)
            {
                MergeHead->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                MergeHead->next = pHead2;
                pHead2 = pHead2->next;
            }

            MergeHead = MergeHead->next;
        }

        if (pHead1 == NULL)
            MergeHead->next = pHead2;
        else
            MergeHead->next = pHead1;

        return tempHead.next;
    }
};
