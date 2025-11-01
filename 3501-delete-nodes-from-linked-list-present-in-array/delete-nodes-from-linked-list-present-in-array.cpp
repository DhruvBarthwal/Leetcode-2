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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = 0;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            int value = curr->val;
            if(mp.find(value) != mp.end()){
                if(prev == NULL){
                    head = head->next;
                    curr->next = NULL;
                    curr = head;
                }
                else{
                    ListNode* temp = curr->next;
                    prev->next = temp;
                    curr = curr->next;
                    temp = NULL;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};