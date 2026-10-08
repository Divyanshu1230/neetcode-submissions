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
#define null NULL
#define Node ListNode
    ListNode* reverseKGroup(ListNode* head, int k) {
        Node* temp = head;
        int cnt = 0;
        // check if k nodes exist
        while(cnt < k){
            if(temp == null){
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // recursively call for rest LL
        Node* prevNode = reverseKGroup(temp,k);

        // reverse curr group
        temp=head; cnt=0;
        while(cnt<k){
            Node* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;
            cnt++;
        }
        return prevNode;
    }
};
