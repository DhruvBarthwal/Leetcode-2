class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            int num = heights[i];
            if(!s.empty()){
                if(heights[s.top()] > num){
                    ans[s.top()]++;
                }
                else{
                    while(!s.empty() && heights[s.top()] <= num){
                        ans[s.top()]++;
                        s.pop();
                    }
                    if(!s.empty()) ans[s.top()]++;
                }
            }
            s.push(i);
        }
        return ans;
    }
};