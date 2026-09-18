#include <vector>
#include <climits>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {

        std::priority_queue<std::pair<int, ListNode*>, std::vector<std::pair<int, ListNode*>>, std::greater<>> pq;
        for(auto list : lists){
            if(list != nullptr){
                pq.push({list->val, list});
            }
        }

        ListNode* newList = new ListNode();
        
        ListNode* current_of_new = newList;
        
        while(!pq.empty()){

            ListNode* newNode = new ListNode(pq.top().first);

            current_of_new->next = pq.top().second;
            
            current_of_new = current_of_new->next; 

            ListNode* NodeToAdd = pq.top().second;

            if(NodeToAdd->next != nullptr){
                pq.push({NodeToAdd->next->val, NodeToAdd->next});
            }

            current_of_new->next = nullptr;

            pq.pop();
        }
        return newList->next;
    }
};