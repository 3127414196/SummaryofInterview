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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0)
            return NULL;
        stack <ListNode *> Nodestack;

        ListNode* pHead = pListHead;

        int count = 0;
        while(pHead != NULL)
        {
            Nodestack.push(pHead);
            pHead = pHead->next;
            count ++;
        }

        if (k > count)      //need to decide whether overflow
            return NULL;

        for (int i = 1; i < k; i++)
            Nodestack.pop();

        return Nodestack.top();
    }
};
