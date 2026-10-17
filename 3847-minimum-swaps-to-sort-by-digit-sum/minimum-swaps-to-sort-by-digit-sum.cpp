class Solution {
public:

//4 3 2 5 1 
//3 4 1 2
//2 1 4 3
//1 3 2 4
//1 2 3 4
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int,int,int>> v;
        for(int i =0;i<n;i++){
            int sum = 0;
            int temp = nums[i];
            while(temp > 0){
                sum += temp % 10;
                temp /= 10;
            }
            cout<< sum<<" ";
            v.push_back({sum,nums[i],i});
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        vector<bool> vis(n,false);
        for(int i = 0;i<n;i++){
            if(vis[i] || i == get<2>(v[i])) continue;
            int cycle = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = get<2>(v[j]);
                cycle++;
            }
            if(cycle > 1) cnt += cycle - 1;
        }
        return cnt;
    }
};