/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //pencegahan null pointer
        if(head == NULL){return false;}

        map<ListNode*,bool> recents;
        ListNode *pointer = head;
        while(pointer->next != NULL){
            
            if(recents.count(pointer->next)){
                return true;
            }
            recents[pointer] = true;
            pointer = pointer->next;

        }
        return false;
    }
};