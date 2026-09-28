class Solution {
public:
    int minDeletions(string s) {
        if(s.length() == 1) return 0;

        vector<int> freq(26,0);

        for(char &ch : s) freq[ch-'a']++;

        priority_queue<int> pq;

        for(auto &x : freq){
            if(x != 0){
                pq.push(x);
            }
        }

        int cnt = 0;

        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            while(!pq.empty() && top == pq.top() && top != 0){
                pq.push(pq.top() - 1);
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};