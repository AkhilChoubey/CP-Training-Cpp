#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if(list1 == NULL) {
        return list2;
    }
    if(list2 == NULL) {
        return list1;
    }

    //We knw that both are not null

    ListNode* temp = NULL;

    if(list1->val <= list2->val) {
        temp = list1;
        temp = mergeTwoLists(list1->next, list2);
    }
    else {
        temp = list2;
        temp = mergeTwoLists(list1, list2->next);
    }

    return temp;

}

ListNode* mergeKSortedList(vector<ListNode*>& lists){
    if(lists.size() == 0) {
        return NULL;
    }
    else if(lists.size() == 1) {
        return lists[0];
    }

    //There are more than 1 list , we need to merge them 
    int last = lists.size() - 1;
    while(last != 0) {
        int i = 0, j = last;
        
        lists[i] = mergeTwoLists(lists[i], lists[j]);
        i++;
        j--;
        if(i >= j) {
        last = j;
        }
    }

    return lists[0];
}