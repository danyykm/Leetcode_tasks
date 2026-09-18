struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode();
        ListNode* current_of_1 = list1;
        ListNode* current_of_2 = list2;
        ListNode* current_of_3 = newList;
        while(current_of_1 != nullptr or current_of_2 != nullptr){
            if(current_of_1 != nullptr and current_of_2 != nullptr){
                if(current_of_1->val <= current_of_2->val){
                    ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = current_of_3->next;
                    current_of_3->val = current_of_1->val;
                    current_of_1 = current_of_1->next;
                    continue;
                }
                else{
                    ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = current_of_3->next;
                    current_of_3->val = current_of_2->val;
                    current_of_2 = current_of_2->next;
                    continue;
                }
            }
            if(current_of_1 == nullptr and current_of_2 != nullptr){
                ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = current_of_3->next;
                    current_of_3->val = current_of_2->val;
                    current_of_2 = current_of_2->next;
                    continue;
            }
            if(current_of_1 != nullptr and current_of_2 == nullptr){
                ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = current_of_3->next;
                    current_of_3->val = current_of_1->val;
                    current_of_1 = current_of_1->next;
                    continue;
            }
        }
        return newList->next;
    }
};