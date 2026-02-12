class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            int val = 0;
            int temp = nums[i];
            while(temp > 0){
                val = (val << 1) | (temp & 1);
                temp >>= 1;
            }
            pq.push({val,nums[i]});
        }
        while(!pq.empty()){
            auto [x,y] = pq.top();
            pq.pop();
            ans.push_back(y);
        }
        return ans;
    }
};