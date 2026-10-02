class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        double temp = sum / 2;
        priority_queue<double> pq;
        for(auto &num : nums) pq.push(num);

        int cnt = 0;

        while(!pq.empty()){
            if(sum <= temp) break;
            double x = pq.top();
            pq.pop();
            sum -= x;
            x /= 2;
            sum += x;
            cnt++;
            pq.push(x);
        }
        return cnt;
    }
};