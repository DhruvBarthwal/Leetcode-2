class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<>> pq;
        int total = 0;

        for(int &x : nums) pq.push(x);

        while(k > 0 && !pq.empty()){
            int x = pq.top();
            pq.pop();
            if(x >= 0){
                if(k & 1) pq.push(-x);
                else pq.push(x);
                k = 0;
            }
            else {
                k--;
                pq.push(-x);
            }
        }

        while(!pq.empty()){
            total += pq.top();
            pq.pop();
        }
        
        return total;
    }
};