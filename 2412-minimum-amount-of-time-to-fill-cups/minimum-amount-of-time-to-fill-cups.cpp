class Solution {
public:
    int fillCups(vector<int>& amount) {
        // int count = 0;
        // priority_queue<int> pq;
        // for(int num : amount) pq.push(num);
        // while(pq.top() != 0){
        //     int a = pq.top();
        //     pq.pop();
        //     int b = pq.top();
        //     pq.pop();
        //     a--;
        //     b--;
        //     pq.push(a);
        //     pq.push(b);
        //     count++;
        // }
        // return count;
        int mx = *max_element(amount.begin(),amount.end());
        int sum = accumulate(amount.begin(),amount.end(), 0LL);
        return max(mx, (sum+1)/2);
    }
};