struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode();
        ListNode* current_of_1 = l1;
        ListNode* current_of_2 = l2;
        ListNode* current_of_3 = newList;
        bool additional_ten = false;
        bool first_time = true;
        while(current_of_1 != nullptr or current_of_2 != nullptr){
            int summ_of_nodes;
            if(current_of_1 != nullptr and current_of_2 != nullptr){
                if(first_time){
                    first_time = false;
                }
                else{
                    ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = newNode;
                }
                current_of_3->next = nullptr;
                if(additional_ten){
                    summ_of_nodes = current_of_1->val + current_of_2->val + 1;
                }
                else{
                    summ_of_nodes = current_of_1->val + current_of_2->val;
                }
                current_of_3->val = summ_of_nodes % 10;
                if(summ_of_nodes >= 10){
                    additional_ten = true;
                }
                else{
                    additional_ten = false;
                }
            }
            else if(current_of_1 != nullptr and current_of_2 == nullptr){
                if(first_time){
                    first_time = false;
                }
                else{
                    ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = newNode;
                }
                current_of_3->next = nullptr;
                if(additional_ten){
                    summ_of_nodes = current_of_1->val + 1;
                }
                else{
                    summ_of_nodes = current_of_1->val;
                }
                current_of_3->val = summ_of_nodes % 10;
                if(summ_of_nodes >= 10){
                    additional_ten = true;
                }
                else{
                    additional_ten = false;
                }
            }
            else if(current_of_1 == nullptr and current_of_2 != nullptr){
                if(first_time){
                    first_time = false;
                }
                else{
                    ListNode* newNode = new ListNode();
                    current_of_3->next = newNode;
                    current_of_3 = newNode;
                }
                if(additional_ten){
                    summ_of_nodes = current_of_2->val + 1;
                }
                else{
                    summ_of_nodes = current_of_2->val;
                }
                current_of_3->val = summ_of_nodes % 10;
                if(summ_of_nodes >= 10){
                    additional_ten = true;
                }
                else{
                    additional_ten = false;
                }
            }
            if(current_of_1 != nullptr and current_of_2 != nullptr){
                current_of_1 = current_of_1->next;
                current_of_2 = current_of_2->next;
                continue;
            }
            if(current_of_1 == nullptr and current_of_2 != nullptr){
                current_of_2 = current_of_2->next;
                continue;
            }
            if(current_of_1 != nullptr and current_of_2 == nullptr){
                current_of_1 = current_of_1->next;
                continue;
            }
        }
        if(current_of_1 == nullptr and current_of_2 == nullptr){
                if(additional_ten){
                    if(newList != nullptr){
                        ListNode* newNode = new ListNode();
                        current_of_3->next = newNode;
                        current_of_3 = newNode;
                    }
                    current_of_3->next = nullptr;
                    current_of_3->val = 1;
                }
            }
        return newList;
    }
};