 

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 // reccursive 
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     if(list1 == NULL){
         return list2;
     }
     if(list2 == NULL){
         return list1;
     }

     // Both the list have nodes and now we need to merge them

    ListNode* temp = NULL;

    if(list1->val <= list2->val) {
        temp = list1;
        temp = mergeTwoLists(list1->next, list2);
    }
    else {
        temp = list2;
        temo = mergeTwoLists(list1, list2->next);
    }

    return temp;
 }

 //iterative - 3 pointer's approach
 ListNode* mergeTwoLists(ListNode* list1 , ListNode *list2) {
     if(list1 == NULL) {
         return list2;
     }
     if(list2 == NULL) {
         return list1;
     }
     ListNode* ptr1 = list1;
     ListNode* ptr2 = list2;

     ListNode* dummy = new ListNode(0);
     ListNode* temp = dummy;

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->val < ptr2->val) {
            temp->next = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            temp->next = ptr2;
            ptr2 = ptr2->next;
        }

        temp = temp->next;
    }

    while(ptr1 != NULL) {
        temp->next = ptr1;
        temp = temp->next;
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL) {
        temp->next = ptr2;
        temp = temp->next;
        ptr2 = ptr2->next;
    }

    return dummy->next;
 }
