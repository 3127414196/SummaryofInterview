// ForInterview.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <bits/stdc++.h>

using namespace std;


struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

void BuildNodes(RandomListNode* pNode, RandomListNode* pNext, RandomListNode* pSibling)
{
    if (pNode != nullptr)
    {
        pNode->next = pNext;
        pNode->random = pSibling;
    }
}

void PrintList(RandomListNode* pHead)
{
    RandomListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->label);

        if (pNode->random != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->random->label);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->next;
    }
}

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        RandomListNode* cur = pHead;
        RandomListNode* NewTreeHead = NULL;

        while (cur != NULL)
        {
            RandomListNode *newnode = new RandomListNode(cur->label);
            newnode->next = cur->next;
            cur->next = newnode;
            cur = cur->next->next;
        }
        cur = pHead;
        while (cur != NULL)
        {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        NewTreeHead = pHead->next;
        cur = pHead;
        RandomListNode *pclone = NewTreeHead;
        while (cur != NULL && pclone != NULL)
        {
            cur->next = cur->next->next;
            if (cur->next != NULL)      //attention :之前是去判断cur->next->next是否为空，事实上并不需要去判断，而且由于去读空指针会导致越界
                pclone->next = pclone->next->next;
            else
                pclone->next = NULL;
            pclone = pclone->next;
            cur = cur->next;
        }

        return NewTreeHead;
    }
};

// ====================测试代码====================
void Test(const char* testName, RandomListNode* pHead)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    Solution A;
    RandomListNode* pClonedHead = A.Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

void Test1()
{
    RandomListNode* pNode1 = new RandomListNode(1);
    RandomListNode* pNode2 = new RandomListNode(2);
    RandomListNode* pNode3 = new RandomListNode(3);
    RandomListNode* pNode4 = new RandomListNode(4);
    RandomListNode* pNode5 = new RandomListNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}
int main(void)
{
    Test1();
	return 0;
}
