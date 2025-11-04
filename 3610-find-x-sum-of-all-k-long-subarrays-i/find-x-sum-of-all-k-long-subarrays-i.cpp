class Solution {
public:
struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
};
void countSum(int &sum,priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq, int x){
    while(!pq.empty() && x>0){
        auto[a,b] = pq.top();
        pq.pop();
        sum += (a*b);
        x--;
    }
}
void addPair(int a, int b,priority_queue<pair<int,int>, vector<pair<int,int>>,cmp>&pq){
    //base case
    if(pq.empty()){
        pq.push({a,b});
        return;
    }
    if(pq.top().first == a){
        pq.pop();
        if(b != 0) pq.push({a,b});
        return;
    }
    auto [val,cnt] = pq.top();
    pq.pop();
    addPair(a,b,pq);
    pq.push({val,cnt}); 
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> ans;
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
        //create window
        for(int i = 0;i<k;i++){
            int val = nums[i];
            freq[val]++;
        }
        for(auto [val,cnt] : freq){
            pq.push({val,cnt});
        }
        countSum(sum,pq,x);
        ans.push_back(sum);
        sum = 0;
        for(int i = k;i<n;i++){
            freq[nums[i]]++;
            addPair(nums[i],freq[nums[i]],pq);
            freq[nums[i-k]]--;
            addPair(nums[i-k],freq[nums[i-k]],pq);
            countSum(sum,pq,x);
            ans.push_back(sum);
            sum =0;
        }
        return ans;
    }
};