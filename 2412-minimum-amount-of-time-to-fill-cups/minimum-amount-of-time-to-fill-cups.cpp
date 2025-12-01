class Solution {
public:
    int fillCups(vector<int>& amount) {
        int count = 0;
        priority_queue<int> pq;
        for(int num : amount) pq.push(num);
        while(pq.top() != 0){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            a--;
            b--;
            pq.push(a);
            pq.push(b);
            count++;
        }
        return count;
    }
};