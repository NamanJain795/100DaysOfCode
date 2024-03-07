/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void removeHead(ListNode* &head, int &size, int &ln){
        head = head -> next;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        if(head -> next == NULL && n == 1){
            head = NULL;
            return head;
        }
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp -> next;
        }
        int ln = size - n;
        if(ln == 0){
            removeHead(head, size, ln);
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 0;
        while(count < ln){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        if(curr -> next == NULL){
            prev -> next = NULL;
        }
        else{
            prev -> next = curr -> next;
            curr -> next = NULL;
        }
        return head;
    }
};