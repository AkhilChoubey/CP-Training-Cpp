#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int length(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count += 1;
        head = head->next;
    }
    return count;
}

ListNode *endingZeroes(ListNode *sNode, int diff)
{
    if (sNode == NULL)
    {
        return NULL;
    }

    ListNode *newHead = new ListNode(0);
    diff--;
    ListNode *dummy = newHead;

    // creating list og 0 of size diff.
    while (diff--)
    {
        dummy->next = new ListNode(0);
        dummy = dummy->next;
    }

    //Connecting dummy with sNode
    dummy->next = sNode;

    return newHead;
}

ListNode *subtractHelper(ListNode *lNode, ListNode *sNode, bool &borrow)
{
    if (lNode == NULL && sNode == NULL && borrow == false)
    {
        return NULL;
    }

    ListNode *previous = subtractHelper(lNode->next, sNode->next, borrow);

    int d1 = lNode->val;
    int d2 = lNode->val;

    if (borrow)
    {
        d1 -= 1;
        borrow = false;
    }

    if (d1 < d2)
    {
        d1 += 10;
        borrow = true;
    }

    int sub = d1 - d2;

    ListNode *current = new ListNode(sub);
    current->next = previous;

    return current;
}

ListNode *subtractTwoNumber(ListNode *l1, ListNode *l2)
{
    int len1 = lenght(l1);
    int len2 = lenght(l2);

    ListNode *lNode = NULL;
    ListNode *rNode = NULL;

    ListNode *temp1 = l1;
    ListNode *temp2 = l2;

    //Diffrent lenght case handling
    if (len1 != len2)
    {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;

        //Make both of same lenght by adding traling zeroes to smaller length list.
        sNode = endingZeroes(sNode, abs(len1 - len2));
    }

    else
    {
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val != l2->val)
            {
                lNode = l1->val > l2->val ? l1 : l2;
                sNode = l1->val > l2->val ? l2 : l1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    //if still lNode and sNode is NULL
    //then both nums are same
    if (lNode == NULL && sNode == NULL)
    {
        return new ListNode(0);
    }

    bool borrow = false;

    return subtractHelper(lNode, sNode, borrow);
}