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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //initialization
        vector<int> indices;
        ListNode* temp = head;
        int prev = -1;
        int i = 0;

        //base case
        if(!temp || !temp->next || !temp->next->next) return {-1,-1};

        //traverse the list
        while(temp && temp->next){
            int curr = temp->val;
            int next = temp->next->val;
            if(prev != -1 && temp->next){
                if((prev > curr && curr < next) || (prev < curr && curr > next)) indices.push_back(i);
            }
            prev = curr;
            temp = temp-> next;
            i++;
        }

        //calc max and min distance
        if(indices.size() < 2) return {-1,-1};

        int maxi = indices[indices.size() - 1] - indices[0];
        int mini = INT_MAX;

        for(int j = 1;j<indices.size();j++){
            mini = min(mini, indices[j] - indices[j-1]);
        }

        //return values
        return {mini,maxi};
    }
};