class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        //initialization
        int n = nums.size();
        int ans = 0;
        set<int> s;
        unordered_map<int,int> freq;
        //counting freq of +ve integer
        for(int &num : nums){
            num %= value;
            if(num>=0){
                freq[num]++;
            }
            else{
                freq[num+value]++;
            }
        }
        //inserting elements in set
        for(auto &[num , count]: freq){
            int i = 0;
            while(i<count){
                int v = num + value*i;
                s.insert(v);
                i++;
                cout<<v<<" ";
            }
        }
        int cnt = 0;
        for(auto & num : s){
            if(cnt != num){
                ans = cnt;
                break;
            }
            cnt++;
        }
        return (ans == 0)? cnt : ans;
    }
};