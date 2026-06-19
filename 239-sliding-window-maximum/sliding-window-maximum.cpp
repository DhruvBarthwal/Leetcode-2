class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //prerequisites
        int  n = nums.size();
        priority_queue<pair<int,int>>pq;
        vector<int> ans;
        vector<bool>vis(n,false);
        int maxi = 0;
        //first window
        for(int i =0;i<k;i++){
            maxi = max(nums[i],maxi);
            pq.push({nums[i],i});
        }
        ans.push_back(maxi);
        int i =0;
        //traversing rest of the array
        for(int j = k;j<n;j++){
            int num = nums[j];
            pq.push({nums[j],j});
            vis[i] = true;
            while(vis[pq.top().second] && !pq.empty()){
                pq.pop();
            }
            i++;
            maxi = pq.top().first;
            ans.push_back(maxi);
        }
        return ans;
    }
};